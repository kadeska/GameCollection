// server.cpp
/*
This is a basic server for a server/client program. Will be adding more 
functionality in the future. 
 */

/**
 * @file server.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-12-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "../include/server.hpp"
#include "../include/networking.hpp"
#include <iostream>

Server::Server(boost::asio::io_context& io_context, short port)
    : acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    acceptConnection();
}

void Server::acceptConnection() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
            if (!ec) {
                std::cout << "New client connected.\n";
                std::make_shared<Session>(std::move(socket))->start();
            }
            acceptConnection();
        });
}

int Server::start_server() {
    try {
        Server server(server_io_context, 1234);
        std::cout << "Server running on port 1234...\n";
        server_io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }
    return 0;
}