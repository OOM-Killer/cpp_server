#include <string.h>
#include <generic_handler.hpp>
#include <communicating_tcp_socket.hpp>
#include <handler_exception.hpp>

namespace request_handler {

  generic_handler::generic_handler(){}

  void generic_handler::handle(server::net::communicating_tcp_socket socket) {
  }

  void generic_handler::check_commands(char* buffer, size_t len){
    handler_exception::cmd_e cmd;
    if (strncmp(buffer, "quit", 4) == 0) {
      cmd = handler_exception::CMD_QUIT;
      goto except;
    }
    if (strncmp(buffer, "die", 3) == 0) {
      cmd = handler_exception::CMD_DIE;
      goto except;
    }
    return;
except:
    socket_->cleanup();
    throw request_handler::handler_exception(cmd);
  }
}
