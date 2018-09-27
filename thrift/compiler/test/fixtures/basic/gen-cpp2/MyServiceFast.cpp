/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/MyServiceFast.h"
#include "src/gen-cpp2/MyServiceFast.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> MyServiceFastSvIf::getProcessor() {
  return std::make_unique<MyServiceFastAsyncProcessor>(this);
}

void MyServiceFastSvIf::ping() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("ping");
}

folly::Future<folly::Unit> MyServiceFastSvIf::future_ping() {
  return apache::thrift::detail::si::future(semifuture_ping(), getThreadManager());
}

folly::SemiFuture<folly::Unit> MyServiceFastSvIf::semifuture_ping() {
  return apache::thrift::detail::si::semifuture([&] { return ping(); });
}

void MyServiceFastSvIf::async_eb_ping(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_eb(this, std::move(callback), [this]() mutable { return future_ping(); });
}

void MyServiceFastSvIf::getRandomData(std::string& /*_return*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("getRandomData");
}

folly::Future<std::unique_ptr<std::string>> MyServiceFastSvIf::future_getRandomData() {
  return apache::thrift::detail::si::future(semifuture_getRandomData(), getThreadManager());
}

folly::SemiFuture<std::unique_ptr<std::string>> MyServiceFastSvIf::semifuture_getRandomData() {
  return apache::thrift::detail::si::semifuture_returning_uptr([&](std::string& _return) { getRandomData(_return); });
}

void MyServiceFastSvIf::async_eb_getRandomData(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<std::string>>> callback) {
  apache::thrift::detail::si::async_eb(this, std::move(callback), [this]() mutable { return future_getRandomData(); });
}

bool MyServiceFastSvIf::hasDataById(int64_t /*id*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("hasDataById");
}

folly::Future<bool> MyServiceFastSvIf::future_hasDataById(int64_t id) {
  return apache::thrift::detail::si::future(semifuture_hasDataById(id), getThreadManager());
}

folly::SemiFuture<bool> MyServiceFastSvIf::semifuture_hasDataById(int64_t id) {
  return apache::thrift::detail::si::semifuture([&] { return hasDataById(id); });
}

void MyServiceFastSvIf::async_eb_hasDataById(std::unique_ptr<apache::thrift::HandlerCallback<bool>> callback, int64_t id) {
  apache::thrift::detail::si::async_eb(this, std::move(callback), [this, id]() mutable { return future_hasDataById(id); });
}

void MyServiceFastSvIf::getDataById(std::string& /*_return*/, int64_t /*id*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("getDataById");
}

folly::Future<std::unique_ptr<std::string>> MyServiceFastSvIf::future_getDataById(int64_t id) {
  return apache::thrift::detail::si::future(semifuture_getDataById(id), getThreadManager());
}

folly::SemiFuture<std::unique_ptr<std::string>> MyServiceFastSvIf::semifuture_getDataById(int64_t id) {
  return apache::thrift::detail::si::semifuture_returning_uptr([&](std::string& _return) { getDataById(_return, id); });
}

void MyServiceFastSvIf::async_eb_getDataById(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<std::string>>> callback, int64_t id) {
  apache::thrift::detail::si::async_eb(this, std::move(callback), [this, id]() mutable { return future_getDataById(id); });
}

void MyServiceFastSvIf::putDataById(int64_t /*id*/, std::unique_ptr<std::string> /*data*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("putDataById");
}

folly::Future<folly::Unit> MyServiceFastSvIf::future_putDataById(int64_t id, std::unique_ptr<std::string> data) {
  return apache::thrift::detail::si::future(semifuture_putDataById(id, std::move(data)), getThreadManager());
}

folly::SemiFuture<folly::Unit> MyServiceFastSvIf::semifuture_putDataById(int64_t id, std::unique_ptr<std::string> data) {
  return apache::thrift::detail::si::semifuture([&] { return putDataById(id, std::move(data)); });
}

void MyServiceFastSvIf::async_eb_putDataById(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, int64_t id, std::unique_ptr<std::string> data) {
  apache::thrift::detail::si::async_eb(this, std::move(callback), [this, id, data = std::move(data)]() mutable { return future_putDataById(id, std::move(data)); });
}

void MyServiceFastSvIf::lobDataById(int64_t /*id*/, std::unique_ptr<std::string> /*data*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("lobDataById");
}

folly::Future<folly::Unit> MyServiceFastSvIf::future_lobDataById(int64_t id, std::unique_ptr<std::string> data) {
  return apache::thrift::detail::si::future(semifuture_lobDataById(id, std::move(data)), getThreadManager());
}

folly::SemiFuture<folly::Unit> MyServiceFastSvIf::semifuture_lobDataById(int64_t id, std::unique_ptr<std::string> data) {
  return apache::thrift::detail::si::semifuture([&] { return lobDataById(id, std::move(data)); });
}

void MyServiceFastSvIf::async_eb_lobDataById(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback, int64_t id, std::unique_ptr<std::string> data) {
  apache::thrift::detail::si::async_eb_oneway(this, std::move(callback), [this, id, data = std::move(data)]() mutable { return future_lobDataById(id, std::move(data)); });
}

const char* MyServiceFastAsyncProcessor::getServiceName() {
  return "MyServiceFast";
}

folly::Optional<std::string> MyServiceFastAsyncProcessor::getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) {
  return apache::thrift::detail::ap::get_cache_key(buf, protType, cacheKeyMap_);
}

void MyServiceFastAsyncProcessor::process(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(buf), protType, context, eb, tm);
}

bool MyServiceFastAsyncProcessor::isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) {
  return apache::thrift::detail::ap::is_oneway_method(buf, header, onewayMethods_);
}

std::unordered_set<std::string> MyServiceFastAsyncProcessor::onewayMethods_ {
  "lobDataById"
};
std::unordered_map<std::string, int16_t> MyServiceFastAsyncProcessor::cacheKeyMap_ {};
const MyServiceFastAsyncProcessor::BinaryProtocolProcessMap& MyServiceFastAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const MyServiceFastAsyncProcessor::BinaryProtocolProcessMap MyServiceFastAsyncProcessor::binaryProcessMap_ {
  {"ping", &MyServiceFastAsyncProcessor::process_ping<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"getRandomData", &MyServiceFastAsyncProcessor::process_getRandomData<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"hasDataById", &MyServiceFastAsyncProcessor::process_hasDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"getDataById", &MyServiceFastAsyncProcessor::process_getDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"putDataById", &MyServiceFastAsyncProcessor::process_putDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"lobDataById", &MyServiceFastAsyncProcessor::process_lobDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const MyServiceFastAsyncProcessor::CompactProtocolProcessMap& MyServiceFastAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const MyServiceFastAsyncProcessor::CompactProtocolProcessMap MyServiceFastAsyncProcessor::compactProcessMap_ {
  {"ping", &MyServiceFastAsyncProcessor::process_ping<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"getRandomData", &MyServiceFastAsyncProcessor::process_getRandomData<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"hasDataById", &MyServiceFastAsyncProcessor::process_hasDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"getDataById", &MyServiceFastAsyncProcessor::process_getDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"putDataById", &MyServiceFastAsyncProcessor::process_putDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"lobDataById", &MyServiceFastAsyncProcessor::process_lobDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
