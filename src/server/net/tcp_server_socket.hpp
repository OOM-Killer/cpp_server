#ifndef __SERVER_NET_TCP_SERVER_SOCKET_H_INCLUDED__
#define __SERVER_NET_TCP_SERVER_SOCKET_H_INCLUDED__

#include <netdb.h>
#include <communicating_tcp_socket.hpp>

namespace server {
  namespace net {

    class tcp_server_socket : public generic_socket {
      public:
        explicit tcp_server_socket();
        void prepare_and_listen(std::string bind_hostname, int bind_port);
        communicating_tcp_socket accept();
      private:
        void bind();
        void set_listen(int queue_len = 5);
        void set_addr_port(std::string bind_hostname, int bind_port);
        sockaddr_in local_addr_;
    };

  }
}
#endif
