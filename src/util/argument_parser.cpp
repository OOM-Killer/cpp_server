#include <string.h>
#include <stdlib.h>

#include <config.hpp>
#include <bad_args.hpp>
#include <argument_parser.hpp>

namespace util {

  argument_parser::argument_parser(int argc, char **argv) {
    int i;

    if (argc < 4)
      throw bad_args("too few arguments");
    if (argc > 4)
      throw bad_args("too many arguments");
    for (i = 0; i < strlen(argv[2]); ++i) {
      if (!isdigit(argv[2][i]))
        throw bad_args("bind port has to be numeric");
    }
    for (i = 0; i < strlen(argv[3]); ++i) {
      if (!isdigit(argv[3][i]))
        throw bad_args("thread pool size has to be numeric");
    }

    bind_hostname_ = std::string(argv[1]);
    bind_port_ = atoi(argv[2]);
    thread_pool_size_ = atoi(argv[3]);
  }

  config argument_parser::get_config() {
    return config(bind_hostname_, bind_port_, thread_pool_size_);
  }
}
