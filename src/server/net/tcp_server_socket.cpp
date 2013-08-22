#include <netdb.h>
#include <string.h>
#include <errno.h>

#include <iostream>

#include <generic_socket.hpp>
#include <tcp_server_socket.hpp>
#include <socket_exception.hpp>

namespace server {
namespace net {

  tcp_server_socket::tcp_server_socket(std::string bind_hostname, int bind_port)
  : generic_socket(SOCK_STREAM, IPPROTO_TCP) {
    set_addr_port(bind_hostname, bind_port);
  }

  void tcp_server_socket::set_listen(int queue_len) {
    if (listen(socket_descriptor, queue_len) < 0) {
      throw socket_exception("Can't bind");
    }
  }

  communicating_tcp_socket tcp_server_socket::accept() {
    int new_conn;

    if ((new_conn = ::accept(socket_descriptor, NULL, 0)) < 0) {
      throw socket_exception(strerror(errno));
    }

    return communicating_tcp_socket(new_conn);
  }
}
}
