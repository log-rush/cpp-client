#include "./http.h"

#include <curl/curl.h>

namespace logrush
{

    json post(std::string url, json body)
    {
        std::string readBuffer;
        struct curl_slist* header = NULL;
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();

        if (curl)
        {
            header = curl_slist_append(header, "Content-Type: application/json");

            std::string b = body.dump();
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, b.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, b.length());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK)
            {   
                auto j = json::parse(std::string("{ \"message\":\"" + std::string(curl_easy_strerror(res)) + "\"}"));
                return j;
            }

            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        std::string resb = readBuffer;

        auto j = json::parse(resb);
        return j;
    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
    }
} // namespace logrush
