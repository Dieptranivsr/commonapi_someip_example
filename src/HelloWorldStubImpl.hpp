// HelloWorldStubImpl.hpp
#ifndef HELLOWORLDSTUBIMPL_H_
#define HELLOWORLDSTUBIMPL_H_

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/helloWorlds/HelloWorldStubDefault.hpp>

class HelloWorldStubImpl: public v1_0::commonapi::helloWorlds::HelloWorldStubDefault {
public:
    HelloWorldStubImpl();
    virtual ~HelloWorldStubImpl();
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
    	std::string _name, sayHelloReply_t _reply);
};
#endif /* HELLOWORLDSTUBIMPL_H_ */