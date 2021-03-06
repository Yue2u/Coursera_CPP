// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: svg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_svg_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_svg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_svg_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_svg_2eproto;
namespace SvgProto {
class Color;
struct ColorDefaultTypeInternal;
extern ColorDefaultTypeInternal _Color_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
class Rgba;
struct RgbaDefaultTypeInternal;
extern RgbaDefaultTypeInternal _Rgba_default_instance_;
}  // namespace SvgProto
PROTOBUF_NAMESPACE_OPEN
template<> ::SvgProto::Color* Arena::CreateMaybeMessage<::SvgProto::Color>(Arena*);
template<> ::SvgProto::Point* Arena::CreateMaybeMessage<::SvgProto::Point>(Arena*);
template<> ::SvgProto::Rgba* Arena::CreateMaybeMessage<::SvgProto::Rgba>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace SvgProto {

// ===================================================================

class Rgba final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SvgProto.Rgba) */ {
 public:
  inline Rgba() : Rgba(nullptr) {}
  ~Rgba() override;
  explicit constexpr Rgba(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Rgba(const Rgba& from);
  Rgba(Rgba&& from) noexcept
    : Rgba() {
    *this = ::std::move(from);
  }

  inline Rgba& operator=(const Rgba& from) {
    CopyFrom(from);
    return *this;
  }
  inline Rgba& operator=(Rgba&& from) noexcept {
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
  static const Rgba& default_instance() {
    return *internal_default_instance();
  }
  static inline const Rgba* internal_default_instance() {
    return reinterpret_cast<const Rgba*>(
               &_Rgba_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Rgba& a, Rgba& b) {
    a.Swap(&b);
  }
  inline void Swap(Rgba* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Rgba* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Rgba* New() const final {
    return new Rgba();
  }

  Rgba* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Rgba>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Rgba& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Rgba& from);
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
  void InternalSwap(Rgba* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SvgProto.Rgba";
  }
  protected:
  explicit Rgba(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kRedFieldNumber = 1,
    kGreenFieldNumber = 2,
    kBlueFieldNumber = 3,
    kHasOpacityFieldNumber = 4,
    kOpacityFieldNumber = 5,
  };
  // uint32 red = 1;
  void clear_red();
  ::PROTOBUF_NAMESPACE_ID::uint32 red() const;
  void set_red(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_red() const;
  void _internal_set_red(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 green = 2;
  void clear_green();
  ::PROTOBUF_NAMESPACE_ID::uint32 green() const;
  void set_green(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_green() const;
  void _internal_set_green(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 blue = 3;
  void clear_blue();
  ::PROTOBUF_NAMESPACE_ID::uint32 blue() const;
  void set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_blue() const;
  void _internal_set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // bool has_opacity = 4;
  void clear_has_opacity();
  bool has_opacity() const;
  void set_has_opacity(bool value);
  private:
  bool _internal_has_opacity() const;
  void _internal_set_has_opacity(bool value);
  public:

  // double opacity = 5;
  void clear_opacity();
  double opacity() const;
  void set_opacity(double value);
  private:
  double _internal_opacity() const;
  void _internal_set_opacity(double value);
  public:

  // @@protoc_insertion_point(class_scope:SvgProto.Rgba)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint32 red_;
  ::PROTOBUF_NAMESPACE_ID::uint32 green_;
  ::PROTOBUF_NAMESPACE_ID::uint32 blue_;
  bool has_opacity_;
  double opacity_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class Color final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SvgProto.Color) */ {
 public:
  inline Color() : Color(nullptr) {}
  ~Color() override;
  explicit constexpr Color(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Color(const Color& from);
  Color(Color&& from) noexcept
    : Color() {
    *this = ::std::move(from);
  }

  inline Color& operator=(const Color& from) {
    CopyFrom(from);
    return *this;
  }
  inline Color& operator=(Color&& from) noexcept {
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
  static const Color& default_instance() {
    return *internal_default_instance();
  }
  enum DataCase {
    kIsNone = 1,
    kName = 2,
    kRgba = 3,
    DATA_NOT_SET = 0,
  };

  static inline const Color* internal_default_instance() {
    return reinterpret_cast<const Color*>(
               &_Color_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Color& a, Color& b) {
    a.Swap(&b);
  }
  inline void Swap(Color* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Color* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Color* New() const final {
    return new Color();
  }

  Color* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Color>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Color& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Color& from);
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
  void InternalSwap(Color* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SvgProto.Color";
  }
  protected:
  explicit Color(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kIsNoneFieldNumber = 1,
    kNameFieldNumber = 2,
    kRgbaFieldNumber = 3,
  };
  // bool is_none = 1;
  bool has_is_none() const;
  private:
  bool _internal_has_is_none() const;
  public:
  void clear_is_none();
  bool is_none() const;
  void set_is_none(bool value);
  private:
  bool _internal_is_none() const;
  void _internal_set_is_none(bool value);
  public:

  // string name = 2;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
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

  // .SvgProto.Rgba rgba = 3;
  bool has_rgba() const;
  private:
  bool _internal_has_rgba() const;
  public:
  void clear_rgba();
  const ::SvgProto::Rgba& rgba() const;
  PROTOBUF_MUST_USE_RESULT ::SvgProto::Rgba* release_rgba();
  ::SvgProto::Rgba* mutable_rgba();
  void set_allocated_rgba(::SvgProto::Rgba* rgba);
  private:
  const ::SvgProto::Rgba& _internal_rgba() const;
  ::SvgProto::Rgba* _internal_mutable_rgba();
  public:
  void unsafe_arena_set_allocated_rgba(
      ::SvgProto::Rgba* rgba);
  ::SvgProto::Rgba* unsafe_arena_release_rgba();

  void clear_data();
  DataCase data_case() const;
  // @@protoc_insertion_point(class_scope:SvgProto.Color)
 private:
  class _Internal;
  void set_has_is_none();
  void set_has_name();
  void set_has_rgba();

  inline bool has_data() const;
  inline void clear_has_data();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union DataUnion {
    constexpr DataUnion() : _constinit_{} {}
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
    bool is_none_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::SvgProto::Rgba* rgba_;
  } data_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class Point final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SvgProto.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  explicit constexpr Point(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
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
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Point* New() const final {
    return new Point();
  }

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Point& from);
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
  void InternalSwap(Point* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SvgProto.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:SvgProto.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Rgba

// uint32 red = 1;
inline void Rgba::clear_red() {
  red_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::_internal_red() const {
  return red_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::red() const {
  // @@protoc_insertion_point(field_get:SvgProto.Rgba.red)
  return _internal_red();
}
inline void Rgba::_internal_set_red(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  red_ = value;
}
inline void Rgba::set_red(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_red(value);
  // @@protoc_insertion_point(field_set:SvgProto.Rgba.red)
}

// uint32 green = 2;
inline void Rgba::clear_green() {
  green_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::_internal_green() const {
  return green_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::green() const {
  // @@protoc_insertion_point(field_get:SvgProto.Rgba.green)
  return _internal_green();
}
inline void Rgba::_internal_set_green(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  green_ = value;
}
inline void Rgba::set_green(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_green(value);
  // @@protoc_insertion_point(field_set:SvgProto.Rgba.green)
}

// uint32 blue = 3;
inline void Rgba::clear_blue() {
  blue_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::_internal_blue() const {
  return blue_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::blue() const {
  // @@protoc_insertion_point(field_get:SvgProto.Rgba.blue)
  return _internal_blue();
}
inline void Rgba::_internal_set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  blue_ = value;
}
inline void Rgba::set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_blue(value);
  // @@protoc_insertion_point(field_set:SvgProto.Rgba.blue)
}

// bool has_opacity = 4;
inline void Rgba::clear_has_opacity() {
  has_opacity_ = false;
}
inline bool Rgba::_internal_has_opacity() const {
  return has_opacity_;
}
inline bool Rgba::has_opacity() const {
  // @@protoc_insertion_point(field_get:SvgProto.Rgba.has_opacity)
  return _internal_has_opacity();
}
inline void Rgba::_internal_set_has_opacity(bool value) {
  
  has_opacity_ = value;
}
inline void Rgba::set_has_opacity(bool value) {
  _internal_set_has_opacity(value);
  // @@protoc_insertion_point(field_set:SvgProto.Rgba.has_opacity)
}

// double opacity = 5;
inline void Rgba::clear_opacity() {
  opacity_ = 0;
}
inline double Rgba::_internal_opacity() const {
  return opacity_;
}
inline double Rgba::opacity() const {
  // @@protoc_insertion_point(field_get:SvgProto.Rgba.opacity)
  return _internal_opacity();
}
inline void Rgba::_internal_set_opacity(double value) {
  
  opacity_ = value;
}
inline void Rgba::set_opacity(double value) {
  _internal_set_opacity(value);
  // @@protoc_insertion_point(field_set:SvgProto.Rgba.opacity)
}

// -------------------------------------------------------------------

// Color

// bool is_none = 1;
inline bool Color::_internal_has_is_none() const {
  return data_case() == kIsNone;
}
inline bool Color::has_is_none() const {
  return _internal_has_is_none();
}
inline void Color::set_has_is_none() {
  _oneof_case_[0] = kIsNone;
}
inline void Color::clear_is_none() {
  if (_internal_has_is_none()) {
    data_.is_none_ = false;
    clear_has_data();
  }
}
inline bool Color::_internal_is_none() const {
  if (_internal_has_is_none()) {
    return data_.is_none_;
  }
  return false;
}
inline void Color::_internal_set_is_none(bool value) {
  if (!_internal_has_is_none()) {
    clear_data();
    set_has_is_none();
  }
  data_.is_none_ = value;
}
inline bool Color::is_none() const {
  // @@protoc_insertion_point(field_get:SvgProto.Color.is_none)
  return _internal_is_none();
}
inline void Color::set_is_none(bool value) {
  _internal_set_is_none(value);
  // @@protoc_insertion_point(field_set:SvgProto.Color.is_none)
}

// string name = 2;
inline bool Color::_internal_has_name() const {
  return data_case() == kName;
}
inline bool Color::has_name() const {
  return _internal_has_name();
}
inline void Color::set_has_name() {
  _oneof_case_[0] = kName;
}
inline void Color::clear_name() {
  if (_internal_has_name()) {
    data_.name_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
    clear_has_data();
  }
}
inline const std::string& Color::name() const {
  // @@protoc_insertion_point(field_get:SvgProto.Color.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline void Color::set_name(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_name()) {
    clear_data();
    set_has_name();
    data_.name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  data_.name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SvgProto.Color.name)
}
inline std::string* Color::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:SvgProto.Color.name)
  return _s;
}
inline const std::string& Color::_internal_name() const {
  if (_internal_has_name()) {
    return data_.name_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void Color::_internal_set_name(const std::string& value) {
  if (!_internal_has_name()) {
    clear_data();
    set_has_name();
    data_.name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  data_.name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Color::_internal_mutable_name() {
  if (!_internal_has_name()) {
    clear_data();
    set_has_name();
    data_.name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return data_.name_.Mutable(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Color::release_name() {
  // @@protoc_insertion_point(field_release:SvgProto.Color.name)
  if (_internal_has_name()) {
    clear_has_data();
    return data_.name_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
  } else {
    return nullptr;
  }
}
inline void Color::set_allocated_name(std::string* name) {
  if (has_data()) {
    clear_data();
  }
  if (name != nullptr) {
    set_has_name();
    data_.name_.UnsafeSetDefault(name);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaForAllocation();
    if (arena != nullptr) {
      arena->Own(name);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:SvgProto.Color.name)
}

// .SvgProto.Rgba rgba = 3;
inline bool Color::_internal_has_rgba() const {
  return data_case() == kRgba;
}
inline bool Color::has_rgba() const {
  return _internal_has_rgba();
}
inline void Color::set_has_rgba() {
  _oneof_case_[0] = kRgba;
}
inline void Color::clear_rgba() {
  if (_internal_has_rgba()) {
    if (GetArenaForAllocation() == nullptr) {
      delete data_.rgba_;
    }
    clear_has_data();
  }
}
inline ::SvgProto::Rgba* Color::release_rgba() {
  // @@protoc_insertion_point(field_release:SvgProto.Color.rgba)
  if (_internal_has_rgba()) {
    clear_has_data();
      ::SvgProto::Rgba* temp = data_.rgba_;
    if (GetArenaForAllocation() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    data_.rgba_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::SvgProto::Rgba& Color::_internal_rgba() const {
  return _internal_has_rgba()
      ? *data_.rgba_
      : reinterpret_cast< ::SvgProto::Rgba&>(::SvgProto::_Rgba_default_instance_);
}
inline const ::SvgProto::Rgba& Color::rgba() const {
  // @@protoc_insertion_point(field_get:SvgProto.Color.rgba)
  return _internal_rgba();
}
inline ::SvgProto::Rgba* Color::unsafe_arena_release_rgba() {
  // @@protoc_insertion_point(field_unsafe_arena_release:SvgProto.Color.rgba)
  if (_internal_has_rgba()) {
    clear_has_data();
    ::SvgProto::Rgba* temp = data_.rgba_;
    data_.rgba_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Color::unsafe_arena_set_allocated_rgba(::SvgProto::Rgba* rgba) {
  clear_data();
  if (rgba) {
    set_has_rgba();
    data_.rgba_ = rgba;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:SvgProto.Color.rgba)
}
inline ::SvgProto::Rgba* Color::_internal_mutable_rgba() {
  if (!_internal_has_rgba()) {
    clear_data();
    set_has_rgba();
    data_.rgba_ = CreateMaybeMessage< ::SvgProto::Rgba >(GetArenaForAllocation());
  }
  return data_.rgba_;
}
inline ::SvgProto::Rgba* Color::mutable_rgba() {
  ::SvgProto::Rgba* _msg = _internal_mutable_rgba();
  // @@protoc_insertion_point(field_mutable:SvgProto.Color.rgba)
  return _msg;
}

inline bool Color::has_data() const {
  return data_case() != DATA_NOT_SET;
}
inline void Color::clear_has_data() {
  _oneof_case_[0] = DATA_NOT_SET;
}
inline Color::DataCase Color::data_case() const {
  return Color::DataCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// Point

// double x = 1;
inline void Point::clear_x() {
  x_ = 0;
}
inline double Point::_internal_x() const {
  return x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:SvgProto.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:SvgProto.Point.x)
}

// double y = 2;
inline void Point::clear_y() {
  y_ = 0;
}
inline double Point::_internal_y() const {
  return y_;
}
inline double Point::y() const {
  // @@protoc_insertion_point(field_get:SvgProto.Point.y)
  return _internal_y();
}
inline void Point::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Point::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:SvgProto.Point.y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace SvgProto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
