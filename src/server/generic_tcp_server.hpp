
#include <config.hpp>

namespace server {

  class generic_tcp_server {
    public:
      explicit generic_tcp_server (util::config config);
      void run();
    private:
      util::config config_;
  };

}
