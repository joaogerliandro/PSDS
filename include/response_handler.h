#pragma once

#include <common.h>

using namespace nlohmann;

namespace PSDS
{
    class ResponseHandler
    {
        public:
            static std::string process_response(json processed_data)
            {
                return std::string("response");
            }
    };
}