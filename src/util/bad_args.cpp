#include <string>

#include <bad_args.hpp>

namespace util {

  bad_args::bad_args(const char *message):
    msg_exception(message) {}

  bad_args::bad_args(const std::string message):
    msg_exception(message) {}

}
