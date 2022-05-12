#pragma once

#include <string>

#include "logrush/json/json.hpp"

namespace logrush
{
    using json = nlohmann::json;

    json post(std::string, json body);

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
} // namespace logrush
