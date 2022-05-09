#include <iostream>
#include <chrono>
#include <thread>
#include <logrush/logrush.h>
#include <logrush/LogRushClient.h>

int main()
{
    auto c = logrush::LogRushClient("http://127.0.0.1:7000");
    auto s = c.register_stream("C++ Basic Example", "", "");

    s.log("Hello World!");

    c.unregister_stream(s);

    return 0;
}
