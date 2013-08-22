#include <iostream>
#include <string>
#include <exception>
#include <string.h>
#include <stdlib.h>
#include <config.hpp>
#include <bad_args.hpp>

namespace util {

  class argument_parser {
    public:
      argument_parser(int argc, char **argv);  
      config get_config();

    private:
      int bind_port_;
      int thread_pool_size_;
      std::string bind_hostname_;
  };
}
