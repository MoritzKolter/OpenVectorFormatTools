// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ovf_lut.proto

#include "ovf_lut.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace OpenVectorFormat {
constexpr JobLUT::JobLUT(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : workplanepositions_()
  , _workplanepositions_cached_byte_size_()
  , jobshellposition_(PROTOBUF_LONGLONG(0)){}
struct JobLUTDefaultTypeInternal {
  constexpr JobLUTDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~JobLUTDefaultTypeInternal() {}
  union {
    JobLUT _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT JobLUTDefaultTypeInternal _JobLUT_default_instance_;
constexpr WorkPlaneLUT::WorkPlaneLUT(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : vectorblockspositions_()
  , _vectorblockspositions_cached_byte_size_()
  , workplaneshellposition_(PROTOBUF_LONGLONG(0)){}
struct WorkPlaneLUTDefaultTypeInternal {
  constexpr WorkPlaneLUTDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~WorkPlaneLUTDefaultTypeInternal() {}
  union {
    WorkPlaneLUT _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT WorkPlaneLUTDefaultTypeInternal _WorkPlaneLUT_default_instance_;
}  // namespace OpenVectorFormat
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ovf_5flut_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ovf_5flut_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ovf_5flut_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_ovf_5flut_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::OpenVectorFormat::JobLUT, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::OpenVectorFormat::JobLUT, jobshellposition_),
  PROTOBUF_FIELD_OFFSET(::OpenVectorFormat::JobLUT, workplanepositions_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::OpenVectorFormat::WorkPlaneLUT, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::OpenVectorFormat::WorkPlaneLUT, workplaneshellposition_),
  PROTOBUF_FIELD_OFFSET(::OpenVectorFormat::WorkPlaneLUT, vectorblockspositions_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::OpenVectorFormat::JobLUT)},
  { 7, -1, sizeof(::OpenVectorFormat::WorkPlaneLUT)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::OpenVectorFormat::_JobLUT_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::OpenVectorFormat::_WorkPlaneLUT_default_instance_),
};

const char descriptor_table_protodef_ovf_5flut_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rovf_lut.proto\022\020OpenVectorFormat\">\n\006Job"
  "LUT\022\030\n\020jobShellPosition\030\001 \001(\003\022\032\n\022workPla"
  "nePositions\030\002 \003(\003\"M\n\014WorkPlaneLUT\022\036\n\026wor"
  "kPlaneShellPosition\030\001 \001(\003\022\035\n\025vectorBlock"
  "sPositions\030\002 \003(\003b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ovf_5flut_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ovf_5flut_2eproto = {
  false, false, 184, descriptor_table_protodef_ovf_5flut_2eproto, "ovf_lut.proto", 
  &descriptor_table_ovf_5flut_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_ovf_5flut_2eproto::offsets,
  file_level_metadata_ovf_5flut_2eproto, file_level_enum_descriptors_ovf_5flut_2eproto, file_level_service_descriptors_ovf_5flut_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_ovf_5flut_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_ovf_5flut_2eproto);
  return descriptor_table_ovf_5flut_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_ovf_5flut_2eproto(&descriptor_table_ovf_5flut_2eproto);
namespace OpenVectorFormat {

// ===================================================================

class JobLUT::_Internal {
 public:
};

JobLUT::JobLUT(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  workplanepositions_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:OpenVectorFormat.JobLUT)
}
JobLUT::JobLUT(const JobLUT& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      workplanepositions_(from.workplanepositions_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  jobshellposition_ = from.jobshellposition_;
  // @@protoc_insertion_point(copy_constructor:OpenVectorFormat.JobLUT)
}

void JobLUT::SharedCtor() {
jobshellposition_ = PROTOBUF_LONGLONG(0);
}

JobLUT::~JobLUT() {
  // @@protoc_insertion_point(destructor:OpenVectorFormat.JobLUT)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void JobLUT::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void JobLUT::ArenaDtor(void* object) {
  JobLUT* _this = reinterpret_cast< JobLUT* >(object);
  (void)_this;
}
void JobLUT::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void JobLUT::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void JobLUT::Clear() {
// @@protoc_insertion_point(message_clear_start:OpenVectorFormat.JobLUT)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  workplanepositions_.Clear();
  jobshellposition_ = PROTOBUF_LONGLONG(0);
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* JobLUT::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int64 jobShellPosition = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          jobshellposition_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated int64 workPlanePositions = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt64Parser(_internal_mutable_workplanepositions(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16) {
          _internal_add_workplanepositions(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* JobLUT::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:OpenVectorFormat.JobLUT)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 jobShellPosition = 1;
  if (this->jobshellposition() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_jobshellposition(), target);
  }

  // repeated int64 workPlanePositions = 2;
  {
    int byte_size = _workplanepositions_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt64Packed(
          2, _internal_workplanepositions(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:OpenVectorFormat.JobLUT)
  return target;
}

size_t JobLUT::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:OpenVectorFormat.JobLUT)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int64 workPlanePositions = 2;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int64Size(this->workplanepositions_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _workplanepositions_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // int64 jobShellPosition = 1;
  if (this->jobshellposition() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_jobshellposition());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void JobLUT::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:OpenVectorFormat.JobLUT)
  GOOGLE_DCHECK_NE(&from, this);
  const JobLUT* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<JobLUT>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:OpenVectorFormat.JobLUT)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:OpenVectorFormat.JobLUT)
    MergeFrom(*source);
  }
}

void JobLUT::MergeFrom(const JobLUT& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:OpenVectorFormat.JobLUT)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  workplanepositions_.MergeFrom(from.workplanepositions_);
  if (from.jobshellposition() != 0) {
    _internal_set_jobshellposition(from._internal_jobshellposition());
  }
}

void JobLUT::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:OpenVectorFormat.JobLUT)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void JobLUT::CopyFrom(const JobLUT& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:OpenVectorFormat.JobLUT)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool JobLUT::IsInitialized() const {
  return true;
}

void JobLUT::InternalSwap(JobLUT* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  workplanepositions_.InternalSwap(&other->workplanepositions_);
  swap(jobshellposition_, other->jobshellposition_);
}

::PROTOBUF_NAMESPACE_ID::Metadata JobLUT::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class WorkPlaneLUT::_Internal {
 public:
};

WorkPlaneLUT::WorkPlaneLUT(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  vectorblockspositions_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:OpenVectorFormat.WorkPlaneLUT)
}
WorkPlaneLUT::WorkPlaneLUT(const WorkPlaneLUT& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      vectorblockspositions_(from.vectorblockspositions_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  workplaneshellposition_ = from.workplaneshellposition_;
  // @@protoc_insertion_point(copy_constructor:OpenVectorFormat.WorkPlaneLUT)
}

void WorkPlaneLUT::SharedCtor() {
workplaneshellposition_ = PROTOBUF_LONGLONG(0);
}

WorkPlaneLUT::~WorkPlaneLUT() {
  // @@protoc_insertion_point(destructor:OpenVectorFormat.WorkPlaneLUT)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void WorkPlaneLUT::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void WorkPlaneLUT::ArenaDtor(void* object) {
  WorkPlaneLUT* _this = reinterpret_cast< WorkPlaneLUT* >(object);
  (void)_this;
}
void WorkPlaneLUT::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void WorkPlaneLUT::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void WorkPlaneLUT::Clear() {
// @@protoc_insertion_point(message_clear_start:OpenVectorFormat.WorkPlaneLUT)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  vectorblockspositions_.Clear();
  workplaneshellposition_ = PROTOBUF_LONGLONG(0);
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* WorkPlaneLUT::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int64 workPlaneShellPosition = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          workplaneshellposition_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated int64 vectorBlocksPositions = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt64Parser(_internal_mutable_vectorblockspositions(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16) {
          _internal_add_vectorblockspositions(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* WorkPlaneLUT::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:OpenVectorFormat.WorkPlaneLUT)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 workPlaneShellPosition = 1;
  if (this->workplaneshellposition() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_workplaneshellposition(), target);
  }

  // repeated int64 vectorBlocksPositions = 2;
  {
    int byte_size = _vectorblockspositions_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt64Packed(
          2, _internal_vectorblockspositions(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:OpenVectorFormat.WorkPlaneLUT)
  return target;
}

size_t WorkPlaneLUT::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:OpenVectorFormat.WorkPlaneLUT)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int64 vectorBlocksPositions = 2;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int64Size(this->vectorblockspositions_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _vectorblockspositions_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // int64 workPlaneShellPosition = 1;
  if (this->workplaneshellposition() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_workplaneshellposition());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void WorkPlaneLUT::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:OpenVectorFormat.WorkPlaneLUT)
  GOOGLE_DCHECK_NE(&from, this);
  const WorkPlaneLUT* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<WorkPlaneLUT>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:OpenVectorFormat.WorkPlaneLUT)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:OpenVectorFormat.WorkPlaneLUT)
    MergeFrom(*source);
  }
}

void WorkPlaneLUT::MergeFrom(const WorkPlaneLUT& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:OpenVectorFormat.WorkPlaneLUT)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  vectorblockspositions_.MergeFrom(from.vectorblockspositions_);
  if (from.workplaneshellposition() != 0) {
    _internal_set_workplaneshellposition(from._internal_workplaneshellposition());
  }
}

void WorkPlaneLUT::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:OpenVectorFormat.WorkPlaneLUT)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WorkPlaneLUT::CopyFrom(const WorkPlaneLUT& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:OpenVectorFormat.WorkPlaneLUT)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WorkPlaneLUT::IsInitialized() const {
  return true;
}

void WorkPlaneLUT::InternalSwap(WorkPlaneLUT* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  vectorblockspositions_.InternalSwap(&other->vectorblockspositions_);
  swap(workplaneshellposition_, other->workplaneshellposition_);
}

::PROTOBUF_NAMESPACE_ID::Metadata WorkPlaneLUT::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace OpenVectorFormat
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::OpenVectorFormat::JobLUT* Arena::CreateMaybeMessage< ::OpenVectorFormat::JobLUT >(Arena* arena) {
  return Arena::CreateMessageInternal< ::OpenVectorFormat::JobLUT >(arena);
}
template<> PROTOBUF_NOINLINE ::OpenVectorFormat::WorkPlaneLUT* Arena::CreateMaybeMessage< ::OpenVectorFormat::WorkPlaneLUT >(Arena* arena) {
  return Arena::CreateMessageInternal< ::OpenVectorFormat::WorkPlaneLUT >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
