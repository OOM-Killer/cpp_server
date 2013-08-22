#include <netdb.h>
#include <string.h>
#include <errno.h>

#include <iostream>

#include <config.hpp>
#include <generic_socket.hpp>
#include <socket_exception.hpp>

namespace server {

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

}
