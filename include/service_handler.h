#pragma once

#include <common.h>

using namespace nlohmann;

const std::string hostname = "aws.connect.psdb.cloud";
const std::string database = "limoserver";
const std::string username = "77kmrqos99we2eh5729k";
const std::string password = "pscale_pw_IDzNZYXreX4PcYFm9HnLA6g8whpcTbAoblejTjG3Gx0";

namespace PSDS
{
    class ServiceHandler
    {
        public:
            static json create_order(json body_json)
            {
                json processed_data;

                std::string client_name = body_json["ClientName"];
                std::string product = body_json["Product"];
                int32_t amount = body_json["Amount"];
                double value = body_json["Value"];
                std::string address = body_json["Address"];
                std::string tax_number = body_json["TaxNumber"];

                std::string query = "insert into OrderN values('" + client_name + "', '" + product + 
                "', " + std::to_string(amount) + ", " + std::to_string(value) + ", '" + address + "', '" + tax_number + "')";

                sql::mysql::MySQL_Driver *driver;
                sql::Connection *con;
                sql::Statement *stmt;
                sql::ResultSet *res;

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