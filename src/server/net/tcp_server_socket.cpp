#include <string.h>
#include <errno.h>

#include <iostream>

#include <generic_socket.hpp>
#include <tcp_server_socket.hpp>
#include <socket_exception.hpp>

namespace server {
  namespace net {

    tcp_server_socket::tcp_server_socket()
      : generic_socket(SOCK_STREAM, IPPROTO_TCP) {
      }

    void tcp_server_socket::set_listen(int queue_len) {
      if (listen(socket_descriptor_, queue_len) < 0) {
        throw socket_exception("Can't bind");
      }
      std::cout << "--- listening\n";
    }

    communicating_tcp_socket tcp_server_socket::accept() {
      int new_conn;

      if ((new_conn = ::accept(socket_descriptor_, NULL, 0)) < 0) {
        throw socket_exception(strerror(errno));
      }

      return communicating_tcp_socket(new_conn);
    }

    void tcp_server_socket::set_addr_port(std::string bind_hostname, int bind_port) {
      hostent *host;

      if ((host = gethostbyname(bind_hostname.c_str())) == NULL) {
        throw socket_exception("Unable to lookup hostname");
      }

      memset(&local_addr_, 0, sizeof(sockaddr_in));

      local_addr_.sin_family = AF_INET;
      local_addr_.sin_addr.s_addr = *((unsigned long *) host->h_addr_list[0]);
      local_addr_.sin_port = htons(bind_port);

    }

    void tcp_server_socket::bind() {
      if (::bind(socket_descriptor_, (sockaddr*) &local_addr_, sizeof(sockaddr_in)) < 0)
      {
        throw socket_exception(strerror(errno));
      }

      bound_ = 1;
    }

    void tcp_server_socket::prepare_and_listen(std::string bind_hostname, int bind_port) {
      reuse();
      set_addr_port(bind_hostname, bind_port);
      bind();
      non_blocking();
      set_listen(5);
    }
  }
}
