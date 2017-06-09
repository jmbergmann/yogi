// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: yogi_00000000.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "yogi_00000000.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace yogi_00000000_ns {

namespace {

const ::google::protobuf::Descriptor* ScatterMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ScatterMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* GatherMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GatherMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* PublishMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PublishMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* MasterMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MasterMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* SlaveMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SlaveMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_yogi_5f00000000_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_yogi_5f00000000_2eproto() {
  protobuf_AddDesc_yogi_5f00000000_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "yogi_00000000.proto");
  GOOGLE_CHECK(file != NULL);
  ScatterMessage_descriptor_ = file->message_type(0);
  static const int ScatterMessage_offsets_[1] = {
  };
  ScatterMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ScatterMessage_descriptor_,
      ScatterMessage::default_instance_,
      ScatterMessage_offsets_,
      -1,
      -1,
      -1,
      sizeof(ScatterMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ScatterMessage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ScatterMessage, _is_default_instance_));
  GatherMessage_descriptor_ = file->message_type(1);
  static const int GatherMessage_offsets_[1] = {
  };
  GatherMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      GatherMessage_descriptor_,
      GatherMessage::default_instance_,
      GatherMessage_offsets_,
      -1,
      -1,
      -1,
      sizeof(GatherMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GatherMessage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GatherMessage, _is_default_instance_));
  PublishMessage_descriptor_ = file->message_type(2);
  static const int PublishMessage_offsets_[1] = {
  };
  PublishMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      PublishMessage_descriptor_,
      PublishMessage::default_instance_,
      PublishMessage_offsets_,
      -1,
      -1,
      -1,
      sizeof(PublishMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PublishMessage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PublishMessage, _is_default_instance_));
  MasterMessage_descriptor_ = file->message_type(3);
  static const int MasterMessage_offsets_[1] = {
  };
  MasterMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      MasterMessage_descriptor_,
      MasterMessage::default_instance_,
      MasterMessage_offsets_,
      -1,
      -1,
      -1,
      sizeof(MasterMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MasterMessage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MasterMessage, _is_default_instance_));
  SlaveMessage_descriptor_ = file->message_type(4);
  static const int SlaveMessage_offsets_[1] = {
  };
  SlaveMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      SlaveMessage_descriptor_,
      SlaveMessage::default_instance_,
      SlaveMessage_offsets_,
      -1,
      -1,
      -1,
      sizeof(SlaveMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SlaveMessage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SlaveMessage, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_yogi_5f00000000_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ScatterMessage_descriptor_, &ScatterMessage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      GatherMessage_descriptor_, &GatherMessage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      PublishMessage_descriptor_, &PublishMessage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      MasterMessage_descriptor_, &MasterMessage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      SlaveMessage_descriptor_, &SlaveMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_yogi_5f00000000_2eproto() {
  delete ScatterMessage::default_instance_;
  delete ScatterMessage_reflection_;
  delete GatherMessage::default_instance_;
  delete GatherMessage_reflection_;
  delete PublishMessage::default_instance_;
  delete PublishMessage_reflection_;
  delete MasterMessage::default_instance_;
  delete MasterMessage_reflection_;
  delete SlaveMessage::default_instance_;
  delete SlaveMessage_reflection_;
}

void protobuf_AddDesc_yogi_5f00000000_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_yogi_5f00000000_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023yogi_00000000.proto\022\ryogi_00000000\"\020\n\016"
    "ScatterMessage\"\017\n\rGatherMessage\"\020\n\016Publi"
    "shMessage\"\017\n\rMasterMessage\"\016\n\014SlaveMessa"
    "geb\006proto3", 130);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "yogi_00000000.proto", &protobuf_RegisterTypes);
  ScatterMessage::default_instance_ = new ScatterMessage();
  GatherMessage::default_instance_ = new GatherMessage();
  PublishMessage::default_instance_ = new PublishMessage();
  MasterMessage::default_instance_ = new MasterMessage();
  SlaveMessage::default_instance_ = new SlaveMessage();
  ScatterMessage::default_instance_->InitAsDefaultInstance();
  GatherMessage::default_instance_->InitAsDefaultInstance();
  PublishMessage::default_instance_->InitAsDefaultInstance();
  MasterMessage::default_instance_->InitAsDefaultInstance();
  SlaveMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_yogi_5f00000000_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_yogi_5f00000000_2eproto {
  StaticDescriptorInitializer_yogi_5f00000000_2eproto() {
    protobuf_AddDesc_yogi_5f00000000_2eproto();
  }
} static_descriptor_initializer_yogi_5f00000000_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ScatterMessage::ScatterMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:yogi_00000000_ns.ScatterMessage)
}

void ScatterMessage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

ScatterMessage::ScatterMessage(const ScatterMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:yogi_00000000_ns.ScatterMessage)
}

void ScatterMessage::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

ScatterMessage::~ScatterMessage() {
  // @@protoc_insertion_point(destructor:yogi_00000000_ns.ScatterMessage)
  SharedDtor();
}

void ScatterMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ScatterMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ScatterMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ScatterMessage_descriptor_;
}

const ScatterMessage& ScatterMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_yogi_5f00000000_2eproto();
  return *default_instance_;
}

ScatterMessage* ScatterMessage::default_instance_ = NULL;

ScatterMessage* ScatterMessage::New(::google::protobuf::Arena* arena) const {
  ScatterMessage* n = new ScatterMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ScatterMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:yogi_00000000_ns.ScatterMessage)
}

bool ScatterMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:yogi_00000000_ns.ScatterMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
  }
success:
  // @@protoc_insertion_point(parse_success:yogi_00000000_ns.ScatterMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:yogi_00000000_ns.ScatterMessage)
  return false;
#undef DO_
}

void ScatterMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:yogi_00000000_ns.ScatterMessage)
  // @@protoc_insertion_point(serialize_end:yogi_00000000_ns.ScatterMessage)
}

::google::protobuf::uint8* ScatterMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:yogi_00000000_ns.ScatterMessage)
  // @@protoc_insertion_point(serialize_to_array_end:yogi_00000000_ns.ScatterMessage)
  return target;
}

int ScatterMessage::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:yogi_00000000_ns.ScatterMessage)
  int total_size = 0;

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ScatterMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:yogi_00000000_ns.ScatterMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const ScatterMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ScatterMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:yogi_00000000_ns.ScatterMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:yogi_00000000_ns.ScatterMessage)
    MergeFrom(*source);
  }
}

void ScatterMessage::MergeFrom(const ScatterMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:yogi_00000000_ns.ScatterMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
}

void ScatterMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:yogi_00000000_ns.ScatterMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScatterMessage::CopyFrom(const ScatterMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:yogi_00000000_ns.ScatterMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScatterMessage::IsInitialized() const {

  return true;
}

void ScatterMessage::Swap(ScatterMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ScatterMessage::InternalSwap(ScatterMessage* other) {
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ScatterMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ScatterMessage_descriptor_;
  metadata.reflection = ScatterMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ScatterMessage

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GatherMessage::GatherMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:yogi_00000000_ns.GatherMessage)
}

void GatherMessage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

GatherMessage::GatherMessage(const GatherMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:yogi_00000000_ns.GatherMessage)
}

void GatherMessage::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

GatherMessage::~GatherMessage() {
  // @@protoc_insertion_point(destructor:yogi_00000000_ns.GatherMessage)
  SharedDtor();
}

void GatherMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GatherMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GatherMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GatherMessage_descriptor_;
}

const GatherMessage& GatherMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_yogi_5f00000000_2eproto();
  return *default_instance_;
}

GatherMessage* GatherMessage::default_instance_ = NULL;

GatherMessage* GatherMessage::New(::google::protobuf::Arena* arena) const {
  GatherMessage* n = new GatherMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GatherMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:yogi_00000000_ns.GatherMessage)
}

bool GatherMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:yogi_00000000_ns.GatherMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
  }
success:
  // @@protoc_insertion_point(parse_success:yogi_00000000_ns.GatherMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:yogi_00000000_ns.GatherMessage)
  return false;
#undef DO_
}

void GatherMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:yogi_00000000_ns.GatherMessage)
  // @@protoc_insertion_point(serialize_end:yogi_00000000_ns.GatherMessage)
}

::google::protobuf::uint8* GatherMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:yogi_00000000_ns.GatherMessage)
  // @@protoc_insertion_point(serialize_to_array_end:yogi_00000000_ns.GatherMessage)
  return target;
}

int GatherMessage::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:yogi_00000000_ns.GatherMessage)
  int total_size = 0;

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GatherMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:yogi_00000000_ns.GatherMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const GatherMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const GatherMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:yogi_00000000_ns.GatherMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:yogi_00000000_ns.GatherMessage)
    MergeFrom(*source);
  }
}

void GatherMessage::MergeFrom(const GatherMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:yogi_00000000_ns.GatherMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
}

void GatherMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:yogi_00000000_ns.GatherMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GatherMessage::CopyFrom(const GatherMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:yogi_00000000_ns.GatherMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GatherMessage::IsInitialized() const {

  return true;
}

void GatherMessage::Swap(GatherMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GatherMessage::InternalSwap(GatherMessage* other) {
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GatherMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GatherMessage_descriptor_;
  metadata.reflection = GatherMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GatherMessage

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PublishMessage::PublishMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:yogi_00000000_ns.PublishMessage)
}

void PublishMessage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

PublishMessage::PublishMessage(const PublishMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:yogi_00000000_ns.PublishMessage)
}

void PublishMessage::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

PublishMessage::~PublishMessage() {
  // @@protoc_insertion_point(destructor:yogi_00000000_ns.PublishMessage)
  SharedDtor();
}

void PublishMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PublishMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PublishMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PublishMessage_descriptor_;
}

const PublishMessage& PublishMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_yogi_5f00000000_2eproto();
  return *default_instance_;
}

PublishMessage* PublishMessage::default_instance_ = NULL;

PublishMessage* PublishMessage::New(::google::protobuf::Arena* arena) const {
  PublishMessage* n = new PublishMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PublishMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:yogi_00000000_ns.PublishMessage)
}

bool PublishMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:yogi_00000000_ns.PublishMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
  }
success:
  // @@protoc_insertion_point(parse_success:yogi_00000000_ns.PublishMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:yogi_00000000_ns.PublishMessage)
  return false;
#undef DO_
}

void PublishMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:yogi_00000000_ns.PublishMessage)
  // @@protoc_insertion_point(serialize_end:yogi_00000000_ns.PublishMessage)
}

::google::protobuf::uint8* PublishMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:yogi_00000000_ns.PublishMessage)
  // @@protoc_insertion_point(serialize_to_array_end:yogi_00000000_ns.PublishMessage)
  return target;
}

int PublishMessage::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:yogi_00000000_ns.PublishMessage)
  int total_size = 0;

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PublishMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:yogi_00000000_ns.PublishMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const PublishMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const PublishMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:yogi_00000000_ns.PublishMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:yogi_00000000_ns.PublishMessage)
    MergeFrom(*source);
  }
}

void PublishMessage::MergeFrom(const PublishMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:yogi_00000000_ns.PublishMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
}

void PublishMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:yogi_00000000_ns.PublishMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PublishMessage::CopyFrom(const PublishMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:yogi_00000000_ns.PublishMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PublishMessage::IsInitialized() const {

  return true;
}

void PublishMessage::Swap(PublishMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PublishMessage::InternalSwap(PublishMessage* other) {
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PublishMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PublishMessage_descriptor_;
  metadata.reflection = PublishMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PublishMessage

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MasterMessage::MasterMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:yogi_00000000_ns.MasterMessage)
}

void MasterMessage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

MasterMessage::MasterMessage(const MasterMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:yogi_00000000_ns.MasterMessage)
}

void MasterMessage::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

MasterMessage::~MasterMessage() {
  // @@protoc_insertion_point(destructor:yogi_00000000_ns.MasterMessage)
  SharedDtor();
}

void MasterMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MasterMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MasterMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MasterMessage_descriptor_;
}

const MasterMessage& MasterMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_yogi_5f00000000_2eproto();
  return *default_instance_;
}

MasterMessage* MasterMessage::default_instance_ = NULL;

MasterMessage* MasterMessage::New(::google::protobuf::Arena* arena) const {
  MasterMessage* n = new MasterMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MasterMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:yogi_00000000_ns.MasterMessage)
}

bool MasterMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:yogi_00000000_ns.MasterMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
  }
success:
  // @@protoc_insertion_point(parse_success:yogi_00000000_ns.MasterMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:yogi_00000000_ns.MasterMessage)
  return false;
#undef DO_
}

void MasterMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:yogi_00000000_ns.MasterMessage)
  // @@protoc_insertion_point(serialize_end:yogi_00000000_ns.MasterMessage)
}

::google::protobuf::uint8* MasterMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:yogi_00000000_ns.MasterMessage)
  // @@protoc_insertion_point(serialize_to_array_end:yogi_00000000_ns.MasterMessage)
  return target;
}

int MasterMessage::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:yogi_00000000_ns.MasterMessage)
  int total_size = 0;

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MasterMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:yogi_00000000_ns.MasterMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const MasterMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const MasterMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:yogi_00000000_ns.MasterMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:yogi_00000000_ns.MasterMessage)
    MergeFrom(*source);
  }
}

void MasterMessage::MergeFrom(const MasterMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:yogi_00000000_ns.MasterMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
}

void MasterMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:yogi_00000000_ns.MasterMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MasterMessage::CopyFrom(const MasterMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:yogi_00000000_ns.MasterMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MasterMessage::IsInitialized() const {

  return true;
}

void MasterMessage::Swap(MasterMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MasterMessage::InternalSwap(MasterMessage* other) {
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MasterMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MasterMessage_descriptor_;
  metadata.reflection = MasterMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// MasterMessage

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SlaveMessage::SlaveMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:yogi_00000000_ns.SlaveMessage)
}

void SlaveMessage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

SlaveMessage::SlaveMessage(const SlaveMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:yogi_00000000_ns.SlaveMessage)
}

void SlaveMessage::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

SlaveMessage::~SlaveMessage() {
  // @@protoc_insertion_point(destructor:yogi_00000000_ns.SlaveMessage)
  SharedDtor();
}

void SlaveMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SlaveMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SlaveMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SlaveMessage_descriptor_;
}

const SlaveMessage& SlaveMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_yogi_5f00000000_2eproto();
  return *default_instance_;
}

SlaveMessage* SlaveMessage::default_instance_ = NULL;

SlaveMessage* SlaveMessage::New(::google::protobuf::Arena* arena) const {
  SlaveMessage* n = new SlaveMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SlaveMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:yogi_00000000_ns.SlaveMessage)
}

bool SlaveMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:yogi_00000000_ns.SlaveMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
  }
success:
  // @@protoc_insertion_point(parse_success:yogi_00000000_ns.SlaveMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:yogi_00000000_ns.SlaveMessage)
  return false;
#undef DO_
}

void SlaveMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:yogi_00000000_ns.SlaveMessage)
  // @@protoc_insertion_point(serialize_end:yogi_00000000_ns.SlaveMessage)
}

::google::protobuf::uint8* SlaveMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:yogi_00000000_ns.SlaveMessage)
  // @@protoc_insertion_point(serialize_to_array_end:yogi_00000000_ns.SlaveMessage)
  return target;
}

int SlaveMessage::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:yogi_00000000_ns.SlaveMessage)
  int total_size = 0;

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SlaveMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:yogi_00000000_ns.SlaveMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const SlaveMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const SlaveMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:yogi_00000000_ns.SlaveMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:yogi_00000000_ns.SlaveMessage)
    MergeFrom(*source);
  }
}

void SlaveMessage::MergeFrom(const SlaveMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:yogi_00000000_ns.SlaveMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
}

void SlaveMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:yogi_00000000_ns.SlaveMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SlaveMessage::CopyFrom(const SlaveMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:yogi_00000000_ns.SlaveMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SlaveMessage::IsInitialized() const {

  return true;
}

void SlaveMessage::Swap(SlaveMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SlaveMessage::InternalSwap(SlaveMessage* other) {
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SlaveMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SlaveMessage_descriptor_;
  metadata.reflection = SlaveMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SlaveMessage

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace yogi_00000000_ns

// @@protoc_insertion_point(global_scope)
