# LogRush
A log-rush logging client for c++

## Install
Todo CMake install
Todo conan install

## Usage
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