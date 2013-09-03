#ifndef __REQUEST_HANDLER_GENERIC_HANDLER_H_DEFINED___
#define __REQUEST_HANDLER_GENERIC_HANDLER_H_DEFINED___

#include <communicating_tcp_socket.hpp>

namespace request_handler {

  class generic_handler {
    public:
      enum status {
        QUIT,
        DIE,
        CONN_CLOSE,
        CONT
      };
      generic_handler();
      generic_handler::status handle();
      virtual void handler_logic();
      server::net::communicating_tcp_socket socket_;
    protected:
      char buffer_[100];
      int received_;
    private:
      enum cmd {
        CMD_QUIT,
        CMD_DIE,
        CMD_NONE
      };
      generic_handler::cmd check_commands();
  };
}

#endif
