#include <iostream>

#include <config.hpp>
#include <generic_socket.hpp>
#include <tcp_server_socket.hpp>
#include <generic_tcp_server.hpp>

namespace server {

  generic_tcp_server::generic_tcp_server(util::config config):
    config_(config) {}

  void generic_tcp_server::run() {
    std::cout << "starting\n";
    tcp_server_socket tss(config_.get_bind_hostname(), config_.get_bind_port());
    tss.set_listen(3);
    tss.accept();
  }

}
