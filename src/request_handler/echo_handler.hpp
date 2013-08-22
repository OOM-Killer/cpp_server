#ifndef __REQUEST_HANDLER_ECHO_H_DEFINED__
#define __REQUEST_HANDLER_ECHO_H_DEFINED__

#include <communicating_tcp_socket.hpp>
#include <generic_handler.hpp>

namespace request_handler {

  class echo_handler : public generic_handler {
    public:
      virtual void handle(server::net::communicating_tcp_socket socket);
  };
}

#endif
