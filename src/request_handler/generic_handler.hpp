#ifndef __REQUEST_HANDLER_GENERIC_HANDLER_H_DEFINED___
#define __REQUEST_HANDLER_GENERIC_HANDLER_H_DEFINED___

#include <communicating_tcp_socket.hpp>

namespace request_handler {

  class generic_handler {
    public:
      generic_handler();
      void check_commands(char*, size_t);
      virtual void handle(server::net::communicating_tcp_socket socket);
    protected:
      server::net::communicating_tcp_socket* socket_;
  };
}

#endif
