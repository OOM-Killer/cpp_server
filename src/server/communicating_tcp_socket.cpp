#include <communicating_tcp_socket.hpp>
#include <netdb.h>

namespace server {

    communicating_tcp_socket::communicating_tcp_socket(int fd)
    : generic_socket(SOCK_STREAM, IPPROTO_TCP) {
      socket_descriptor = fd;
    }

}
