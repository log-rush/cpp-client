#pragma once

#include <string>
#include <memory>

#include "logrush/LogRushStream.h"

namespace logrush
{
    class LogRushClient
    {
    public:
        LogRushClient(std::string url);
        ~LogRushClient();

        logrush::BasicLogStream register_stream(std::string alias, std::string id, std::string key);
        logrush::BatchLogStream register_stream(std::string alias, size_t batch_size, std::string id, std::string key);

        void unregister_stream(logrush::BasicLogStream stream);
        void unregister_stream(logrush::BatchLogStream stream, bool force_log);
    private:
        std::string url;
    };
} // namespace logrush
