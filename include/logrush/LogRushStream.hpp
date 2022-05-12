#pragma once

#include <string>
#include <vector>

namespace logrush
{
    class BasicLogStream {
    public:
        BasicLogStream(std::string url, std::string id, std::string key);
        ~BasicLogStream() {}

        void log(std::string log);

        std::string url;
        std::string id;
        std::string key;
    };

    class BatchLogStream {
    public:
        BatchLogStream(std::string url, std::string id, std::string key, size_t batch_size);
        ~BatchLogStream() {}

        void log(std::string log);
        void flush();
        
        std::string url;
        std::string id;
        std::string key;
    private:
        size_t batch_size;
        int pos = 1;
        std::vector<std::pair<uint64_t, std::string>> logs;
    };
} // namespace logrush
