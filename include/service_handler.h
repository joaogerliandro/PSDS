#pragma once

#include <common.h>

using namespace nlohmann;

namespace PSDS
{
    class ServiceHandler
    {
        public:
            static json create_order(json body_json)
            {
                json processed_data;

                return processed_data;
            }

            static json get_order_list(json body_json)
            {
                json processed_data;

                return processed_data;
            }

            static json confirm_order(json body_json)
            {
                json processed_data;

                return processed_data;
            }

            static json cancel_order(json body_json)
            {
                json processed_data;

                return processed_data;
            }

            static json process_order(json body_json)
            {
                json processed_data;

                return processed_data;
            }
            
            static json process_default_error()
            {
                json processed_data;

                return processed_data;
            }
    };
}