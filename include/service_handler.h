#pragma once

#include <common.h>

using namespace nlohmann;

std::string hostname = "127.0.0.1";
std::string database = "postgres";
std::string username = "postgres";
std::string password = "root";
std::string connection_string = "host=" + hostname + " dbname=" + database + " user=" + username + " password=" + password;

namespace PSDS
{
    class ServiceHandler
    {
        public:
            static json create_order(json body_json)
            {
                json processed_data;

                int8_t status = 0;
                std::string client_name = body_json["ClientName"];
                std::string tax_number = body_json["TaxNumber"];
                std::string product = body_json["Product"];
                int32_t amount = body_json["Amount"];
                double value = body_json["TotalValue"];
                std::string address = body_json["Address"];

                std::string query = "insert into Orders (Status, ClientName, TaxNumber, Product, Amount, TotalValue, Address) values(" + std::to_string(status) + ", '" + client_name + "', '" + tax_number + 
                "', '" + product + "', " + std::to_string(amount) + ", " + std::to_string(value) + ", '" + address + "')";

                PGconn *conn = PQconnectdb(connection_string.c_str());

                if (PQstatus(conn) != CONNECTION_OK) {
                    std::cerr << "Erro ao conectar ao banco de dados: " << PQerrorMessage(conn) << std::endl;
                    PQfinish(conn);

                    processed_data = json::parse(R"(
                        {
                            "Head": 
                            {
                                "Status": "NOK"
                            },
                            "Body":
                            {
                                "Message": "Falha na conexão com o servidor remoto ! Tente novamente outra hora."
                            }
                        }
                    )");

                    return processed_data;
                }

                PGresult *res = PQexec(conn, query.c_str());

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    std::cerr << "Erro ao executar o comando INSERT: " << PQerrorMessage(conn) << std::endl;
                    PQclear(res);
                    PQfinish(conn);

                    processed_data = json::parse(R"(
                        {
                            "Head": 
                            {
                                "Status": "NOK"
                            },
                            "Body":
                            {
                                "Message": "Falha ao criar pedido ! Tente novamente."
                            }
                        }
                    )");

                    return processed_data;
                }

                PQclear(res);
                PQfinish(conn);

                processed_data = json::parse(R"(
                    {
                        "Head": 
                        {
                            "Status": "OK"
                        },
                        "Body":
                        {
                            "Message": "Pedido criado com sucesso !"
                        }
                    }
                )");

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