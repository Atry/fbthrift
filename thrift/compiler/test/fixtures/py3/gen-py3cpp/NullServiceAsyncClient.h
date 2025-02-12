/**
 * Autogenerated by Thrift for src/empty.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/py3/gen-py3cpp/empty_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {
class NullService;
} // cpp2
namespace apache::thrift {

template <>
class Client<::cpp2::NullService> : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "NullService";
  }


};

} // namespace apache::thrift

namespace cpp2 {
using NullServiceAsyncClient = ::apache::thrift::Client<NullService>;
} // cpp2
