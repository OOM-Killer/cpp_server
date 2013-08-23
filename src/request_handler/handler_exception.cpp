#include <string>

#include <handler_exception.hpp>

namespace request_handler {

  handler_exception::handler_exception(handler_exception::cmd_e cmd):
  cmd_(cmd) { }

  handler_exception::cmd_e handler_exception::get_cmd() {
    return cmd_;
  }

}
