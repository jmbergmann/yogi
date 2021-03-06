# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: yogi_000009cd.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='yogi_000009cd.proto',
  package='yogi_000009cd',
  syntax='proto3',
  serialized_pb=_b('\n\x13yogi_000009cd.proto\x12\ryogi_000009cd\"\x10\n\x0eScatterMessage\"{\n\rGatherMessage\x12\x11\n\ttimestamp\x18\x01 \x01(\x04\x12\x30\n\x05value\x18\x02 \x01(\x0b\x32!.yogi_000009cd.GatherMessage.Pair\x1a%\n\x04Pair\x12\r\n\x05\x66irst\x18\x01 \x01(\t\x12\x0e\n\x06second\x18\x02 \x01(\t\"}\n\x0ePublishMessage\x12\x11\n\ttimestamp\x18\x01 \x01(\x04\x12\x31\n\x05value\x18\x02 \x01(\x0b\x32\".yogi_000009cd.PublishMessage.Pair\x1a%\n\x04Pair\x12\r\n\x05\x66irst\x18\x01 \x01(\t\x12\x0e\n\x06second\x18\x02 \x01(\t\"\x0f\n\rMasterMessage\"y\n\x0cSlaveMessage\x12\x11\n\ttimestamp\x18\x01 \x01(\x04\x12/\n\x05value\x18\x02 \x01(\x0b\x32 .yogi_000009cd.SlaveMessage.Pair\x1a%\n\x04Pair\x12\r\n\x05\x66irst\x18\x01 \x01(\t\x12\x0e\n\x06second\x18\x02 \x01(\tB\x02H\x03\x62\x06proto3')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_SCATTERMESSAGE = _descriptor.Descriptor(
  name='ScatterMessage',
  full_name='yogi_000009cd.ScatterMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=38,
  serialized_end=54,
)


_GATHERMESSAGE_PAIR = _descriptor.Descriptor(
  name='Pair',
  full_name='yogi_000009cd.GatherMessage.Pair',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='first', full_name='yogi_000009cd.GatherMessage.Pair.first', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='second', full_name='yogi_000009cd.GatherMessage.Pair.second', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=142,
  serialized_end=179,
)

_GATHERMESSAGE = _descriptor.Descriptor(
  name='GatherMessage',
  full_name='yogi_000009cd.GatherMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='timestamp', full_name='yogi_000009cd.GatherMessage.timestamp', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='value', full_name='yogi_000009cd.GatherMessage.value', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[_GATHERMESSAGE_PAIR, ],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=56,
  serialized_end=179,
)


_PUBLISHMESSAGE_PAIR = _descriptor.Descriptor(
  name='Pair',
  full_name='yogi_000009cd.PublishMessage.Pair',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='first', full_name='yogi_000009cd.PublishMessage.Pair.first', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='second', full_name='yogi_000009cd.PublishMessage.Pair.second', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=142,
  serialized_end=179,
)

_PUBLISHMESSAGE = _descriptor.Descriptor(
  name='PublishMessage',
  full_name='yogi_000009cd.PublishMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='timestamp', full_name='yogi_000009cd.PublishMessage.timestamp', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='value', full_name='yogi_000009cd.PublishMessage.value', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[_PUBLISHMESSAGE_PAIR, ],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=181,
  serialized_end=306,
)


_MASTERMESSAGE = _descriptor.Descriptor(
  name='MasterMessage',
  full_name='yogi_000009cd.MasterMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=308,
  serialized_end=323,
)


_SLAVEMESSAGE_PAIR = _descriptor.Descriptor(
  name='Pair',
  full_name='yogi_000009cd.SlaveMessage.Pair',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='first', full_name='yogi_000009cd.SlaveMessage.Pair.first', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='second', full_name='yogi_000009cd.SlaveMessage.Pair.second', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=142,
  serialized_end=179,
)

_SLAVEMESSAGE = _descriptor.Descriptor(
  name='SlaveMessage',
  full_name='yogi_000009cd.SlaveMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='timestamp', full_name='yogi_000009cd.SlaveMessage.timestamp', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='value', full_name='yogi_000009cd.SlaveMessage.value', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[_SLAVEMESSAGE_PAIR, ],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=325,
  serialized_end=446,
)

_GATHERMESSAGE_PAIR.containing_type = _GATHERMESSAGE
_GATHERMESSAGE.fields_by_name['value'].message_type = _GATHERMESSAGE_PAIR
_PUBLISHMESSAGE_PAIR.containing_type = _PUBLISHMESSAGE
_PUBLISHMESSAGE.fields_by_name['value'].message_type = _PUBLISHMESSAGE_PAIR
_SLAVEMESSAGE_PAIR.containing_type = _SLAVEMESSAGE
_SLAVEMESSAGE.fields_by_name['value'].message_type = _SLAVEMESSAGE_PAIR
DESCRIPTOR.message_types_by_name['ScatterMessage'] = _SCATTERMESSAGE
DESCRIPTOR.message_types_by_name['GatherMessage'] = _GATHERMESSAGE
DESCRIPTOR.message_types_by_name['PublishMessage'] = _PUBLISHMESSAGE
DESCRIPTOR.message_types_by_name['MasterMessage'] = _MASTERMESSAGE
DESCRIPTOR.message_types_by_name['SlaveMessage'] = _SLAVEMESSAGE

ScatterMessage = _reflection.GeneratedProtocolMessageType('ScatterMessage', (_message.Message,), dict(
  DESCRIPTOR = _SCATTERMESSAGE,
  __module__ = 'yogi_000009cd_pb2'
  # @@protoc_insertion_point(class_scope:yogi_000009cd.ScatterMessage)
  ))
_sym_db.RegisterMessage(ScatterMessage)

GatherMessage = _reflection.GeneratedProtocolMessageType('GatherMessage', (_message.Message,), dict(

  Pair = _reflection.GeneratedProtocolMessageType('Pair', (_message.Message,), dict(
    DESCRIPTOR = _GATHERMESSAGE_PAIR,
    __module__ = 'yogi_000009cd_pb2'
    # @@protoc_insertion_point(class_scope:yogi_000009cd.GatherMessage.Pair)
    ))
  ,
  DESCRIPTOR = _GATHERMESSAGE,
  __module__ = 'yogi_000009cd_pb2'
  # @@protoc_insertion_point(class_scope:yogi_000009cd.GatherMessage)
  ))
_sym_db.RegisterMessage(GatherMessage)
_sym_db.RegisterMessage(GatherMessage.Pair)

PublishMessage = _reflection.GeneratedProtocolMessageType('PublishMessage', (_message.Message,), dict(

  Pair = _reflection.GeneratedProtocolMessageType('Pair', (_message.Message,), dict(
    DESCRIPTOR = _PUBLISHMESSAGE_PAIR,
    __module__ = 'yogi_000009cd_pb2'
    # @@protoc_insertion_point(class_scope:yogi_000009cd.PublishMessage.Pair)
    ))
  ,
  DESCRIPTOR = _PUBLISHMESSAGE,
  __module__ = 'yogi_000009cd_pb2'
  # @@protoc_insertion_point(class_scope:yogi_000009cd.PublishMessage)
  ))
_sym_db.RegisterMessage(PublishMessage)
_sym_db.RegisterMessage(PublishMessage.Pair)

MasterMessage = _reflection.GeneratedProtocolMessageType('MasterMessage', (_message.Message,), dict(
  DESCRIPTOR = _MASTERMESSAGE,
  __module__ = 'yogi_000009cd_pb2'
  # @@protoc_insertion_point(class_scope:yogi_000009cd.MasterMessage)
  ))
_sym_db.RegisterMessage(MasterMessage)

SlaveMessage = _reflection.GeneratedProtocolMessageType('SlaveMessage', (_message.Message,), dict(

  Pair = _reflection.GeneratedProtocolMessageType('Pair', (_message.Message,), dict(
    DESCRIPTOR = _SLAVEMESSAGE_PAIR,
    __module__ = 'yogi_000009cd_pb2'
    # @@protoc_insertion_point(class_scope:yogi_000009cd.SlaveMessage.Pair)
    ))
  ,
  DESCRIPTOR = _SLAVEMESSAGE,
  __module__ = 'yogi_000009cd_pb2'
  # @@protoc_insertion_point(class_scope:yogi_000009cd.SlaveMessage)
  ))
_sym_db.RegisterMessage(SlaveMessage)
_sym_db.RegisterMessage(SlaveMessage.Pair)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('H\003'))
# @@protoc_insertion_point(module_scope)
ScatterMessage.SIGNATURE = 0x000009cd
GatherMessage.SIGNATURE = 0x000009cd
PublishMessage.SIGNATURE = 0x000009cd
MasterMessage.SIGNATURE = 0x000009cd
SlaveMessage.SIGNATURE = 0x000009cd
