#include "server.hpp"

namespace server {

  generic_tcp::generic_tcp(util::config config) {
    config.print_config();
  }

  void generic_tcp::run() {
    std::cout << "running\n";
  }

}
