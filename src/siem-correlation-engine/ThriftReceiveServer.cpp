// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "SIEMThrift.h"
#include "ThriftReceiveServer.h"
#include "SIEMUtil.hpp"
#include "SIEMMessage_types.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>

#include <Poco/Logger.h>
#include <Poco/Util/LayeredConfiguration.h>
#include <Poco/Util/Application.h>

#include <pthread.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace  ::SIEM::thrift;

namespace SIEM
{

bool CThriftReceiveServer::Recv(const std::string& strEvent)
{
    Poco::Logger & logger = Poco::Util::Application::instance().logger();

    if(strEvent.empty()) return false;

    int nJudge = 0;

JUDGE_WRITE:

    if(m_CachePtr->nWrite - m_CachePtr->nRead < m_nCacheNum)
    {
        m_CachePtr->Cache[m_CachePtr->nWrite % m_nCacheNum].assign(strEvent);
        m_CachePtr->nWrite ++;
    }
    else if(nJudge < 4)//judge 4 times
    {
        logger.debug("buffer is full");
        sleep(2);
        nJudge ++;
        goto JUDGE_WRITE;
    }
    else
    {
        logger.error("buffer always full, return false");
        return false;
    }
    return true;
}

bool CThriftReceiveServer::Handle(const SIEMThriftEvent& tEvent)
{
    shared_ptr<SIEMEvent> se(new SIEMEvent());
    if(!m_ptrSIEMBuild->ThriftEventBuild(*(se.get()), tEvent))
    {

    }
    return true;
}

bool CThriftReceiveServer::Start()
{
    if(pthread_create(&m_pthServerID, NULL, ThreadThrift, this))
    {
        return false;
    }

    if(pthread_create(&m_pthHandleID, NULL, ThreadHandle, this))
    {
        return false;
    }
    return true;
}

void* CThriftReceiveServer::ThreadThrift(void *p)
{
    Poco::Logger & logger = Poco::Util::Application::instance().logger();
    logger.debug("Begin Thrift receive thread");

    if(p == NULL)
    {
        logger.error("Input is NULL");
        exit(1);
    }

    CThriftReceiveServer *pTs = (CThriftReceiveServer *)p;

    //start Thrift server
    shared_ptr<CThriftReceiveServer> handler(new CThriftReceiveServer());
    shared_ptr<TProcessor> processor(new SIEMThriftProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(pTs->m_nThreadNum);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TNonblockingServer server(processor, protocolFactory, pTs->m_nPort, threadManager);
    server.serve();

	return (void *)0;
}

void * CThriftReceiveServer::ThreadHandle(void *p)
{
    Poco::Logger & logger = Poco::Util::Application::instance().logger();
    logger.debug("Begin Thrift receive thread");

    if(p == NULL)
    {
        logger.error("Input is NULL");
        exit(1);
    }

    CThriftReceiveServer *pServer = (CThriftReceiveServer *) p;

#ifndef CACHE_PTR
#define CACHE_PTR (pServer->m_CachePtr)

    while(true)
    {
        if(CACHE_PTR->nWrite == 0)
        {
            logger.debug("Thrift no receive data");
            sleep(2);
        }
        else if(CACHE_PTR->nRead >= CACHE_PTR->nWrite)
        {
            logger.debug("Read >= Write");
            sleep(1);
        }
        else
        {
            SIEMThriftEvent e;
            SIEM::Util::StringToThrift(CACHE_PTR->Cache[CACHE_PTR->nRead % pServer->m_nCacheNum], &e);
            CACHE_PTR->nRead ++;
            pServer->Handle(e);
        }
    }

#undef CACHE_PTR
#endif

    return (void *)0;
}

bool CThriftReceiveServer::Initialize()
{
    //Read zmq config items from config file.
    Poco::Util::LayeredConfiguration & config = Poco::Util::Application::instance().config();
    Poco::Logger & logger = Poco::Util::Application::instance().logger();

    logger.debug("Read thrift config from config file");

    m_strBind    = config.getString("siemevent.thrift.bind", "siemevent.thrift.bind");
    m_nThreadNum = config.getInt   ("siemevent.thrift.thread.num", 10);
    m_nPort      = config.getInt   ("siemevent.thrift.port", 9999);
    m_nCacheNum  = config.getInt   ("siemevent.thrift.cache.num", 2048);

    m_CachePtr->Cache.resize(m_nCacheNum);

    logger.debug(Poco::format("Thrift bind address is %s, thread number is %hu port is %hu cache number is %u",\
			m_strBind, m_nThreadNum, m_nPort, m_nCacheNum));

	return true;
}

CThriftReceiveServer::CThriftReceiveServer()
:m_strBind("127.0.0.1"),
 m_nPort(9999),
 m_nThreadNum(10),
 m_nCacheNum(2048),
 m_CachePtr(new stCacheItem<std::string>()),
 m_pthHandleID(0)
{
}

CThriftReceiveServer::~CThriftReceiveServer()
{
}

}
