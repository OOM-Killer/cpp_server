#include "server.hpp"
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>


namespace server {

  socket_exception::socket_exception(const char *message):
    msg_(message) {}

  socket_exception::socket_exception(std::string message):
    msg_(message) {}

  const char* socket_exception::what() const throw() {
    return msg_.c_str();
  }

  generic_socket::generic_socket(int type, int protocol) {
    std::cout << "creating socket\n";
    socket_descriptor = socket(PF_INET, type, protocol);
  }

  void generic_socket::set_addr_port(std::string bind_hostname, int bind_port) {
    sockaddr_in local_addr;
    hostent *host;

    if ((host = gethostbyname(bind_hostname.c_str())) == NULL) {
      throw socket_exception("Unable to lookup hostname");
    }

    memset(&local_addr, 0, sizeof(sockaddr_in));

    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = *((unsigned long *) host->h_addr_list[0]);
    local_addr.sin_port = htons(bind_port);

    if (bind(socket_descriptor, (sockaddr*) &local_addr, sizeof(sockaddr_in)) < 0)
    {
      throw socket_exception(strerror(errno));
    }
  }

  tcp_server_socket::tcp_server_socket(std::string bind_hostname, int bind_port)
  : generic_socket(SOCK_STREAM, IPPROTO_TCP) {
    set_addr_port(bind_hostname, bind_port);
  }

  void tcp_server_socket::set_listen(int queue_len) {
    if (listen(socket_descriptor, queue_len) < 0) {
      throw socket_exception("Can't bind");
    }
  }

  generic_tcp_server::generic_tcp_server(util::config config):
    config_(config) {}

  void generic_tcp_server::run() {
    std::cout << "starting\n";
    tcp_server_socket tss(config_.get_bind_hostname(), config_.get_bind_port());
    tss.set_listen(3);
  }

}
