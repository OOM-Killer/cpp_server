#include <string>
#include <iostream>
#include "util.hpp"

namespace server {

  class generic_tcp {
    public:
      explicit generic_tcp (util::config config);
      void run();
  };

}
