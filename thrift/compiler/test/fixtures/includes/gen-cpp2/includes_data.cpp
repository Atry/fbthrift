/**
 * Autogenerated by Thrift for src/includes.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/includes/gen-cpp2/includes_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

namespace apache {
namespace thrift {

const std::array<folly::StringPiece, 2> TStructDataStorage<::cpp2::Included>::fields_names = {{
  "MyIntField",
  "MyTransitiveField",
}};
const std::array<int16_t, 2> TStructDataStorage<::cpp2::Included>::fields_ids = {{
  1,
  2,
}};
const std::array<protocol::TType, 2> TStructDataStorage<::cpp2::Included>::fields_types = {{
  TType::T_I64,
  TType::T_STRUCT,
}};

} // namespace thrift
} // namespace apache
