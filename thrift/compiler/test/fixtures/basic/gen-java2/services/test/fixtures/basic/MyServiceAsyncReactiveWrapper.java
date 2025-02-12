/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.thrift.client.*;
import java.util.*;

public class MyServiceAsyncReactiveWrapper 
    implements MyService.Reactive {
    private final MyService.Async _delegate;

    public MyServiceAsyncReactiveWrapper(MyService.Async _delegate) {
        
        this._delegate = _delegate;
    }

    @java.lang.Override
    public void dispose() {
        _delegate.close();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> ping() {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.ping());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<String> getRandomData() {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.getRandomData());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> sink(final long sink) {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.sink(sink));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> putDataById(final long id, final String data) {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.putDataById(id, data));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Boolean> hasDataById(final long id) {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.hasDataById(id));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<String> getDataById(final long id) {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.getDataById(id));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> deleteDataById(final long id) {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.deleteDataById(id));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> lobDataById(final long id, final String data) {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.lobDataById(id, data));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Set<Float>> invalidReturnForHack() {
        return com.facebook.thrift.util.FutureUtil.toMono(_delegate.invalidReturnForHack());
    }

}
