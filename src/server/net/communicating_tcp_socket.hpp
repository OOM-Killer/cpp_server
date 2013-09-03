
#ifndef __SERVER_COMMUNICATING_TCP_SOCKET_H_INCLUDED__
#define __SERVER_COMMUNICATING_TCP_SOCKET_H_INCLUDED__

#include <generic_socket.hpp>

namespace server {
namespace net {
  class communicating_tcp_socket : public generic_socket {
    public:
      explicit communicating_tcp_socket(int);
      explicit communicating_tcp_socket();
      void set_fd(int);
      int recv(char* buffer, int len);
      void send(const char* buffer, int len);
  };
}
}

#endif
