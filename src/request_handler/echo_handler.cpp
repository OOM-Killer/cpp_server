#include <string.h>
#include <iostream>

#include <communicating_tcp_socket.hpp>
#include <echo_handler.hpp>

namespace request_handler {

  void echo_handler::handler_logic() {

    buffer_[received_] = (char) NULL;
    std::cout << "client: " << buffer_;
    socket_.send(buffer_, received_);
  }
}
