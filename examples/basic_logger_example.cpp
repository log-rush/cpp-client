#include <iostream>
#include <chrono>
#include <thread>
#include <logrush/logrush.h>
#include <logrush/LogRushClient.h>

int main()
{
    auto c = logrush::LogRushClient("http://127.0.0.1:7000");
    try
    {
        auto s = c.register_stream("C++ Basic Example", "", "");

        s.log("Hello World!");

        c.unregister_stream(s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
