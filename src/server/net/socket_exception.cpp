#include <iostream>

#include <socket_exception.hpp>

namespace server {
namespace net{

  socket_exception::socket_exception(const char *message):
    msg_exception(message) {}

  socket_exception::socket_exception(const std::string message):
    msg_exception(message) {}
}
}
