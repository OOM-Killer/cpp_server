#include <string>

#include <msg_exception.hpp>

namespace util {

  msg_exception::msg_exception(const char *message):
    msg_(message) {}

  msg_exception::msg_exception(const std::string message):
    msg_(message) {}

  const char* msg_exception::what() const throw() {
    return msg_.c_str();
  }

}
