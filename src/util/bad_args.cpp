#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <exception>

#include <bad_args.hpp>

namespace util {

  bad_args::bad_args(const char *message):
    msg_(message) {}

  bad_args::bad_args(const std::string message):
    msg_(message) {}

  const char* bad_args::what() const throw() {
    return msg_.c_str();
  }

}
