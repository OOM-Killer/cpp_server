#ifndef __REQUEST_HANDLER_GENERIC_HANDLER_H_DEFINED___
#define __REQUEST_HANDLER_GENERIC_HANDLER_H_DEFINED___

#include <communicating_tcp_socket.hpp>

namespace request_handler {

  class generic_handler {
    public:
      generic_handler();
      virtual void handle(server::net::communicating_tcp_socket socket);
    private:
      server::net::communicating_tcp_socket* socket_;
  };
}

#endif
