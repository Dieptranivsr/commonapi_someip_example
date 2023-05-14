* Before compiling
```
$ export RUNTIME_PATH=/home/dieptt3
$ ls ${RUNTIME_PATH}/capicxx-core-runtime/include
CommonAPI
```

## Generate code
* Get CommonAPI, SOME/IP Code Generator
```shell
~/project/cgen$ wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.2.0.1/commonapi_core_generator.zip
~/project/cgen$ wget https://github.com/COVESA/capicxx-someip-tools/releases/download/3.2.0.1/commonapi_someip_generator.zip
```

* Generate code (CommonAPI code with the commonapi-generator and CommonAPI SOMEIP code with the commonapi-someip-generator
```shell
~/project/build$ ./cgen/commonapi_core_generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/HelloWorld.fidl
```

```shell
~/project/build$ ./cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 -ll verbose ./fidl/HelloWorld.fdepl
```

## Terminal 1
```shell
~/project/build$ export VSOMEIP_CONFIGURATION_FILE=../fidl/vsomeip.json
~/project/build$ VSOMEIP_APPLICATION_NAME=service-sample ./HelloWorldService &
```

## Terminal 2
```shell
~/project/build$ VSOMEIP_APPLICATION_NAME=client-sample ./HelloWorldClient
```

![Screenshot 2023-05-14 153305](https://github.com/okulinich/sping/assets/69444682/8356743f-acfc-452e-8be6-735593236d0a)
