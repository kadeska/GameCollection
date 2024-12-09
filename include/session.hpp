#ifndef SESSION_HPP
#define SESSION_HPP

#include <boost/asio.hpp>
#include <memory>
#include <array>
#include <string>

class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(boost::asio::ip::tcp::socket socket);
    void start();

private:
    void readMessage();
    void writeMessage(const std::string& message);

    boost::asio::ip::tcp::socket socket_;
    std::array<char, 1024> buffer_;
};

#endif // SESSION_HPP
