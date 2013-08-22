#include <communicating_tcp_socket.hpp>
#include <unistd.h>
#include <netdb.h>

#include <iostream>

#include <socket_exception.hpp>

namespace server {
namespace net {

    communicating_tcp_socket::communicating_tcp_socket(int fd)
    : generic_socket(SOCK_STREAM, IPPROTO_TCP) {
      sockdesc_ = fd;
    }

    int communicating_tcp_socket::recv(char* buffer, int len) {
      int received_len;
      received_len = ::recv(sockdesc_, buffer, len, 0);
      if (received_len < 0)
        throw server::net::socket_exception("error receiving data from socket");
      return received_len;
    }

    void communicating_tcp_socket::send(const char* buffer, int len) {
      if (::send(sockdesc_, buffer, len, 0) < 0) {
        throw server::net::socket_exception("error writing data to socket");
      }
    }

    void communicating_tcp_socket::cleanup() {
      close(sockdesc_);
      std::cout << "closing\n";
    }
}
}
