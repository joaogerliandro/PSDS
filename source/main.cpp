#include <common.h>

using nlohmann::json;

int main() 
{
    using namespace std::chrono_literals;

    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind("tcp://*:4444");

    json json_test = 
    {
        {"string", "resultado"},
        {"int", 10},
        {"double", 2.0f}
    };

    const std::string data{json_test.dump()};

    for (;;) 
    {
        zmq::message_t request;

        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received: " << request.to_string() << std::endl;

        std::this_thread::sleep_for(1s);

        socket.send(zmq::buffer(data), zmq::send_flags::none);
    }

    return 0;
}