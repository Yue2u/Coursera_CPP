// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: phone.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_phone_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_phone_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_phone_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_phone_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_phone_2eproto;
namespace YellowPages {
class Phone;
struct PhoneDefaultTypeInternal;
extern PhoneDefaultTypeInternal _Phone_default_instance_;
}  // namespace YellowPages
PROTOBUF_NAMESPACE_OPEN
template<> ::YellowPages::Phone* Arena::CreateMaybeMessage<::YellowPages::Phone>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace YellowPages {

enum Phone_Type : int {
  Phone_Type_PHONE = 0,
  Phone_Type_FAX = 1,
  Phone_Type_Phone_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Phone_Type_Phone_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Phone_Type_IsValid(int value);
constexpr Phone_Type Phone_Type_Type_MIN = Phone_Type_PHONE;
constexpr Phone_Type Phone_Type_Type_MAX = Phone_Type_FAX;
constexpr int Phone_Type_Type_ARRAYSIZE = Phone_Type_Type_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Phone_Type_descriptor();
template<typename T>
inline const std::string& Phone_Type_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Phone_Type>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Phone_Type_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Phone_Type_descriptor(), enum_t_value);
}
inline bool Phone_Type_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Phone_Type* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Phone_Type>(
    Phone_Type_descriptor(), name, value);
}
// ===================================================================

class Phone final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:YellowPages.Phone) */ {
 public:
  inline Phone() : Phone(nullptr) {}
  ~Phone() override;
  explicit constexpr Phone(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Phone(const Phone& from);
  Phone(Phone&& from) noexcept
    : Phone() {
    *this = ::std::move(from);
  }

  inline Phone& operator=(const Phone& from) {
    CopyFrom(from);
    return *this;
  }
  inline Phone& operator=(Phone&& from) noexcept {
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
  static const Phone& default_instance() {
    return *internal_default_instance();
  }
  static inline const Phone* internal_default_instance() {
    return reinterpret_cast<const Phone*>(
               &_Phone_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Phone& a, Phone& b) {
    a.Swap(&b);
  }
  inline void Swap(Phone* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Phone* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Phone* New() const final {
    return new Phone();
  }

  Phone* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Phone>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Phone& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Phone& from);
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
  void InternalSwap(Phone* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "YellowPages.Phone";
  }
  protected:
  explicit Phone(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Phone_Type Type;
  static constexpr Type PHONE =
    Phone_Type_PHONE;
  static constexpr Type FAX =
    Phone_Type_FAX;
  static inline bool Type_IsValid(int value) {
    return Phone_Type_IsValid(value);
  }
  static constexpr Type Type_MIN =
    Phone_Type_Type_MIN;
  static constexpr Type Type_MAX =
    Phone_Type_Type_MAX;
  static constexpr int Type_ARRAYSIZE =
    Phone_Type_Type_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Type_descriptor() {
    return Phone_Type_descriptor();
  }
  template<typename T>
  static inline const std::string& Type_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Type>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Type_Name.");
    return Phone_Type_Name(enum_t_value);
  }
  static inline bool Type_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Type* value) {
    return Phone_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kFormattedFieldNumber = 1,
    kCountryCodeFieldNumber = 3,
    kLocalCodeFieldNumber = 4,
    kNumberFieldNumber = 5,
    kExtensionFieldNumber = 6,
    kDescriptionFieldNumber = 7,
    kTypeFieldNumber = 2,
  };
  // string formatted = 1;
  void clear_formatted();
  const std::string& formatted() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_formatted(ArgT0&& arg0, ArgT... args);
  std::string* mutable_formatted();
  PROTOBUF_MUST_USE_RESULT std::string* release_formatted();
  void set_allocated_formatted(std::string* formatted);
  private:
  const std::string& _internal_formatted() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_formatted(const std::string& value);
  std::string* _internal_mutable_formatted();
  public:

  // string country_code = 3;
  void clear_country_code();
  const std::string& country_code() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_country_code(ArgT0&& arg0, ArgT... args);
  std::string* mutable_country_code();
  PROTOBUF_MUST_USE_RESULT std::string* release_country_code();
  void set_allocated_country_code(std::string* country_code);
  private:
  const std::string& _internal_country_code() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_country_code(const std::string& value);
  std::string* _internal_mutable_country_code();
  public:

  // string local_code = 4;
  void clear_local_code();
  const std::string& local_code() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_local_code(ArgT0&& arg0, ArgT... args);
  std::string* mutable_local_code();
  PROTOBUF_MUST_USE_RESULT std::string* release_local_code();
  void set_allocated_local_code(std::string* local_code);
  private:
  const std::string& _internal_local_code() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_local_code(const std::string& value);
  std::string* _internal_mutable_local_code();
  public:

  // string number = 5;
  void clear_number();
  const std::string& number() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_number(ArgT0&& arg0, ArgT... args);
  std::string* mutable_number();
  PROTOBUF_MUST_USE_RESULT std::string* release_number();
  void set_allocated_number(std::string* number);
  private:
  const std::string& _internal_number() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_number(const std::string& value);
  std::string* _internal_mutable_number();
  public:

  // string extension = 6;
  void clear_extension();
  const std::string& extension() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_extension(ArgT0&& arg0, ArgT... args);
  std::string* mutable_extension();
  PROTOBUF_MUST_USE_RESULT std::string* release_extension();
  void set_allocated_extension(std::string* extension);
  private:
  const std::string& _internal_extension() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_extension(const std::string& value);
  std::string* _internal_mutable_extension();
  public:

  // string description = 7;
  void clear_description();
  const std::string& description() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_description(ArgT0&& arg0, ArgT... args);
  std::string* mutable_description();
  PROTOBUF_MUST_USE_RESULT std::string* release_description();
  void set_allocated_description(std::string* description);
  private:
  const std::string& _internal_description() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_description(const std::string& value);
  std::string* _internal_mutable_description();
  public:

  // .YellowPages.Phone.Type type = 2;
  void clear_type();
  ::YellowPages::Phone_Type type() const;
  void set_type(::YellowPages::Phone_Type value);
  private:
  ::YellowPages::Phone_Type _internal_type() const;
  void _internal_set_type(::YellowPages::Phone_Type value);
  public:

  // @@protoc_insertion_point(class_scope:YellowPages.Phone)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr formatted_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr country_code_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr local_code_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr number_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr extension_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr description_;
  int type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_phone_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Phone

// string formatted = 1;
inline void Phone::clear_formatted() {
  formatted_.ClearToEmpty();
}
inline const std::string& Phone::formatted() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.formatted)
  return _internal_formatted();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Phone::set_formatted(ArgT0&& arg0, ArgT... args) {
 
 formatted_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Phone.formatted)
}
inline std::string* Phone::mutable_formatted() {
  std::string* _s = _internal_mutable_formatted();
  // @@protoc_insertion_point(field_mutable:YellowPages.Phone.formatted)
  return _s;
}
inline const std::string& Phone::_internal_formatted() const {
  return formatted_.Get();
}
inline void Phone::_internal_set_formatted(const std::string& value) {
  
  formatted_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Phone::_internal_mutable_formatted() {
  
  return formatted_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Phone::release_formatted() {
  // @@protoc_insertion_point(field_release:YellowPages.Phone.formatted)
  return formatted_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Phone::set_allocated_formatted(std::string* formatted) {
  if (formatted != nullptr) {
    
  } else {
    
  }
  formatted_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), formatted,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Phone.formatted)
}

// .YellowPages.Phone.Type type = 2;
inline void Phone::clear_type() {
  type_ = 0;
}
inline ::YellowPages::Phone_Type Phone::_internal_type() const {
  return static_cast< ::YellowPages::Phone_Type >(type_);
}
inline ::YellowPages::Phone_Type Phone::type() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.type)
  return _internal_type();
}
inline void Phone::_internal_set_type(::YellowPages::Phone_Type value) {
  
  type_ = value;
}
inline void Phone::set_type(::YellowPages::Phone_Type value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:YellowPages.Phone.type)
}

// string country_code = 3;
inline void Phone::clear_country_code() {
  country_code_.ClearToEmpty();
}
inline const std::string& Phone::country_code() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.country_code)
  return _internal_country_code();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Phone::set_country_code(ArgT0&& arg0, ArgT... args) {
 
 country_code_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Phone.country_code)
}
inline std::string* Phone::mutable_country_code() {
  std::string* _s = _internal_mutable_country_code();
  // @@protoc_insertion_point(field_mutable:YellowPages.Phone.country_code)
  return _s;
}
inline const std::string& Phone::_internal_country_code() const {
  return country_code_.Get();
}
inline void Phone::_internal_set_country_code(const std::string& value) {
  
  country_code_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Phone::_internal_mutable_country_code() {
  
  return country_code_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Phone::release_country_code() {
  // @@protoc_insertion_point(field_release:YellowPages.Phone.country_code)
  return country_code_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Phone::set_allocated_country_code(std::string* country_code) {
  if (country_code != nullptr) {
    
  } else {
    
  }
  country_code_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), country_code,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Phone.country_code)
}

// string local_code = 4;
inline void Phone::clear_local_code() {
  local_code_.ClearToEmpty();
}
inline const std::string& Phone::local_code() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.local_code)
  return _internal_local_code();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Phone::set_local_code(ArgT0&& arg0, ArgT... args) {
 
 local_code_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Phone.local_code)
}
inline std::string* Phone::mutable_local_code() {
  std::string* _s = _internal_mutable_local_code();
  // @@protoc_insertion_point(field_mutable:YellowPages.Phone.local_code)
  return _s;
}
inline const std::string& Phone::_internal_local_code() const {
  return local_code_.Get();
}
inline void Phone::_internal_set_local_code(const std::string& value) {
  
  local_code_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Phone::_internal_mutable_local_code() {
  
  return local_code_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Phone::release_local_code() {
  // @@protoc_insertion_point(field_release:YellowPages.Phone.local_code)
  return local_code_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Phone::set_allocated_local_code(std::string* local_code) {
  if (local_code != nullptr) {
    
  } else {
    
  }
  local_code_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), local_code,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Phone.local_code)
}

// string number = 5;
inline void Phone::clear_number() {
  number_.ClearToEmpty();
}
inline const std::string& Phone::number() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.number)
  return _internal_number();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Phone::set_number(ArgT0&& arg0, ArgT... args) {
 
 number_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Phone.number)
}
inline std::string* Phone::mutable_number() {
  std::string* _s = _internal_mutable_number();
  // @@protoc_insertion_point(field_mutable:YellowPages.Phone.number)
  return _s;
}
inline const std::string& Phone::_internal_number() const {
  return number_.Get();
}
inline void Phone::_internal_set_number(const std::string& value) {
  
  number_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Phone::_internal_mutable_number() {
  
  return number_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Phone::release_number() {
  // @@protoc_insertion_point(field_release:YellowPages.Phone.number)
  return number_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Phone::set_allocated_number(std::string* number) {
  if (number != nullptr) {
    
  } else {
    
  }
  number_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), number,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Phone.number)
}

// string extension = 6;
inline void Phone::clear_extension() {
  extension_.ClearToEmpty();
}
inline const std::string& Phone::extension() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.extension)
  return _internal_extension();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Phone::set_extension(ArgT0&& arg0, ArgT... args) {
 
 extension_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Phone.extension)
}
inline std::string* Phone::mutable_extension() {
  std::string* _s = _internal_mutable_extension();
  // @@protoc_insertion_point(field_mutable:YellowPages.Phone.extension)
  return _s;
}
inline const std::string& Phone::_internal_extension() const {
  return extension_.Get();
}
inline void Phone::_internal_set_extension(const std::string& value) {
  
  extension_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Phone::_internal_mutable_extension() {
  
  return extension_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Phone::release_extension() {
  // @@protoc_insertion_point(field_release:YellowPages.Phone.extension)
  return extension_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Phone::set_allocated_extension(std::string* extension) {
  if (extension != nullptr) {
    
  } else {
    
  }
  extension_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), extension,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Phone.extension)
}

// string description = 7;
inline void Phone::clear_description() {
  description_.ClearToEmpty();
}
inline const std::string& Phone::description() const {
  // @@protoc_insertion_point(field_get:YellowPages.Phone.description)
  return _internal_description();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Phone::set_description(ArgT0&& arg0, ArgT... args) {
 
 description_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Phone.description)
}
inline std::string* Phone::mutable_description() {
  std::string* _s = _internal_mutable_description();
  // @@protoc_insertion_point(field_mutable:YellowPages.Phone.description)
  return _s;
}
inline const std::string& Phone::_internal_description() const {
  return description_.Get();
}
inline void Phone::_internal_set_description(const std::string& value) {
  
  description_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Phone::_internal_mutable_description() {
  
  return description_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Phone::release_description() {
  // @@protoc_insertion_point(field_release:YellowPages.Phone.description)
  return description_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Phone::set_allocated_description(std::string* description) {
  if (description != nullptr) {
    
  } else {
    
  }
  description_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), description,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Phone.description)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace YellowPages

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::YellowPages::Phone_Type> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::YellowPages::Phone_Type>() {
  return ::YellowPages::Phone_Type_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_phone_2eproto