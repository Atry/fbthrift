/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdexcept>

#include <folly/Singleton.h>
#include <folly/lang/Exception.h>
#include <thrift/lib/cpp2/type/TypeRegistry.h>

namespace apache {
namespace thrift {
namespace type {
namespace detail {

FOLLY_EXPORT TypeRegistry& getGeneratedTypeRegistry() {
  struct GeneratedTag {};
  return folly::detail::createGlobal<TypeRegistry, GeneratedTag>();
}

} // namespace detail

AnyData TypeRegistry::store(AnyRef value, const Protocol&) const {
  switch (value.type().base_type()) {
    case BaseType::Void:
      return {};
    default:
      // TODO(afuller): Implement.
      folly::throw_exception<std::out_of_range>("Not Implemented");
  }
}

void TypeRegistry::load(const AnyData& value, AnyRef out) const {
  switch (value.type().base_type()) {
    case BaseType::Void:
      if (out.type() != value.type()) {
        folly::throw_exception<std::bad_any_cast>();
      }
      return;
    default:
      // TODO(afuller): Implement.
      folly::throw_exception<std::out_of_range>("Not Implemented");
  }
}

AnyValue TypeRegistry::load(const AnyData& data) const {
  switch (data.type().base_type()) {
    case BaseType::Void:
      return {};
    default:
      // TODO(afuller): Implement.
      folly::throw_exception<std::out_of_range>("Not Implemented");
  }
}

} // namespace type
} // namespace thrift
} // namespace apache
