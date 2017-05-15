// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: yogi_0000000f.proto

#ifndef PROTOBUF_yogi_5f0000000f_2eproto__INCLUDED
#define PROTOBUF_yogi_5f0000000f_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace yogi_0000000f_ns {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_yogi_5f0000000f_2eproto();
void protobuf_AssignDesc_yogi_5f0000000f_2eproto();
void protobuf_ShutdownFile_yogi_5f0000000f_2eproto();

class GatherMessage;
class MasterMessage;
class PublishMessage;
class ScatterMessage;
class SlaveMessage;

// ===================================================================

class ScatterMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:yogi_0000000f_ns.ScatterMessage) */ {
 public:
  ScatterMessage();
  virtual ~ScatterMessage();

  ScatterMessage(const ScatterMessage& from);

  inline ScatterMessage& operator=(const ScatterMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ScatterMessage& default_instance();

  void Swap(ScatterMessage* other);

  // implements Message ----------------------------------------------

  inline ScatterMessage* New() const { return New(NULL); }

  ScatterMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ScatterMessage& from);
  void MergeFrom(const ScatterMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ScatterMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:yogi_0000000f_ns.ScatterMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_AssignDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f0000000f_2eproto();

  void InitAsDefaultInstance();
  static ScatterMessage* default_instance_;
};
// -------------------------------------------------------------------

class GatherMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:yogi_0000000f_ns.GatherMessage) */ {
 public:
  GatherMessage();
  virtual ~GatherMessage();

  GatherMessage(const GatherMessage& from);

  inline GatherMessage& operator=(const GatherMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GatherMessage& default_instance();

  void Swap(GatherMessage* other);

  // implements Message ----------------------------------------------

  inline GatherMessage* New() const { return New(NULL); }

  GatherMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GatherMessage& from);
  void MergeFrom(const GatherMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GatherMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes value = 2;
  void clear_value();
  static const int kValueFieldNumber = 2;
  const ::std::string& value() const;
  void set_value(const ::std::string& value);
  void set_value(const char* value);
  void set_value(const void* value, size_t size);
  ::std::string* mutable_value();
  ::std::string* release_value();
  void set_allocated_value(::std::string* value);

  // @@protoc_insertion_point(class_scope:yogi_0000000f_ns.GatherMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr value_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_AssignDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f0000000f_2eproto();

  void InitAsDefaultInstance();
  static GatherMessage* default_instance_;
};
// -------------------------------------------------------------------

class PublishMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:yogi_0000000f_ns.PublishMessage) */ {
 public:
  PublishMessage();
  virtual ~PublishMessage();

  PublishMessage(const PublishMessage& from);

  inline PublishMessage& operator=(const PublishMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PublishMessage& default_instance();

  void Swap(PublishMessage* other);

  // implements Message ----------------------------------------------

  inline PublishMessage* New() const { return New(NULL); }

  PublishMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PublishMessage& from);
  void MergeFrom(const PublishMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PublishMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes value = 2;
  void clear_value();
  static const int kValueFieldNumber = 2;
  const ::std::string& value() const;
  void set_value(const ::std::string& value);
  void set_value(const char* value);
  void set_value(const void* value, size_t size);
  ::std::string* mutable_value();
  ::std::string* release_value();
  void set_allocated_value(::std::string* value);

  // @@protoc_insertion_point(class_scope:yogi_0000000f_ns.PublishMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr value_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_AssignDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f0000000f_2eproto();

  void InitAsDefaultInstance();
  static PublishMessage* default_instance_;
};
// -------------------------------------------------------------------

class MasterMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:yogi_0000000f_ns.MasterMessage) */ {
 public:
  MasterMessage();
  virtual ~MasterMessage();

  MasterMessage(const MasterMessage& from);

  inline MasterMessage& operator=(const MasterMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MasterMessage& default_instance();

  void Swap(MasterMessage* other);

  // implements Message ----------------------------------------------

  inline MasterMessage* New() const { return New(NULL); }

  MasterMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MasterMessage& from);
  void MergeFrom(const MasterMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MasterMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:yogi_0000000f_ns.MasterMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_AssignDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f0000000f_2eproto();

  void InitAsDefaultInstance();
  static MasterMessage* default_instance_;
};
// -------------------------------------------------------------------

class SlaveMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:yogi_0000000f_ns.SlaveMessage) */ {
 public:
  SlaveMessage();
  virtual ~SlaveMessage();

  SlaveMessage(const SlaveMessage& from);

  inline SlaveMessage& operator=(const SlaveMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SlaveMessage& default_instance();

  void Swap(SlaveMessage* other);

  // implements Message ----------------------------------------------

  inline SlaveMessage* New() const { return New(NULL); }

  SlaveMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SlaveMessage& from);
  void MergeFrom(const SlaveMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SlaveMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes value = 2;
  void clear_value();
  static const int kValueFieldNumber = 2;
  const ::std::string& value() const;
  void set_value(const ::std::string& value);
  void set_value(const char* value);
  void set_value(const void* value, size_t size);
  ::std::string* mutable_value();
  ::std::string* release_value();
  void set_allocated_value(::std::string* value);

  // @@protoc_insertion_point(class_scope:yogi_0000000f_ns.SlaveMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr value_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_AssignDesc_yogi_5f0000000f_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f0000000f_2eproto();

  void InitAsDefaultInstance();
  static SlaveMessage* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ScatterMessage

// -------------------------------------------------------------------

// GatherMessage

// optional bytes value = 2;
inline void GatherMessage::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GatherMessage::value() const {
  // @@protoc_insertion_point(field_get:yogi_0000000f_ns.GatherMessage.value)
  return value_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GatherMessage::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:yogi_0000000f_ns.GatherMessage.value)
}
inline void GatherMessage::set_value(const char* value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:yogi_0000000f_ns.GatherMessage.value)
}
inline void GatherMessage::set_value(const void* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:yogi_0000000f_ns.GatherMessage.value)
}
inline ::std::string* GatherMessage::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:yogi_0000000f_ns.GatherMessage.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GatherMessage::release_value() {
  // @@protoc_insertion_point(field_release:yogi_0000000f_ns.GatherMessage.value)
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GatherMessage::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:yogi_0000000f_ns.GatherMessage.value)
}

// -------------------------------------------------------------------

// PublishMessage

// optional bytes value = 2;
inline void PublishMessage::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PublishMessage::value() const {
  // @@protoc_insertion_point(field_get:yogi_0000000f_ns.PublishMessage.value)
  return value_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PublishMessage::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:yogi_0000000f_ns.PublishMessage.value)
}
inline void PublishMessage::set_value(const char* value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:yogi_0000000f_ns.PublishMessage.value)
}
inline void PublishMessage::set_value(const void* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:yogi_0000000f_ns.PublishMessage.value)
}
inline ::std::string* PublishMessage::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:yogi_0000000f_ns.PublishMessage.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PublishMessage::release_value() {
  // @@protoc_insertion_point(field_release:yogi_0000000f_ns.PublishMessage.value)
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PublishMessage::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:yogi_0000000f_ns.PublishMessage.value)
}

// -------------------------------------------------------------------

// MasterMessage

// -------------------------------------------------------------------

// SlaveMessage

// optional bytes value = 2;
inline void SlaveMessage::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SlaveMessage::value() const {
  // @@protoc_insertion_point(field_get:yogi_0000000f_ns.SlaveMessage.value)
  return value_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SlaveMessage::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:yogi_0000000f_ns.SlaveMessage.value)
}
inline void SlaveMessage::set_value(const char* value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:yogi_0000000f_ns.SlaveMessage.value)
}
inline void SlaveMessage::set_value(const void* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:yogi_0000000f_ns.SlaveMessage.value)
}
inline ::std::string* SlaveMessage::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:yogi_0000000f_ns.SlaveMessage.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SlaveMessage::release_value() {
  // @@protoc_insertion_point(field_release:yogi_0000000f_ns.SlaveMessage.value)
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SlaveMessage::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:yogi_0000000f_ns.SlaveMessage.value)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace yogi_0000000f_ns

struct yogi_0000000f
{
    typedef yogi_0000000f_ns::PublishMessage PublishMessage;
    typedef yogi_0000000f_ns::ScatterMessage ScatterMessage;
    typedef yogi_0000000f_ns::GatherMessage  GatherMessage;
    typedef yogi_0000000f_ns::MasterMessage  MasterMessage;
    typedef yogi_0000000f_ns::SlaveMessage   SlaveMessage;

    enum {
        SIGNATURE = 0x0000000f
    };
};

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_yogi_5f0000000f_2eproto__INCLUDED