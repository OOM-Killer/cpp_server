#include <iostream>

#include <config.hpp>
#include <generic_socket.hpp>
#include <tcp_server_socket.hpp>
#include <generic_tcp_server.hpp>
#include <strlen_handler.hpp>
#include <handler_exception.hpp>

namespace server {

  generic_tcp_server::generic_tcp_server(util::config config):
    config_(config) {}

  void generic_tcp_server::run() {
    request_handler::strlen_handler handler;
    net::tcp_server_socket tss(config_.get_bind_hostname(), config_.get_bind_port());
    tss.set_listen(3);
    std::cout << "--- listening\n";
    while (1) {
      try {
        handler.handle(tss.accept());
      } catch (request_handler::handler_exception& e) {
        switch (e.get_cmd()) {
          case request_handler::handler_exception::CMD_DIE:
            std::cout << "--- dying\n";
            return;
          case request_handler::handler_exception::CMD_QUIT:
            std::cout << "--- client submitted cmd quit\n";
            break;
          case request_handler::handler_exception::CONN_CLOSE:
            std::cout << "--- client has closed connection\n";
            break;
        } 
      }
    }
  }

}
