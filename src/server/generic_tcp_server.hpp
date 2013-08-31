#include <epoll_event_listener.hpp>
#include <tcp_server_socket.hpp>
#include <config.hpp>

namespace server {

  class generic_tcp_server {
    public:
      explicit generic_tcp_server (util::config config);
      ~generic_tcp_server();
      void run();
      void shutdown();
    private:
      util::config config_;
      int keep_running;
      net::tcp_server_socket* tss_;
  };

}
