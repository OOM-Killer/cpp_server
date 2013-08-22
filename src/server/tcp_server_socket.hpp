#include <communicating_tcp_socket.hpp>

namespace server {

  class tcp_server_socket : public generic_socket {
    public:
      explicit tcp_server_socket(std::string bind_hostname, int bind_port);
      void set_listen(int queue_len = 5);
      communicating_tcp_socket accept();
  };
}
