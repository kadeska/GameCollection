// client.cpp
/*
This is a basic client for a server/client program. Will be adding more 
functionality in the future. 
 */

/**
 * @file client.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-12-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "../include/client.hpp"
//#include "../include/networking.hpp"
#include <iostream>

Client::Client(boost::asio::io_context& client_io_context, const std::string& host, short port)
    : socket_(client_io_context) {
    connectToServer(host, port);
}

void Client::connectToServer(const std::string& host, short port) {
    boost::asio::ip::tcp::resolver resolver(socket_.get_executor());
    auto endpoints = resolver.resolve(host, std::to_string(port));
    boost::asio::async_connect(
        socket_,
        endpoints,
        [this](boost::system::error_code ec, const boost::asio::ip::tcp::endpoint&) {
            if (!ec) {
                std::cout << "Connected to server.\n";
            } else {
                std::cerr << "Connection failed: " << ec.message() << std::endl;
            }
        });
}

void Client::writeMessage(const std::string& message) {
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(message),
        [this](boost::system::error_code ec, std::size_t) {
            if (!ec) {
                readMessage();
            }
        });
}

void Client::readMessage() {
    boost::asio::async_read_until(
        socket_,
        boost::asio::dynamic_buffer(buffer_),
        '\n',
        [this](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::cout << "Server response: " << buffer_.substr(0, length);
                buffer_.erase(0, length);
            }
        });
}


int Client::start_client() {
    try {

        Client client(client_io_context, "127.0.0.1", 1234);

        std::thread t([&client_io_context]() { client_io_context.run(); });

        while (true) {
            std::string message;
            std::getline(std::cin, message);
            message += '\n';  // Add newline for server delimiter.
            client.writeMessage(message);
        }

        t.join();
    } catch (std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
    return 0;
}