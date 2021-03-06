/**
 *   @file   ZMQReceiveServer.cpp
 *   @brief  brief
 *
 *   detail
 *
 *   @internal www.captech.net.cn
 *   author:    Zhang peng
 *   mail:      zhangpeng@captech.net.cn,Developer.Zhang.Peng@gmail.com
 *   Created:   Nov 17, 2014
 *   Revision:  1.0.0
 *   Compiler:  gcc/g++
 *   Company:   Captech Co., Ltd.
 *   Copyright: Copyright (c) 2008, Captech Co., Ltd.
 *
 * =====================================================================================
 */

#include "ZMQReceiveServer.h"
#include "SIEMMessage.pb.h"

#include <Poco/Util/LayeredConfiguration.h>
#include <Poco/Util/Application.h>
#include <Poco/Logger.h>

#include <zmq/zmq.hpp>

#include <stdint.h>
#include <pthread.h>

#include <iostream>

extern ::SIEM::SIEMEventVctPtr g_vctSIEMEventPtr;
extern pthread_mutex_t g_mutEvent;

namespace SIEM
{

void * CZMQReceiveServer::ThreadZMQ(void *p)
{
    Poco::Logger & logger = Poco::Util::Application::instance().logger();
    logger.debug("Begin zmq receive thread");
    if(p == NULL)
    {
        logger.error("Input is NULL", __FILE__, __LINE__);
        exit(1);
    }

    CZMQReceiveServer *pZmqServer = (CZMQReceiveServer *) p;

    try
    {
        int linger = 0;
        zmq::context_t context(1);
        zmq::socket_t  poller(context, ZMQ_PULL);

        poller.setsockopt(ZMQ_HWM, &(pZmqServer->m_nHwm), sizeof(uint64_t));
        poller.setsockopt(ZMQ_LINGER, &linger, sizeof(int));

        poller.bind(pZmqServer->m_strIPC.c_str());

        zmq::message_t message;
        zmq::pollitem_t item = {poller, 0, ZMQ_POLLIN, 0};

        while(true)
        {
            pthread_testcancel();

            zmq_poll(&item, 1, pZmqServer->m_nTimeout);
            if(item.revents & ZMQ_POLLIN)
            {
                logger.debug("Recive data");

                poller.recv(&message);
                pZmqServer->Handle((char *)message.data(), message.size());
            }
            else
            {
                logger.debug("ZMQ No recvive data");
            }
        }

        poller.close();
    }
    catch (zmq::error_t& e)
    {
        logger.error(e.what(), __FILE__, __LINE__);
    }
    catch(...)
    {
        logger.error("Unknown error", __FILE__, __LINE__);
    }
    return (void *)NULL;
}

bool CZMQReceiveServer::Handle(char * pszMsg, size_t size)
{
    Poco::Logger & logger = Poco::Util::Application::instance().logger();

    SIEMPbMessage msg;
    msg.ParseFromArray(pszMsg, size);

    SIEMEventPtr se(new SIEMEvent());
    if(m_ptrSIEMBuild->ZMQEventBuild(*(se.get()), msg))
    {
        pthread_mutex_lock(&g_mutEvent);
        g_vctSIEMEventPtr->push_back(se);
        pthread_mutex_unlock(&g_mutEvent);
    }
    else
    {
        se.reset();//reference count-- not necessary
        logger.error("Build SIEMEvent fault", __FILE__, __LINE__);
    }
    return true;
}

bool CZMQReceiveServer::Start()
{
    pthread_create(&m_pthServerID, NULL, ThreadZMQ, (void *)this);
    return true;
}

bool CZMQReceiveServer::Initialize()
{
    //Read zmq config items from config file.
    Poco::Util::LayeredConfiguration & config = Poco::Util::Application::instance().config();
    Poco::Logger & logger = Poco::Util::Application::instance().logger();

    logger.debug("Read zmq config from config file");

    m_nHwm     = config.getInt   ("siemevent.zmq.hwm", 100000);
    m_nTimeout = config.getInt   ("siemevent.zmq.timeout", 2000000);
    m_strIPC   = config.getString("siemevent.zmq.bind", "ipc:///tmp/siem-correlation");

    logger.debug(Poco::format("Hwm is %lu, timeout is %u ipc address is %s", m_nHwm, m_nTimeout, m_strIPC));
    return true;
}

CZMQReceiveServer::CZMQReceiveServer():
 m_nHwm(200000),
 m_strIPC("ipc:///tmp/siem-correlation"),
 m_nTimeout(2000000)
{
    // TODO Auto-generated constructor stub

}

CZMQReceiveServer::~CZMQReceiveServer()
{
    // TODO Auto-generated destructor stub
}

} /* namespace SIEM */
