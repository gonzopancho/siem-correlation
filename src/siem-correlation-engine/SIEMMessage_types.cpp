/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "SIEMMessage_types.h"

#include <algorithm>

namespace SIEM { namespace thrift {

int _kSIEMProtocolTypeValues[] = {
  SIEMProtocolType::SIEM_PROTOCOL_NONE,
  SIEMProtocolType::SIEM_PROTOCOL_ICMP,
  SIEMProtocolType::SIEM_PROTOCOL_TCP,
  SIEMProtocolType::SIEM_PROTOCOL_UDP,
  SIEMProtocolType::SIEM_PROTOCOL_ARP_EVENT,
  SIEMProtocolType::SIEM_PROTOCOL_OS_EVENT,
  SIEMProtocolType::SIEM_PROTOCOL_SERVER_EVENT
};
const char* _kSIEMProtocolTypeNames[] = {
  "SIEM_PROTOCOL_NONE",
  "SIEM_PROTOCOL_ICMP",
  "SIEM_PROTOCOL_TCP",
  "SIEM_PROTOCOL_UDP",
  "SIEM_PROTOCOL_ARP_EVENT",
  "SIEM_PROTOCOL_OS_EVENT",
  "SIEM_PROTOCOL_SERVER_EVENT"
};
const std::map<int, const char*> _SIEMProtocolType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kSIEMProtocolTypeValues, _kSIEMProtocolTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kSIEMEventTypeValues[] = {
  SIEMEventType::SIEM_EVENT_NONE,
  SIEMEventType::SIEM_EVENT_DETECTOR,
  SIEMEventType::SIEM_EVENT_MONITOR,
  SIEMEventType::SIEM_EVENT_BACKLOG
};
const char* _kSIEMEventTypeNames[] = {
  "SIEM_EVENT_NONE",
  "SIEM_EVENT_DETECTOR",
  "SIEM_EVENT_MONITOR",
  "SIEM_EVENT_BACKLOG"
};
const std::map<int, const char*> _SIEMEventType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kSIEMEventTypeValues, _kSIEMEventTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* SIEMThriftEvent::ascii_fingerprint = "EA6327FB260945CF748A34BA399647F3";
const uint8_t SIEMThriftEvent::binary_fingerprint[16] = {0xEA,0x63,0x27,0xFB,0x26,0x09,0x45,0xCF,0x74,0x8A,0x34,0xBA,0x39,0x96,0x47,0xF3};

uint32_t SIEMThriftEvent::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_plugin_id_int32 = false;
  bool isset_plugin_sid_int32 = false;
  bool isset_data_int32 = false;
  bool isset_fdata_int32 = false;
  bool isset_event_type_enum = false;
  bool isset_src_ipv4_int32 = false;
  bool isset_dst_ipv4_int32 = false;
  bool isset_device_ipv4_int32 = false;
  bool isset_interface_str = false;
  bool isset_log_str = false;
  bool isset_event_id_str = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->plugin_id_int32);
          isset_plugin_id_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->plugin_sid_int32);
          isset_plugin_sid_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->data_int32);
          isset_data_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->fdata_int32);
          isset_fdata_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->event_type_enum = (SIEMEventType::type)ecast0;
          isset_event_type_enum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->src_ipv4_int32);
          isset_src_ipv4_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->dst_ipv4_int32);
          isset_dst_ipv4_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->device_ipv4_int32);
          isset_device_ipv4_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->interface_str);
          isset_interface_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->log_str);
          isset_log_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->event_id_str);
          isset_event_id_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast1;
          xfer += iprot->readI32(ecast1);
          this->protocol_type_enum = (SIEMProtocolType::type)ecast1;
          this->__isset.protocol_type_enum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->src_port_int32);
          this->__isset.src_port_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->dst_port_int32);
          this->__isset.dst_port_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->snort_sid_int32);
          this->__isset.snort_sid_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 16:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->snort_cid_int32);
          this->__isset.snort_cid_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 17:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->priority_int32);
          this->__isset.priority_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 18:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->occurrences_int32);
          this->__isset.occurrences_int32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 19:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ctx_str);
          this->__isset.ctx_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 20:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->username_str);
          this->__isset.username_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 21:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->password_str);
          this->__isset.password_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 22:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filename_str);
          this->__isset.filename_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 23:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata1_str);
          this->__isset.userdata1_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 24:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata2_str);
          this->__isset.userdata2_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 25:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata3_str);
          this->__isset.userdata3_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 26:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata4_str);
          this->__isset.userdata4_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 27:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata5_str);
          this->__isset.userdata5_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 28:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata6_str);
          this->__isset.userdata6_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 29:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata7_str);
          this->__isset.userdata7_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 30:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata8_str);
          this->__isset.userdata8_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 31:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userdata9_str);
          this->__isset.userdata9_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 32:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sensor_id_str);
          this->__isset.sensor_id_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 33:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->binary_data_str);
          this->__isset.binary_data_str = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_plugin_id_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_plugin_sid_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_data_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_fdata_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_event_type_enum)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_src_ipv4_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_dst_ipv4_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_device_ipv4_int32)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_interface_str)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_log_str)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_event_id_str)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t SIEMThriftEvent::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SIEMThriftEvent");

  xfer += oprot->writeFieldBegin("plugin_id_int32", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->plugin_id_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("plugin_sid_int32", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->plugin_sid_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data_int32", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->data_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fdata_int32", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->fdata_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("event_type_enum", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32((int32_t)this->event_type_enum);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("src_ipv4_int32", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->src_ipv4_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dst_ipv4_int32", ::apache::thrift::protocol::T_I32, 7);
  xfer += oprot->writeI32(this->dst_ipv4_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("device_ipv4_int32", ::apache::thrift::protocol::T_I32, 8);
  xfer += oprot->writeI32(this->device_ipv4_int32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("interface_str", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeString(this->interface_str);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("log_str", ::apache::thrift::protocol::T_STRING, 10);
  xfer += oprot->writeString(this->log_str);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("event_id_str", ::apache::thrift::protocol::T_STRING, 11);
  xfer += oprot->writeString(this->event_id_str);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocol_type_enum", ::apache::thrift::protocol::T_I32, 12);
  xfer += oprot->writeI32((int32_t)this->protocol_type_enum);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.src_port_int32) {
    xfer += oprot->writeFieldBegin("src_port_int32", ::apache::thrift::protocol::T_I32, 13);
    xfer += oprot->writeI32(this->src_port_int32);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.dst_port_int32) {
    xfer += oprot->writeFieldBegin("dst_port_int32", ::apache::thrift::protocol::T_I32, 14);
    xfer += oprot->writeI32(this->dst_port_int32);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.snort_sid_int32) {
    xfer += oprot->writeFieldBegin("snort_sid_int32", ::apache::thrift::protocol::T_I32, 15);
    xfer += oprot->writeI32(this->snort_sid_int32);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.snort_cid_int32) {
    xfer += oprot->writeFieldBegin("snort_cid_int32", ::apache::thrift::protocol::T_I32, 16);
    xfer += oprot->writeI32(this->snort_cid_int32);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.priority_int32) {
    xfer += oprot->writeFieldBegin("priority_int32", ::apache::thrift::protocol::T_I32, 17);
    xfer += oprot->writeI32(this->priority_int32);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.occurrences_int32) {
    xfer += oprot->writeFieldBegin("occurrences_int32", ::apache::thrift::protocol::T_I32, 18);
    xfer += oprot->writeI32(this->occurrences_int32);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.ctx_str) {
    xfer += oprot->writeFieldBegin("ctx_str", ::apache::thrift::protocol::T_STRING, 19);
    xfer += oprot->writeString(this->ctx_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.username_str) {
    xfer += oprot->writeFieldBegin("username_str", ::apache::thrift::protocol::T_STRING, 20);
    xfer += oprot->writeString(this->username_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.password_str) {
    xfer += oprot->writeFieldBegin("password_str", ::apache::thrift::protocol::T_STRING, 21);
    xfer += oprot->writeString(this->password_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.filename_str) {
    xfer += oprot->writeFieldBegin("filename_str", ::apache::thrift::protocol::T_STRING, 22);
    xfer += oprot->writeString(this->filename_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata1_str) {
    xfer += oprot->writeFieldBegin("userdata1_str", ::apache::thrift::protocol::T_STRING, 23);
    xfer += oprot->writeString(this->userdata1_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata2_str) {
    xfer += oprot->writeFieldBegin("userdata2_str", ::apache::thrift::protocol::T_STRING, 24);
    xfer += oprot->writeString(this->userdata2_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata3_str) {
    xfer += oprot->writeFieldBegin("userdata3_str", ::apache::thrift::protocol::T_STRING, 25);
    xfer += oprot->writeString(this->userdata3_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata4_str) {
    xfer += oprot->writeFieldBegin("userdata4_str", ::apache::thrift::protocol::T_STRING, 26);
    xfer += oprot->writeString(this->userdata4_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata5_str) {
    xfer += oprot->writeFieldBegin("userdata5_str", ::apache::thrift::protocol::T_STRING, 27);
    xfer += oprot->writeString(this->userdata5_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata6_str) {
    xfer += oprot->writeFieldBegin("userdata6_str", ::apache::thrift::protocol::T_STRING, 28);
    xfer += oprot->writeString(this->userdata6_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata7_str) {
    xfer += oprot->writeFieldBegin("userdata7_str", ::apache::thrift::protocol::T_STRING, 29);
    xfer += oprot->writeString(this->userdata7_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata8_str) {
    xfer += oprot->writeFieldBegin("userdata8_str", ::apache::thrift::protocol::T_STRING, 30);
    xfer += oprot->writeString(this->userdata8_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userdata9_str) {
    xfer += oprot->writeFieldBegin("userdata9_str", ::apache::thrift::protocol::T_STRING, 31);
    xfer += oprot->writeString(this->userdata9_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sensor_id_str) {
    xfer += oprot->writeFieldBegin("sensor_id_str", ::apache::thrift::protocol::T_STRING, 32);
    xfer += oprot->writeString(this->sensor_id_str);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binary_data_str) {
    xfer += oprot->writeFieldBegin("binary_data_str", ::apache::thrift::protocol::T_STRING, 33);
    xfer += oprot->writeString(this->binary_data_str);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SIEMThriftEvent &a, SIEMThriftEvent &b) {
  using ::std::swap;
  swap(a.plugin_id_int32, b.plugin_id_int32);
  swap(a.plugin_sid_int32, b.plugin_sid_int32);
  swap(a.data_int32, b.data_int32);
  swap(a.fdata_int32, b.fdata_int32);
  swap(a.event_type_enum, b.event_type_enum);
  swap(a.src_ipv4_int32, b.src_ipv4_int32);
  swap(a.dst_ipv4_int32, b.dst_ipv4_int32);
  swap(a.device_ipv4_int32, b.device_ipv4_int32);
  swap(a.interface_str, b.interface_str);
  swap(a.log_str, b.log_str);
  swap(a.event_id_str, b.event_id_str);
  swap(a.protocol_type_enum, b.protocol_type_enum);
  swap(a.src_port_int32, b.src_port_int32);
  swap(a.dst_port_int32, b.dst_port_int32);
  swap(a.snort_sid_int32, b.snort_sid_int32);
  swap(a.snort_cid_int32, b.snort_cid_int32);
  swap(a.priority_int32, b.priority_int32);
  swap(a.occurrences_int32, b.occurrences_int32);
  swap(a.ctx_str, b.ctx_str);
  swap(a.username_str, b.username_str);
  swap(a.password_str, b.password_str);
  swap(a.filename_str, b.filename_str);
  swap(a.userdata1_str, b.userdata1_str);
  swap(a.userdata2_str, b.userdata2_str);
  swap(a.userdata3_str, b.userdata3_str);
  swap(a.userdata4_str, b.userdata4_str);
  swap(a.userdata5_str, b.userdata5_str);
  swap(a.userdata6_str, b.userdata6_str);
  swap(a.userdata7_str, b.userdata7_str);
  swap(a.userdata8_str, b.userdata8_str);
  swap(a.userdata9_str, b.userdata9_str);
  swap(a.sensor_id_str, b.sensor_id_str);
  swap(a.binary_data_str, b.binary_data_str);
  swap(a.__isset, b.__isset);
}

}} // namespace
