cmake_minimum_required(VERSION 2.8)
project(project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen
    src
    $ENV{RUNTIME_PATH}/capicxx-core-runtime/include
    $ENV{RUNTIME_PATH}/capicxx-someip-runtime/include
    $ENV{RUNTIME_PATH}/vsomeip/interface
)

link_directories(
    $ENV{RUNTIME_PATH}/capicxx-core-runtime/build
    $ENV{RUNTIME_PATH}/capicxx-someip-runtime/build
    $ENV{RUNTIME_PATH}/vsomeip/build
)
add_executable(HelloWorldClient
	src/HelloWorldClient.cpp
	src-gen/v1/commonapi/helloWorlds/HelloWorldSomeIPProxy.cpp
	src-gen/v1/commonapi/helloWorlds/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-SomeIP vsomeip3)
add_executable(HelloWorldService
	src/HelloWorldService.cpp
	src/HelloWorldStubImpl.cpp
	src-gen/v1/commonapi/helloWorlds/HelloWorldSomeIPStubAdapter.cpp
	src-gen/v1/commonapi/helloWorlds/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-SomeIP vsomeip3)