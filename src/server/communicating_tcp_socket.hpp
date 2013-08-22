
#ifndef __SERVER_COMMUNICATING_TCP_SOCKET_H_INCLUDED__
#define __SERVER_COMMUNICATING_TCP_SOCKET_H_INCLUDED__

#include <generic_socket.hpp>

namespace server {
  class communicating_tcp_socket : public generic_socket {
    public:
      explicit communicating_tcp_socket(int);
  };
}

#endif
