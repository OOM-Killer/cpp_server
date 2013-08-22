#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <exception>

#include <helper.hpp>

namespace util {

  void helper::print(const char *msg, const char *argv0) {
    std::cout << msg << "\n";
    std::cout << "syntax:\n";
    std::cout << argv0 << " <bind ip> <bind port> <thread pool size>\n";
  }
}
