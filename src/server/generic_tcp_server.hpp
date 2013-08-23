
#include <config.hpp>

namespace server {

  class generic_tcp_server {
    public:
      explicit generic_tcp_server (util::config config);
      void run();
      void shutdown();
    private:
      util::config config_;
      int keep_running;
  };

}
