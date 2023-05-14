/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/helloWorlds/HelloWorldSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {
namespace helloWorlds {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createHelloWorldSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< HelloWorldSomeIPProxy>(_address, _connection);
}

void initializeHelloWorldSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.helloWorlds.HelloWorld:v1_0:test",
        0x1234, 0x5678, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.helloWorlds.HelloWorld:v1_0",
        &createHelloWorldSomeIPProxy);
}

INITIALIZER(registerHelloWorldSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeHelloWorldSomeIPProxy);
}

HelloWorldSomeIPProxy::HelloWorldSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection)
{
}

HelloWorldSomeIPProxy::~HelloWorldSomeIPProxy() {
    completed_.set_value();
}



void HelloWorldSomeIPProxy::sayHello(std::string _name, CommonAPI::CallStatus &_internalCallStatus, std::string &_message, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_name(_name, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >
    >::callMethodWithReply(
        *this,
        CommonAPI::SomeIP::method_id_t(0x80e8),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_name,
        _internalCallStatus,
        deploy_message);
    _message = deploy_message.getValue();
}

std::future<CommonAPI::CallStatus> HelloWorldSomeIPProxy::sayHelloAsync(const std::string &_name, SayHelloAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_name(_name, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    return CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >
    >::callMethodAsync(
        *this,
        CommonAPI::SomeIP::method_id_t(0x80e8),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_name,
        [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment > _message) {
            if (_callback)
                _callback(_internalCallStatus, _message.getValue());
        },
        std::make_tuple(deploy_message));
}

void HelloWorldSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> HelloWorldSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace helloWorlds
} // namespace commonapi
} // namespace v1