#include <iostream>
#include <chrono>
#include <thread>

#include <logrush/logrush.h>

int main()
{
    auto c = logrush::LogRushClient("http://127.0.0.1:7000");
    auto s = c.register_stream("C++ Batch Example", 5, "", "");

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    s.log("Hello World! 1");
    s.log("Hello World! 2");
    s.log("Hello World! 3");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    s.log("Hello World! 4");
    s.log("Hello World! 5");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    s.log("Hello World! 6");
    s.log("Hello World! 7");
    s.log("Hello World! 8");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    s.log("Hello World! 9");
    s.log("Hello World! 10");
    s.log("Hello World! 11");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    s.log("Hello World! 12");

    c.unregister_stream(s, true);

    return 0;
}
