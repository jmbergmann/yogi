# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: yogi_0000040d.proto

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
  name='yogi_0000040d.proto',
  package='yogi_0000040d',
  syntax='proto3',
  serialized_pb=_b('\n\x13yogi_0000040d.proto\x12\ryogi_0000040d\"\x10\n\x0eScatterMessage\"\x1e\n\rGatherMessage\x12\r\n\x05value\x18\x02 \x03(\t\"\x1f\n\x0ePublishMessage\x12\r\n\x05value\x18\x02 \x03(\t\"\x0f\n\rMasterMessage\"\x1d\n\x0cSlaveMessage\x12\r\n\x05value\x18\x02 \x03(\tB\x02H\x03\x62\x06proto3')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_SCATTERMESSAGE = _descriptor.Descriptor(
  name='ScatterMessage',
  full_name='yogi_0000040d.ScatterMessage',
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


_GATHERMESSAGE = _descriptor.Descriptor(
  name='GatherMessage',
  full_name='yogi_0000040d.GatherMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='value', full_name='yogi_0000040d.GatherMessage.value', index=0,
      number=2, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=56,
  serialized_end=86,
)


_PUBLISHMESSAGE = _descriptor.Descriptor(
  name='PublishMessage',
  full_name='yogi_0000040d.PublishMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='value', full_name='yogi_0000040d.PublishMessage.value', index=0,
      number=2, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=88,
  serialized_end=119,
)


_MASTERMESSAGE = _descriptor.Descriptor(
  name='MasterMessage',
  full_name='yogi_0000040d.MasterMessage',
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
  serialized_start=121,
  serialized_end=136,
)


_SLAVEMESSAGE = _descriptor.Descriptor(
  name='SlaveMessage',
  full_name='yogi_0000040d.SlaveMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='value', full_name='yogi_0000040d.SlaveMessage.value', index=0,
      number=2, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=138,
  serialized_end=167,
)

DESCRIPTOR.message_types_by_name['ScatterMessage'] = _SCATTERMESSAGE
DESCRIPTOR.message_types_by_name['GatherMessage'] = _GATHERMESSAGE
DESCRIPTOR.message_types_by_name['PublishMessage'] = _PUBLISHMESSAGE
DESCRIPTOR.message_types_by_name['MasterMessage'] = _MASTERMESSAGE
DESCRIPTOR.message_types_by_name['SlaveMessage'] = _SLAVEMESSAGE

ScatterMessage = _reflection.GeneratedProtocolMessageType('ScatterMessage', (_message.Message,), dict(
  DESCRIPTOR = _SCATTERMESSAGE,
  __module__ = 'yogi_0000040d_pb2'
  # @@protoc_insertion_point(class_scope:yogi_0000040d.ScatterMessage)
  ))
_sym_db.RegisterMessage(ScatterMessage)

GatherMessage = _reflection.GeneratedProtocolMessageType('GatherMessage', (_message.Message,), dict(
  DESCRIPTOR = _GATHERMESSAGE,
  __module__ = 'yogi_0000040d_pb2'
  # @@protoc_insertion_point(class_scope:yogi_0000040d.GatherMessage)
  ))
_sym_db.RegisterMessage(GatherMessage)

PublishMessage = _reflection.GeneratedProtocolMessageType('PublishMessage', (_message.Message,), dict(
  DESCRIPTOR = _PUBLISHMESSAGE,
  __module__ = 'yogi_0000040d_pb2'
  # @@protoc_insertion_point(class_scope:yogi_0000040d.PublishMessage)
  ))
_sym_db.RegisterMessage(PublishMessage)

MasterMessage = _reflection.GeneratedProtocolMessageType('MasterMessage', (_message.Message,), dict(
  DESCRIPTOR = _MASTERMESSAGE,
  __module__ = 'yogi_0000040d_pb2'
  # @@protoc_insertion_point(class_scope:yogi_0000040d.MasterMessage)
  ))
_sym_db.RegisterMessage(MasterMessage)

SlaveMessage = _reflection.GeneratedProtocolMessageType('SlaveMessage', (_message.Message,), dict(
  DESCRIPTOR = _SLAVEMESSAGE,
  __module__ = 'yogi_0000040d_pb2'
  # @@protoc_insertion_point(class_scope:yogi_0000040d.SlaveMessage)
  ))
_sym_db.RegisterMessage(SlaveMessage)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('H\003'))
# @@protoc_insertion_point(module_scope)
ScatterMessage.SIGNATURE = 0x0000040d
GatherMessage.SIGNATURE = 0x0000040d
PublishMessage.SIGNATURE = 0x0000040d
MasterMessage.SIGNATURE = 0x0000040d
SlaveMessage.SIGNATURE = 0x0000040d
