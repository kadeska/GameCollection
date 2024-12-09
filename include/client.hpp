#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <boost/asio.hpp>
#include <string>

class Client {
public:
    Client(boost::asio::io_context& client_io_context, const std::string& host, short port);
    void writeMessage(const std::string& message);
    int start_client();
    boost::asio::io_context client_io_context;
    

private:
    void connectToServer(const std::string& host, short port);
    void readMessage();

    boost::asio::ip::tcp::socket socket_;
    std::string buffer_;
};

#endif // CLIENT_HPP
