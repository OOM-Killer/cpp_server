
#include <string.h>
#include <stdio.h>

#include <iostream>

#include <communicating_tcp_socket.hpp>
#include <strlen_handler.hpp>
#include <handler_exception.hpp>

namespace request_handler {

  void strlen_handler::handle(server::net::communicating_tcp_socket socket) {
    char buffer[100];
    int received = 1;
    int output_len;

    socket_ = &socket;

    std::cout << "--- connection!\n";

    while (1) {
      received = socket_->recv(buffer, 100);

      if (received <= 0) {
        std::cout << "--- client closed conn\n";
        socket_->cleanup();
        return;
      }

      if (received > 4 && strncmp("quit", buffer, (size_t) 4) == 0) {
        std::cout << "--- client sent quit\n";
        socket_->cleanup();
        return;
      }

      output_len = snprintf(buffer, 100, "your input is %i chars long\n", received);
      socket_->send(buffer, output_len + 1);
      buffer[received] = (char) NULL;
      std::cout << "input len: " << received << "\n";
    } 
  }

}
