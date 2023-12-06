#include <server.h>

using namespace std::chrono_literals;
using namespace nlohmann;
using namespace PSDS;

int main() 
{
    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind("tcp://*:4444");

    for (;;) 
    {
        try
        { 
            zmq::message_t request;

            zmq::recv_result_t result = socket.recv(request, zmq::recv_flags::none);

            std::cout << "[SERVER-LOG]: Received Message: " << request.to_string() << std::endl;

            json processed_data = RequestHandler::process_request(request.to_string());

            std::this_thread::sleep_for(1s);

            std::string response = ResponseHandler::process_response(processed_data);

            socket.send(zmq::buffer(response), zmq::send_flags::none);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}