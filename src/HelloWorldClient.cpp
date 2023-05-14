// HelloWorldClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/helloWorlds/HelloWorldProxy.hpp>

using namespace v1_0::commonapi::helloWorlds;

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "test";
    std::string connection = "client-sample";

    std::shared_ptr<HelloWorldProxy<>> myProxy = runtime->buildProxy<HelloWorldProxy>(domain, instance, connection);
    std::cout << "Checking availability!" << std::endl;

    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    const std::string name = "Bod";
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    while (true)
    {
        myProxy->sayHello(name, callStatus, returnMessage);
        if(CommonAPI::CallStatus::SUCCESS  != callStatus) {
            std::cerr << "Remote call failed\n";
            return -1;
        }
        std::cout << "Got message: '" << returnMessage << "'\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}