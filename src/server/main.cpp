#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <boost/asio.hpp>
#include "server_lib/asio_kcp_log.hpp"
#include "server.hpp"

int main(int argc, char* argv[])
{
    try
    {
        // Check command line arguments.
        if (argc != 3)
        {
            std::cerr << "Usage: ./server <address> <port>\n";
            std::cerr << "  For IPv4, try:\n";
            std::cerr << "    ./server 0.0.0.0 9090\n";
            std::cerr << "  For IPv6, try:\n";
            std::cerr << "    ./server 0::0 9090\n";
            return 1;
        }

        AK_INFO_LOG << "start" << std::endl;

        // Initialise the server.
        server s(argv[1], argv[2]);

        // Run the server until stopped.
        s.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
