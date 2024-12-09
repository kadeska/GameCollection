#ifndef SERVER_HPP
#define SERVER_HPP

#include <boost/asio.hpp>
#include <memory>
#include "session.hpp"

class Server {
public:
    Server(boost::asio::io_context& io_context, short port);
    int start_server();
    boost::asio::io_context server_io_context;

private:
    void acceptConnection();

    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif // SERVER_HPP
