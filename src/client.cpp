// client.cpp
/*
This is a basic client for a server/client program. Will be adding more 
functionality in the future. 
 */

#include "../include/networking.hpp"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int startClient() {
    try {
        // Set up an IO context and connect to the server
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "12345");
        
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Send a message to the server
        std::string message = "Hello from client!";
        boost::asio::write(socket, boost::asio::buffer(message));

        // Read the response from the server
        char reply[1024];
        size_t reply_length = socket.read_some(boost::asio::buffer(reply));

        std::cout << "Received from server: " << std::string(reply, reply_length) << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
