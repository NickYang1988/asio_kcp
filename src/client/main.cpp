#include <string>
#include <iostream>
#include <boost/asio.hpp>

#include "client_with_asio.hpp"

using namespace asio_kcp;
using boost::asio::ip::tcp;

enum
{
    max_length = 1024
};

void test_kcp(boost::asio::io_service& io_service, const int port_bind_to, const char* ip, const int port,
    size_t test_msg_size, const int number_of_client)
{
    std::map<int, client_with_asio*> client_map;
    // multi client
    for (int i = port_bind_to; i < port_bind_to + number_of_client; i++)
    {
        client_map.insert(std::make_pair(i, new client_with_asio(io_service, i, std::string(ip), port, test_msg_size)));
    }

    // single client
    //client_with_asio client(io_service, port_bind_to, std::string(ip), port, test_msg_size);
    io_service.run();

    for (auto& iter : client_map)
    {
        delete iter.second;
    }
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 6)
        {
            std::cerr << "Usage: ./client <port_bind_to> <connect_to_host> <connect_to_port> <test_msg_lenth> "
                         "<number_of_client>\n";
            std::cerr << "./client 9091 127.0.0.1 9090 16 100\n";
            return 1;
        }

        boost::asio::io_service io_service;
        test_kcp(io_service, std::atoi(argv[1]), argv[2], std::atoi(argv[3]), std::atoi(argv[4]), std::atoi(argv[5]));
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
