#ifndef __GENERIC_SOCKET_H_INCLUDED__
#define __GENERIC_SOCKET_H_INCLUDED__

#include <string>

namespace server {
namespace net {

  class generic_socket {
    public:
      generic_socket(int type, int protocol);
      generic_socket(int fd);
      void set_addr_port(std::string bind_hostname, int bind_port);
    protected:
      int socket_descriptor;
  };

}
}

#endif
