#ifndef __GENERIC_SOCKET_H_INCLUDED__
#define __GENERIC_SOCKET_H_INCLUDED__

#include <string>

namespace server {
namespace net {

  class generic_socket {
    public:
      void cleanup();
      generic_socket(int type, int protocol);
      generic_socket(int fd);
      void set_addr_port(std::string bind_hostname, int bind_port);
      int reuse();
    protected:
      int bound_;
      int socket_descriptor_;
  };

}
}

#endif
