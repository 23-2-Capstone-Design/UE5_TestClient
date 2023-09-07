// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace protocol {
class Header;
struct HeaderDefaultTypeInternal;
extern HeaderDefaultTypeInternal _Header_default_instance_;
class Rotate;
struct RotateDefaultTypeInternal;
extern RotateDefaultTypeInternal _Rotate_default_instance_;
class Vector;
struct VectorDefaultTypeInternal;
extern VectorDefaultTypeInternal _Vector_default_instance_;
}  // namespace protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::protocol::Header* Arena::CreateMaybeMessage<::protocol::Header>(Arena*);
template<> ::protocol::Rotate* Arena::CreateMaybeMessage<::protocol::Rotate>(Arena*);
template<> ::protocol::Vector* Arena::CreateMaybeMessage<::protocol::Vector>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protocol {

// ===================================================================

class Header final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.Header) */ {
 public:
  inline Header() : Header(nullptr) {}
  ~Header() override;
  explicit PROTOBUF_CONSTEXPR Header(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Header(const Header& from);
  Header(Header&& from) noexcept
    : Header() {
    *this = ::std::move(from);
  }

  inline Header& operator=(const Header& from) {
    CopyFrom(from);
    return *this;
  }
  inline Header& operator=(Header&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Header& default_instance() {
    return *internal_default_instance();
  }
  static inline const Header* internal_default_instance() {
    return reinterpret_cast<const Header*>(
               &_Header_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Header& a, Header& b) {
    a.Swap(&b);
  }
  inline void Swap(Header* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Header* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Header* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Header>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Header& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Header& from) {
    Header::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Header* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.Header";
  }
  protected:
  explicit Header(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSizeFieldNumber = 1,
    kTypeFieldNumber = 2,
  };
  // uint32 size = 1;
  void clear_size();
  uint32_t size() const;
  void set_size(uint32_t value);
  private:
  uint32_t _internal_size() const;
  void _internal_set_size(uint32_t value);
  public:

  // .protocol.PacketType type = 2;
  void clear_type();
  ::protocol::PacketType type() const;
  void set_type(::protocol::PacketType value);
  private:
  ::protocol::PacketType _internal_type() const;
  void _internal_set_type(::protocol::PacketType value);
  public:

  // @@protoc_insertion_point(class_scope:protocol.Header)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    uint32_t size_;
    int type_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Struct_2eproto;
};
// -------------------------------------------------------------------

class Vector final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.Vector) */ {
 public:
  inline Vector() : Vector(nullptr) {}
  ~Vector() override;
  explicit PROTOBUF_CONSTEXPR Vector(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Vector(const Vector& from);
  Vector(Vector&& from) noexcept
    : Vector() {
    *this = ::std::move(from);
  }

  inline Vector& operator=(const Vector& from) {
    CopyFrom(from);
    return *this;
  }
  inline Vector& operator=(Vector&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Vector& default_instance() {
    return *internal_default_instance();
  }
  static inline const Vector* internal_default_instance() {
    return reinterpret_cast<const Vector*>(
               &_Vector_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Vector& a, Vector& b) {
    a.Swap(&b);
  }
  inline void Swap(Vector* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Vector* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Vector* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Vector>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Vector& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Vector& from) {
    Vector::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Vector* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.Vector";
  }
  protected:
  explicit Vector(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
  };
  // float x = 1;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 2;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // float z = 3;
  void clear_z();
  float z() const;
  void set_z(float value);
  private:
  float _internal_z() const;
  void _internal_set_z(float value);
  public:

  // @@protoc_insertion_point(class_scope:protocol.Vector)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    float x_;
    float y_;
    float z_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Struct_2eproto;
};
// -------------------------------------------------------------------

class Rotate final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.Rotate) */ {
 public:
  inline Rotate() : Rotate(nullptr) {}
  ~Rotate() override;
  explicit PROTOBUF_CONSTEXPR Rotate(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Rotate(const Rotate& from);
  Rotate(Rotate&& from) noexcept
    : Rotate() {
    *this = ::std::move(from);
  }

  inline Rotate& operator=(const Rotate& from) {
    CopyFrom(from);
    return *this;
  }
  inline Rotate& operator=(Rotate&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Rotate& default_instance() {
    return *internal_default_instance();
  }
  static inline const Rotate* internal_default_instance() {
    return reinterpret_cast<const Rotate*>(
               &_Rotate_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Rotate& a, Rotate& b) {
    a.Swap(&b);
  }
  inline void Swap(Rotate* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Rotate* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Rotate* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Rotate>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Rotate& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Rotate& from) {
    Rotate::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Rotate* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.Rotate";
  }
  protected:
  explicit Rotate(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRollFieldNumber = 1,
    kPitchFieldNumber = 2,
    kYawFieldNumber = 3,
  };
  // float roll = 1;
  void clear_roll();
  float roll() const;
  void set_roll(float value);
  private:
  float _internal_roll() const;
  void _internal_set_roll(float value);
  public:

  // float pitch = 2;
  void clear_pitch();
  float pitch() const;
  void set_pitch(float value);
  private:
  float _internal_pitch() const;
  void _internal_set_pitch(float value);
  public:

  // float yaw = 3;
  void clear_yaw();
  float yaw() const;
  void set_yaw(float value);
  private:
  float _internal_yaw() const;
  void _internal_set_yaw(float value);
  public:

  // @@protoc_insertion_point(class_scope:protocol.Rotate)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    float roll_;
    float pitch_;
    float yaw_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Header

// uint32 size = 1;
inline void Header::clear_size() {
  _impl_.size_ = 0u;
}
inline uint32_t Header::_internal_size() const {
  return _impl_.size_;
}
inline uint32_t Header::size() const {
  // @@protoc_insertion_point(field_get:protocol.Header.size)
  return _internal_size();
}
inline void Header::_internal_set_size(uint32_t value) {
  
  _impl_.size_ = value;
}
inline void Header::set_size(uint32_t value) {
  _internal_set_size(value);
  // @@protoc_insertion_point(field_set:protocol.Header.size)
}

// .protocol.PacketType type = 2;
inline void Header::clear_type() {
  _impl_.type_ = 0;
}
inline ::protocol::PacketType Header::_internal_type() const {
  return static_cast< ::protocol::PacketType >(_impl_.type_);
}
inline ::protocol::PacketType Header::type() const {
  // @@protoc_insertion_point(field_get:protocol.Header.type)
  return _internal_type();
}
inline void Header::_internal_set_type(::protocol::PacketType value) {
  
  _impl_.type_ = value;
}
inline void Header::set_type(::protocol::PacketType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:protocol.Header.type)
}

// -------------------------------------------------------------------

// Vector

// float x = 1;
inline void Vector::clear_x() {
  _impl_.x_ = 0;
}
inline float Vector::_internal_x() const {
  return _impl_.x_;
}
inline float Vector::x() const {
  // @@protoc_insertion_point(field_get:protocol.Vector.x)
  return _internal_x();
}
inline void Vector::_internal_set_x(float value) {
  
  _impl_.x_ = value;
}
inline void Vector::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:protocol.Vector.x)
}

// float y = 2;
inline void Vector::clear_y() {
  _impl_.y_ = 0;
}
inline float Vector::_internal_y() const {
  return _impl_.y_;
}
inline float Vector::y() const {
  // @@protoc_insertion_point(field_get:protocol.Vector.y)
  return _internal_y();
}
inline void Vector::_internal_set_y(float value) {
  
  _impl_.y_ = value;
}
inline void Vector::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:protocol.Vector.y)
}

// float z = 3;
inline void Vector::clear_z() {
  _impl_.z_ = 0;
}
inline float Vector::_internal_z() const {
  return _impl_.z_;
}
inline float Vector::z() const {
  // @@protoc_insertion_point(field_get:protocol.Vector.z)
  return _internal_z();
}
inline void Vector::_internal_set_z(float value) {
  
  _impl_.z_ = value;
}
inline void Vector::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:protocol.Vector.z)
}

// -------------------------------------------------------------------

// Rotate

// float roll = 1;
inline void Rotate::clear_roll() {
  _impl_.roll_ = 0;
}
inline float Rotate::_internal_roll() const {
  return _impl_.roll_;
}
inline float Rotate::roll() const {
  // @@protoc_insertion_point(field_get:protocol.Rotate.roll)
  return _internal_roll();
}
inline void Rotate::_internal_set_roll(float value) {
  
  _impl_.roll_ = value;
}
inline void Rotate::set_roll(float value) {
  _internal_set_roll(value);
  // @@protoc_insertion_point(field_set:protocol.Rotate.roll)
}

// float pitch = 2;
inline void Rotate::clear_pitch() {
  _impl_.pitch_ = 0;
}
inline float Rotate::_internal_pitch() const {
  return _impl_.pitch_;
}
inline float Rotate::pitch() const {
  // @@protoc_insertion_point(field_get:protocol.Rotate.pitch)
  return _internal_pitch();
}
inline void Rotate::_internal_set_pitch(float value) {
  
  _impl_.pitch_ = value;
}
inline void Rotate::set_pitch(float value) {
  _internal_set_pitch(value);
  // @@protoc_insertion_point(field_set:protocol.Rotate.pitch)
}

// float yaw = 3;
inline void Rotate::clear_yaw() {
  _impl_.yaw_ = 0;
}
inline float Rotate::_internal_yaw() const {
  return _impl_.yaw_;
}
inline float Rotate::yaw() const {
  // @@protoc_insertion_point(field_get:protocol.Rotate.yaw)
  return _internal_yaw();
}
inline void Rotate::_internal_set_yaw(float value) {
  
  _impl_.yaw_ = value;
}
inline void Rotate::set_yaw(float value) {
  _internal_set_yaw(value);
  // @@protoc_insertion_point(field_set:protocol.Rotate.yaw)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
