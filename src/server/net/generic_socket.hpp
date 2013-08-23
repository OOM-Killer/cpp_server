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
      protected:
        void reuse();
        void non_blocking();
        int bound_;
        int socket_descriptor_;
    };

  }
}

#endif
