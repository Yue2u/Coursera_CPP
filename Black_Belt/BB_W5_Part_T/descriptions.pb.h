// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: descriptions.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_descriptions_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_descriptions_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_descriptions_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_descriptions_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_descriptions_2eproto;
namespace TCProto {
class BusDescription;
struct BusDescriptionDefaultTypeInternal;
extern BusDescriptionDefaultTypeInternal _BusDescription_default_instance_;
}  // namespace TCProto
PROTOBUF_NAMESPACE_OPEN
template<> ::TCProto::BusDescription* Arena::CreateMaybeMessage<::TCProto::BusDescription>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TCProto {

// ===================================================================

class BusDescription final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TCProto.BusDescription) */ {
 public:
  inline BusDescription() : BusDescription(nullptr) {}
  ~BusDescription() override;
  explicit constexpr BusDescription(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BusDescription(const BusDescription& from);
  BusDescription(BusDescription&& from) noexcept
    : BusDescription() {
    *this = ::std::move(from);
  }

  inline BusDescription& operator=(const BusDescription& from) {
    CopyFrom(from);
    return *this;
  }
  inline BusDescription& operator=(BusDescription&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
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
  static const BusDescription& default_instance() {
    return *internal_default_instance();
  }
  static inline const BusDescription* internal_default_instance() {
    return reinterpret_cast<const BusDescription*>(
               &_BusDescription_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BusDescription& a, BusDescription& b) {
    a.Swap(&b);
  }
  inline void Swap(BusDescription* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BusDescription* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BusDescription* New() const final {
    return new BusDescription();
  }

  BusDescription* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BusDescription>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const BusDescription& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const BusDescription& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BusDescription* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TCProto.BusDescription";
  }
  protected:
  explicit BusDescription(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStopsFieldNumber = 2,
    kEndpointsFieldNumber = 3,
    kNameFieldNumber = 1,
  };
  // repeated string stops = 2;
  int stops_size() const;
  private:
  int _internal_stops_size() const;
  public:
  void clear_stops();
  const std::string& stops(int index) const;
  std::string* mutable_stops(int index);
  void set_stops(int index, const std::string& value);
  void set_stops(int index, std::string&& value);
  void set_stops(int index, const char* value);
  void set_stops(int index, const char* value, size_t size);
  std::string* add_stops();
  void add_stops(const std::string& value);
  void add_stops(std::string&& value);
  void add_stops(const char* value);
  void add_stops(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& stops() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_stops();
  private:
  const std::string& _internal_stops(int index) const;
  std::string* _internal_add_stops();
  public:

  // repeated string endpoints = 3;
  int endpoints_size() const;
  private:
  int _internal_endpoints_size() const;
  public:
  void clear_endpoints();
  const std::string& endpoints(int index) const;
  std::string* mutable_endpoints(int index);
  void set_endpoints(int index, const std::string& value);
  void set_endpoints(int index, std::string&& value);
  void set_endpoints(int index, const char* value);
  void set_endpoints(int index, const char* value, size_t size);
  std::string* add_endpoints();
  void add_endpoints(const std::string& value);
  void add_endpoints(std::string&& value);
  void add_endpoints(const char* value);
  void add_endpoints(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& endpoints() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_endpoints();
  private:
  const std::string& _internal_endpoints(int index) const;
  std::string* _internal_add_endpoints();
  public:

  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // @@protoc_insertion_point(class_scope:TCProto.BusDescription)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> stops_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> endpoints_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_descriptions_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BusDescription

// string name = 1;
inline void BusDescription::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& BusDescription::name() const {
  // @@protoc_insertion_point(field_get:TCProto.BusDescription.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void BusDescription::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:TCProto.BusDescription.name)
}
inline std::string* BusDescription::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:TCProto.BusDescription.name)
  return _s;
}
inline const std::string& BusDescription::_internal_name() const {
  return name_.Get();
}
inline void BusDescription::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* BusDescription::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* BusDescription::release_name() {
  // @@protoc_insertion_point(field_release:TCProto.BusDescription.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void BusDescription::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:TCProto.BusDescription.name)
}

// repeated string stops = 2;
inline int BusDescription::_internal_stops_size() const {
  return stops_.size();
}
inline int BusDescription::stops_size() const {
  return _internal_stops_size();
}
inline void BusDescription::clear_stops() {
  stops_.Clear();
}
inline std::string* BusDescription::add_stops() {
  std::string* _s = _internal_add_stops();
  // @@protoc_insertion_point(field_add_mutable:TCProto.BusDescription.stops)
  return _s;
}
inline const std::string& BusDescription::_internal_stops(int index) const {
  return stops_.Get(index);
}
inline const std::string& BusDescription::stops(int index) const {
  // @@protoc_insertion_point(field_get:TCProto.BusDescription.stops)
  return _internal_stops(index);
}
inline std::string* BusDescription::mutable_stops(int index) {
  // @@protoc_insertion_point(field_mutable:TCProto.BusDescription.stops)
  return stops_.Mutable(index);
}
inline void BusDescription::set_stops(int index, const std::string& value) {
  stops_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:TCProto.BusDescription.stops)
}
inline void BusDescription::set_stops(int index, std::string&& value) {
  stops_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:TCProto.BusDescription.stops)
}
inline void BusDescription::set_stops(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  stops_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:TCProto.BusDescription.stops)
}
inline void BusDescription::set_stops(int index, const char* value, size_t size) {
  stops_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:TCProto.BusDescription.stops)
}
inline std::string* BusDescription::_internal_add_stops() {
  return stops_.Add();
}
inline void BusDescription::add_stops(const std::string& value) {
  stops_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:TCProto.BusDescription.stops)
}
inline void BusDescription::add_stops(std::string&& value) {
  stops_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:TCProto.BusDescription.stops)
}
inline void BusDescription::add_stops(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  stops_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:TCProto.BusDescription.stops)
}
inline void BusDescription::add_stops(const char* value, size_t size) {
  stops_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:TCProto.BusDescription.stops)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
BusDescription::stops() const {
  // @@protoc_insertion_point(field_list:TCProto.BusDescription.stops)
  return stops_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
BusDescription::mutable_stops() {
  // @@protoc_insertion_point(field_mutable_list:TCProto.BusDescription.stops)
  return &stops_;
}

// repeated string endpoints = 3;
inline int BusDescription::_internal_endpoints_size() const {
  return endpoints_.size();
}
inline int BusDescription::endpoints_size() const {
  return _internal_endpoints_size();
}
inline void BusDescription::clear_endpoints() {
  endpoints_.Clear();
}
inline std::string* BusDescription::add_endpoints() {
  std::string* _s = _internal_add_endpoints();
  // @@protoc_insertion_point(field_add_mutable:TCProto.BusDescription.endpoints)
  return _s;
}
inline const std::string& BusDescription::_internal_endpoints(int index) const {
  return endpoints_.Get(index);
}
inline const std::string& BusDescription::endpoints(int index) const {
  // @@protoc_insertion_point(field_get:TCProto.BusDescription.endpoints)
  return _internal_endpoints(index);
}
inline std::string* BusDescription::mutable_endpoints(int index) {
  // @@protoc_insertion_point(field_mutable:TCProto.BusDescription.endpoints)
  return endpoints_.Mutable(index);
}
inline void BusDescription::set_endpoints(int index, const std::string& value) {
  endpoints_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:TCProto.BusDescription.endpoints)
}
inline void BusDescription::set_endpoints(int index, std::string&& value) {
  endpoints_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:TCProto.BusDescription.endpoints)
}
inline void BusDescription::set_endpoints(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  endpoints_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:TCProto.BusDescription.endpoints)
}
inline void BusDescription::set_endpoints(int index, const char* value, size_t size) {
  endpoints_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:TCProto.BusDescription.endpoints)
}
inline std::string* BusDescription::_internal_add_endpoints() {
  return endpoints_.Add();
}
inline void BusDescription::add_endpoints(const std::string& value) {
  endpoints_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:TCProto.BusDescription.endpoints)
}
inline void BusDescription::add_endpoints(std::string&& value) {
  endpoints_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:TCProto.BusDescription.endpoints)
}
inline void BusDescription::add_endpoints(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  endpoints_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:TCProto.BusDescription.endpoints)
}
inline void BusDescription::add_endpoints(const char* value, size_t size) {
  endpoints_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:TCProto.BusDescription.endpoints)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
BusDescription::endpoints() const {
  // @@protoc_insertion_point(field_list:TCProto.BusDescription.endpoints)
  return endpoints_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
BusDescription::mutable_endpoints() {
  // @@protoc_insertion_point(field_mutable_list:TCProto.BusDescription.endpoints)
  return &endpoints_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace TCProto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_descriptions_2eproto
