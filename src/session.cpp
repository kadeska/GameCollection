#include "../include/session.hpp"
#include <iostream>

Session::Session(boost::asio::ip::tcp::socket socket)
    : socket_(std::move(socket)) {}

void Session::start() {
    readMessage();
}

void Session::readMessage() {
    auto self(shared_from_this());
    socket_.async_read_some(
        boost::asio::buffer(buffer_),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::string message(buffer_.data(), length);
                std::cout << "Received: " << message << std::endl;
                writeMessage("Echo: " + message);
            }
        });
}

void Session::writeMessage(const std::string& message) {
    auto self(shared_from_this());
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(message),
        [this, self](boost::system::error_code ec, std::size_t) {
            if (!ec) {
                readMessage();
            }
        });
}
