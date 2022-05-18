# LogRush
A log-rush logging client for c++

## Install
Todo CMake install
Todo conan install

## Usage
### include in CMake
add the following lines to yout CMakeLists.txt
```cmake
find_package(logrush)
⋮
# in your target_link_libraries
target_link_libraries(<TARGET> logrush::logrush) 
```
### creating an LogRushClient
```c++
#include <logrush/logrush.h>
⋮
logrush::LogRushClient client = logrush::LogRushClient("<server address>");
```
### register log stream:
```c++
// Batch Stream
auto stream = client.register_stream("<Stream Name>", 5 /* Batch size */, "" /* id */, ""/* key */); 

// Basic Stream
auto stream = client.register_stream("<Stream Name>", "" /* id */, ""/* key */);
```
id and key should be empty strings except you want to reuse the stream

### log
```c++
stream.log("<message>");
```
### unregister log stream
```c++
client.unregister(stream);
```

## Examples

in the examples directory you can find two simple programms which use the logrush lib.

## Spdlog

this [repository](https://github.com/log-rush/cpp-client/tree/main/examples/spdlog/) contains two logging sinks for the spdlog library one for basic logging and one for batched logging.