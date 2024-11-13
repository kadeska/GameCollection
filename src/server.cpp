// server.cpp
/*
This is a basic server for a server/client program. Will be adding more 
functionality in the future. 
 */

#include "../include/networking.hpp"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int startServer() {
    try {
        // Set up an IO context and acceptor to listen for incoming connections
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Server is running on port 12345..." << std::endl;

        // Accept a new connection
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::cout << "Client connected!" << std::endl;

        // Read data from the client
        char data[1024];
        size_t length = socket.read_some(boost::asio::buffer(data));

        std::cout << "Received from client: " << std::string(data, length) << std::endl;

        // Send a response back to the client
        std::string response = "Hello from server!";
        boost::asio::write(socket, boost::asio::buffer(response));

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
