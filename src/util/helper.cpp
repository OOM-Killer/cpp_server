#include <iostream>

#include <helper.hpp>

namespace util {

  void helper::print(const char *msg, const char *argv0) {
    std::cout << msg << "\n";
    std::cout << "syntax:\n";
    std::cout << argv0 << " <bind ip> <bind port> <thread pool size>\n";
  }
}
