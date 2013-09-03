#include <string.h>
#include <generic_handler.hpp>
#include <communicating_tcp_socket.hpp>
#include <handler_exception.hpp>

namespace request_handler {

  generic_handler::generic_handler(){
    socket_ = server::net::communicating_tcp_socket();
  }

  void generic_handler::handler_logic() {
  }

  generic_handler::status generic_handler::handle() {
    generic_handler::cmd cmd_ret;
    while (1) {
      received_ = socket_.recv(buffer_, 100);
      if (received_ == -1 && errno == EAGAIN)
        break;
      if (received_ == 0)
        return generic_handler::CONN_CLOSE;
      cmd_ret = check_commands(); 
      if (cmd_ret == generic_handler::CMD_NONE)
        handler_logic();
      else
        return (generic_handler::status) cmd_ret;
    }
    return generic_handler::CONT;
  }

  generic_handler::cmd generic_handler::check_commands() {
    if (received_ >= 4 && strncmp(buffer_, "quit", 4) == 0) {
      return generic_handler::CMD_QUIT;
    }
    if (received_ >= 3 && strncmp(buffer_, "die", 3) == 0) {
      return generic_handler::CMD_DIE;
    }
    return generic_handler::CMD_NONE;
  }
}
