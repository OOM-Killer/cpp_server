
#include <string.h>
#include <stdio.h>

#include <iostream>

#include <communicating_tcp_socket.hpp>
#include <strlen_handler.hpp>
#include <handler_exception.hpp>

namespace request_handler {

  void strlen_handler::handler_logic() {
    int output_len;

    output_len = snprintf(buffer_, 100, "your input is %i chars long\n", received_);
    socket_.send(buffer_, output_len + 1);
    std::cout << "input len: " << std::to_string(received_) << "\n";
  }

}
