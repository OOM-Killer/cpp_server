#include <iostream>

#include <config.hpp>
#include <generic_socket.hpp>
#include <tcp_server_socket.hpp>
#include <generic_tcp_server.hpp>
#include <strlen_handler.hpp>
#include <handler_exception.hpp>

namespace server {

  generic_tcp_server::generic_tcp_server(util::config config):
    config_(config) {
      keep_running = 1;
    }

  void generic_tcp_server::run() {
    request_handler::strlen_handler handler;
    while (keep_running == 1) {
      try {
        handler.handle(tss_->accept());
      } catch (request_handler::handler_exception& e) {}
    }
    tss_->cleanup();
  }

  void generic_tcp_server::prepare_socket() {
    tss_ = new net::tcp_server_socket();
    tss_->prepare_and_listen(config_.get_bind_hostname(), config_.get_bind_port());
  }

  void generic_tcp_server::shutdown() {
    std::cout << "shutting down\n";
    keep_running = 0;
  }

}
