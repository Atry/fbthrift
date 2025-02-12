/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/ServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/module_types.h"
#include "thrift/annotation/gen-cpp2/cpp_types.h"
#include "thrift/annotation/gen-cpp2/python_types.h"
#include "thrift/annotation/gen-cpp2/thrift_types.h"
#include "thrift/annotation/gen-cpp2/hack_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace cpp2 {
class Service;
class ServiceAsyncProcessor;

class ServiceServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
} // cpp2

namespace apache::thrift {
template <>
class ServiceHandler<::cpp2::Service> : public apache::thrift::ServerInterface {
 public:
  std::string_view getGeneratedName() const override { return "Service"; }

  typedef ::cpp2::ServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

  virtual ::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::cpp2::MyI32> func(std::unique_ptr<::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::cpp2::StringWithAdapter>> /*arg1*/, std::unique_ptr<::std::string> /*arg2*/, std::unique_ptr<::cpp2::Foo> /*arg3*/);
  virtual folly::Future<::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::cpp2::MyI32>> future_func(std::unique_ptr<::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::cpp2::StringWithAdapter>> p_arg1, std::unique_ptr<::std::string> p_arg2, std::unique_ptr<::cpp2::Foo> p_arg3);
  virtual folly::SemiFuture<::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::cpp2::MyI32>> semifuture_func(std::unique_ptr<::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::cpp2::StringWithAdapter>> p_arg1, std::unique_ptr<::std::string> p_arg2, std::unique_ptr<::cpp2::Foo> p_arg3);
  virtual void async_tm_func(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::cpp2::MyI32>>> callback, std::unique_ptr<::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::cpp2::StringWithAdapter>> p_arg1, std::unique_ptr<::std::string> p_arg2, std::unique_ptr<::cpp2::Foo> p_arg3);
 private:
  static ::cpp2::ServiceServiceInfoHolder __fbthrift_serviceInfoHolder;
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_func{apache::thrift::detail::si::InvocationType::AsyncTm};
};

} // namespace apache::thrift

namespace cpp2 {
using ServiceSvIf = ::apache::thrift::ServiceHandler<Service>;
} // cpp2
namespace cpp2 {
class ServiceSvNull : public ServiceSvIf {
 public:
  ::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::cpp2::MyI32> func(std::unique_ptr<::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::cpp2::StringWithAdapter>> /*arg1*/, std::unique_ptr<::std::string> /*arg2*/, std::unique_ptr<::cpp2::Foo> /*arg3*/) override;
};

class ServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  ::apache::thrift::ServiceHandler<::cpp2::Service>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessor::ProcessFuncs<ServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFuncs>;
  static const ServiceAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const ServiceAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_func(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_func(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::SerializedResponse return_func(apache::thrift::ContextStack* ctx, ::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::cpp2::MyI32> const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_func(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  ServiceAsyncProcessor(::apache::thrift::ServiceHandler<::cpp2::Service>* iface) :
      iface_(iface) {}
  ~ServiceAsyncProcessor() override {}
};

} // cpp2
