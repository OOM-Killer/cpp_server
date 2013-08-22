#include <string.h>
#include <iostream>

#include <communicating_tcp_socket.hpp>
#include <echo_handler.hpp>

namespace request_handler {

  void echo_handler::handle(server::net::communicating_tcp_socket socket) {
    char buffer[100];
    int received = 1;
    std::cout << "--- connection!\n";

    do {
      received = socket.recv(buffer, 100);
      if (received > 0) {
        if (strncmp(buffer, "quit", 4) == 0){
          std::cout << "--- quit command\n";
          socket.cleanup();
          return;
        }
        buffer[received] = (char) NULL;
        std::cout << "client: " << buffer;
        socket.send(buffer, received);
      }
    } while (received > 0);
    std::cout << "--- client closed connection\n";
    socket.cleanup();
  }
}
