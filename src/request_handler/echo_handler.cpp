#include <string.h>
#include <iostream>

#include <communicating_tcp_socket.hpp>
#include <echo_handler.hpp>

namespace request_handler {

  void echo_handler::handle(server::net::communicating_tcp_socket socket) {
    char buffer[100];
    int received = 1;

    socket_ = &socket;

    std::cout << "--- connection!\n";

    while (1) {
      received = socket_->recv(buffer, 100);

      if (received <= 0) {
        socket_->cleanup();
        return;
      }

      if (received > 4 && strncmp("quit", buffer, (size_t) 4)) {
        socket_->cleanup();
        return;
      }

      buffer[received] = (char) NULL;
      std::cout << "client: " << buffer;
      socket_->send(buffer, received);
    } 
  }
}
