#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>

#include <config.hpp>
#include <generic_socket.hpp>
#include <socket_exception.hpp>

namespace server {
  namespace net {

    generic_socket::generic_socket(int type, int protocol) {
      socket_descriptor_ = socket(PF_INET, type, protocol);
      bound_ = 0;
    }

    void generic_socket::cleanup() {
      close(socket_descriptor_);
    }

    void generic_socket::reuse() {
      int on = 1;

      if (bound_ != 0) 
        throw socket_exception("can't set reuse, socket is not bound yet");

      if ( setsockopt(socket_descriptor_, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on)) == -1)
        throw socket_exception(strerror(errno));
    }

    void generic_socket::non_blocking() {
      int flags;

      flags = fcntl(socket_descriptor_, F_GETFL);
      if (flags == -1)
        throw socket_exception(strerror(errno));

      flags |= O_NONBLOCK;

      if (fcntl(socket_descriptor_, F_SETFL, flags) == -1)
        throw socket_exception(strerror(errno));
    }
  }
}
