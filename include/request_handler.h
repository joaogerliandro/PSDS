#pragma once

#include <common.h>
#include <service_handler.h>

using namespace nlohmann;

namespace PSDS
{
    class RequestHandler
    {
        public:
            static json process_request(std::string request)
            {
                json request_json = json::parse(request);

                json head = request_json["Head"];
                json body = request_json["Body"];

                json processed_data = process_data(head, body);

                return processed_data;
            }

            static json process_data(json head_json, json body_json)
            {
                json processed_data;

                ServiceType requested_service = head_json["ServiceType"];

                switch(requested_service)
                {
                    case ServiceType::CreateOrder:
                        processed_data = ServiceHandler::create_order(body_json);
                        break;
                    case ServiceType::GetOrderList:
                        processed_data = ServiceHandler::get_order_list(body_json);
                        break;
                    case ServiceType::ConfirmOrder:
                        processed_data = ServiceHandler::confirm_order(body_json);
                        break;
                    case ServiceType::CancelOrder:
                        processed_data = ServiceHandler::cancel_order(body_json);
                        break;
                    case ServiceType::ProcessOrder:
                        processed_data = ServiceHandler::process_order(body_json);
                        break;
                    default:
                        processed_data = ServiceHandler::process_default_error();
                        break;
                }

                return processed_data;
            }
    };
}