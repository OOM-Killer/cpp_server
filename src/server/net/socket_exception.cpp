#include <iostream>

#include <socket_exception.hpp>

namespace server {
namespace net{

  socket_exception::socket_exception(const char *message):
    msg_(message) {}

  socket_exception::socket_exception(std::string message):
    msg_(message) {}

  const char* socket_exception::what() const throw() {
    return msg_.c_str();
  }
}
}
