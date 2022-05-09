#include "logrush/LogRushClient.h"

#include "logrush/http/http.h"
#include "logrush/LogRushStream.h"

#include <chrono>

namespace logrush
{
    LogRushClient::LogRushClient(std::string url) : url(url) {}

    LogRushClient::~LogRushClient() {}

    logrush::BasicLogStream LogRushClient::register_stream(std::string alias, std::string id, std::string key)
    {
        json b;
        b["alias"] = alias;
        if (id != "" && key != "")
        {
            b["id"] = id;
            b["key"] = key;
        }
        json ret = post(url + "/stream/register", b);

        auto i = ret.find("id");
        if (i->is_string())
            id = i->get<std::string>();

        auto k = ret.find("key");
        if (k->is_string())
            key = k->get<std::string>();

        return BasicLogStream(url, id, key);
    }

    logrush::BatchLogStream LogRushClient::register_stream(std::string alias, size_t batch_size, std::string id, std::string key)
    {
        json b;
        b["alias"] = alias;
        if (id != "" && key != "")
        {
            b["id"] = id;
            b["key"] = key;
        }
        json ret = post(url + "/stream/register", b);

        auto i = ret.find("id");
        if (i->is_string())
            id = i->get<std::string>();

        auto k = ret.find("key");
        if (k->is_string())
            key = k->get<std::string>();

        return BatchLogStream(url, id, key, batch_size);
    }

    void LogRushClient::unregister_stream(logrush::BasicLogStream stream)
    {
        json b;
        b["id"] = stream.id;
        b["key"] = stream.key;

        auto res = post(url + "/stream/unregister", b);
    }

    void LogRushClient::unregister_stream(logrush::BatchLogStream stream, bool force_log)
    {
        if (force_log)
            stream.flush();

        json b;
        b["id"] = stream.id;
        b["key"] = stream.key;

        auto res = post(url + "/stream/unregister", b);
    }
} // namespace logrush
