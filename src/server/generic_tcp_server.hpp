#include <epoll_event_listener.hpp>
#include <tcp_server_socket.hpp>
#include <config.hpp>

namespace server {

  class generic_tcp_server {
    public:
      explicit generic_tcp_server (util::config config);
      void run();
      void shutdown();
    private:
      void prepare_socket();
      util::config config_;
      int keep_running;
      net::tcp_server_socket* tss_;
      event::epoll_event_listener* event_listener_;
  };

}
