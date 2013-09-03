#ifndef __REQUEST_HANDLER_ECHO_H_DEFINED__
#define __REQUEST_HANDLER_ECHO_H_DEFINED__

#include <generic_handler.hpp>

namespace request_handler {

  class strlen_handler : public generic_handler {
    public:
      void handler_logic();
  };
}

#endif
