#include "logrush/LogRushStream.h"

#include "http/http.h"
#include <chrono>

namespace logrush
{
    BasicLogStream::BasicLogStream(std::string url, std::string id, std::string key)
        : url(url + "/log"), id(id), key(key)
    {
    }

    void BasicLogStream::log(std::string log)
    {
        json b;
        b["stream"] = id;
        b["log"] = log;
        b["timestamp"] = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        post(url, b);
    }

    BatchLogStream::BatchLogStream(std::string url, std::string id, std::string key, size_t batch_size)
        : url(url + "/batch"), id(id), batch_size(batch_size), logs(std::vector<std::pair<uint64_t, std::string>>()), key(key)
    {
        logs.resize(batch_size);
    }

    void BatchLogStream::log(std::string log)
    {
        std::pair<uint64_t, std::string> p{std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(), log};
        logs.at(pos - 1) = p;

        if (pos >= batch_size)
        {
            json b;
            b["logs"] = json::array();
            std::for_each(logs.begin(), logs.end(), [&](auto i)
                          {
                json l;
                l["log"] = i.second;
                l["timestamp"] = i.first;
                b["logs"].push_back(l); });
            b["stream"] = id;

            post(url, b);
            pos = 1;
        }
        else
            pos++;
    }

    void BatchLogStream::flush()
    {
        json b;
        b["logs"] = json::array();

        std::for_each_n(logs.begin(), pos - 1, [&](auto i)
                      {
                json l;
                l["log"] = i.second;
                l["timestamp"] = i.first;
                b["logs"].push_back(l); });
        b["stream"] = id;

        post(url, b);
    }
} // namespace logrush
