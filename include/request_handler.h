#pragma once

#include <common.h>

using namespace nlohmann;

namespace PSDS
{
    class RequestHandler
    {
        public:
            static json process_request(std::string request)
            {
                json processed_data{
                    {"Data1", "Result1"},
                    {"Data2", "Result2"},
                    {"Data3", "Result3"}
                };

                return processed_data;
            }
    };
}