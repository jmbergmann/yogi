// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: yogi_00000003.proto

#ifndef PROTOBUF_yogi_5f00000003_2eproto__INCLUDED
#define PROTOBUF_yogi_5f00000003_2eproto__INCLUDED

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
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
// @@protoc_insertion_point(includes)

namespace yogi_00000003_ns {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_yogi_5f00000003_2eproto();
void protobuf_AssignDesc_yogi_5f00000003_2eproto();
void protobuf_ShutdownFile_yogi_5f00000003_2eproto();

class GatherMessage;
class MasterMessage;
class PublishMessage;
class ScatterMessage;
class SlaveMessage;

// ===================================================================

class ScatterMessage : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:yogi_00000003_ns.ScatterMessage) */ {
 public:
  ScatterMessage();
  virtual ~ScatterMessage();

  ScatterMessage(const ScatterMessage& from);

  inline ScatterMessage& operator=(const ScatterMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ScatterMessage& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const ScatterMessage* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(ScatterMessage* other);

  // implements Message ----------------------------------------------

  inline ScatterMessage* New() const { return New(NULL); }

  ScatterMessage* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const ScatterMessage& from);
  void MergeFrom(const ScatterMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ScatterMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:yogi_00000003_ns.ScatterMessage)
 private:

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  bool _is_default_instance_;
  mutable int _cached_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto();
  #endif
  friend void protobuf_AssignDesc_yogi_5f00000003_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f00000003_2eproto();

  void InitAsDefaultInstance();
  static ScatterMessage* default_instance_;
};
// -------------------------------------------------------------------

class GatherMessage : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:yogi_00000003_ns.GatherMessage) */ {
 public:
  GatherMessage();
  virtual ~GatherMessage();

  GatherMessage(const GatherMessage& from);

  inline GatherMessage& operator=(const GatherMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const GatherMessage& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const GatherMessage* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(GatherMessage* other);

  // implements Message ----------------------------------------------

  inline GatherMessage* New() const { return New(NULL); }

  GatherMessage* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const GatherMessage& from);
  void MergeFrom(const GatherMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GatherMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 value = 2;
  void clear_value();
  static const int kValueFieldNumber = 2;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:yogi_00000003_ns.GatherMessage)
 private:

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  bool _is_default_instance_;
  ::google::protobuf::int32 value_;
  mutable int _cached_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto();
  #endif
  friend void protobuf_AssignDesc_yogi_5f00000003_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f00000003_2eproto();

  void InitAsDefaultInstance();
  static GatherMessage* default_instance_;
};
// -------------------------------------------------------------------

class PublishMessage : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:yogi_00000003_ns.PublishMessage) */ {
 public:
  PublishMessage();
  virtual ~PublishMessage();

  PublishMessage(const PublishMessage& from);

  inline PublishMessage& operator=(const PublishMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const PublishMessage& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const PublishMessage* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(PublishMessage* other);

  // implements Message ----------------------------------------------

  inline PublishMessage* New() const { return New(NULL); }

  PublishMessage* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const PublishMessage& from);
  void MergeFrom(const PublishMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PublishMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 value = 2;
  void clear_value();
  static const int kValueFieldNumber = 2;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:yogi_00000003_ns.PublishMessage)
 private:

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  bool _is_default_instance_;
  ::google::protobuf::int32 value_;
  mutable int _cached_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto();
  #endif
  friend void protobuf_AssignDesc_yogi_5f00000003_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f00000003_2eproto();

  void InitAsDefaultInstance();
  static PublishMessage* default_instance_;
};
// -------------------------------------------------------------------

class MasterMessage : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:yogi_00000003_ns.MasterMessage) */ {
 public:
  MasterMessage();
  virtual ~MasterMessage();

  MasterMessage(const MasterMessage& from);

  inline MasterMessage& operator=(const MasterMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const MasterMessage& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const MasterMessage* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(MasterMessage* other);

  // implements Message ----------------------------------------------

  inline MasterMessage* New() const { return New(NULL); }

  MasterMessage* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const MasterMessage& from);
  void MergeFrom(const MasterMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MasterMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:yogi_00000003_ns.MasterMessage)
 private:

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  bool _is_default_instance_;
  mutable int _cached_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto();
  #endif
  friend void protobuf_AssignDesc_yogi_5f00000003_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f00000003_2eproto();

  void InitAsDefaultInstance();
  static MasterMessage* default_instance_;
};
// -------------------------------------------------------------------

class SlaveMessage : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:yogi_00000003_ns.SlaveMessage) */ {
 public:
  SlaveMessage();
  virtual ~SlaveMessage();

  SlaveMessage(const SlaveMessage& from);

  inline SlaveMessage& operator=(const SlaveMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const SlaveMessage& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const SlaveMessage* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(SlaveMessage* other);

  // implements Message ----------------------------------------------

  inline SlaveMessage* New() const { return New(NULL); }

  SlaveMessage* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const SlaveMessage& from);
  void MergeFrom(const SlaveMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SlaveMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 value = 2;
  void clear_value();
  static const int kValueFieldNumber = 2;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:yogi_00000003_ns.SlaveMessage)
 private:

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  bool _is_default_instance_;
  ::google::protobuf::int32 value_;
  mutable int _cached_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_yogi_5f00000003_2eproto();
  #endif
  friend void protobuf_AssignDesc_yogi_5f00000003_2eproto();
  friend void protobuf_ShutdownFile_yogi_5f00000003_2eproto();

  void InitAsDefaultInstance();
  static SlaveMessage* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ScatterMessage

// -------------------------------------------------------------------

// GatherMessage

// optional sint32 value = 2;
inline void GatherMessage::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 GatherMessage::value() const {
  // @@protoc_insertion_point(field_get:yogi_00000003_ns.GatherMessage.value)
  return value_;
}
inline void GatherMessage::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:yogi_00000003_ns.GatherMessage.value)
}

// -------------------------------------------------------------------

// PublishMessage

// optional sint32 value = 2;
inline void PublishMessage::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 PublishMessage::value() const {
  // @@protoc_insertion_point(field_get:yogi_00000003_ns.PublishMessage.value)
  return value_;
}
inline void PublishMessage::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:yogi_00000003_ns.PublishMessage.value)
}

// -------------------------------------------------------------------

// MasterMessage

// -------------------------------------------------------------------

// SlaveMessage

// optional sint32 value = 2;
inline void SlaveMessage::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 SlaveMessage::value() const {
  // @@protoc_insertion_point(field_get:yogi_00000003_ns.SlaveMessage.value)
  return value_;
}
inline void SlaveMessage::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:yogi_00000003_ns.SlaveMessage.value)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace yogi_00000003_ns

struct yogi_00000003
{
    typedef yogi_00000003_ns::PublishMessage PublishMessage;
    typedef yogi_00000003_ns::ScatterMessage ScatterMessage;
    typedef yogi_00000003_ns::GatherMessage  GatherMessage;
    typedef yogi_00000003_ns::MasterMessage  MasterMessage;
    typedef yogi_00000003_ns::SlaveMessage   SlaveMessage;

    enum {
        SIGNATURE = 0x00000003
    };
};

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_yogi_5f00000003_2eproto__INCLUDED
