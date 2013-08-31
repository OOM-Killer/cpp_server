#include <iostream>

#include <config.hpp>
#include <generic_socket.hpp>
#include <tcp_server_socket.hpp>
#include <generic_tcp_server.hpp>
#include <strlen_handler.hpp>
#include <handler_exception.hpp>
#include <epoll_event_listener.hpp>
#include <pool_keeper.hpp>

namespace server {

  generic_tcp_server::generic_tcp_server(util::config config)
    : config_(config) {
      keep_running = 1;
      tss_ = new net::tcp_server_socket();
      tss_->prepare_and_listen(config_.get_bind_hostname(), config_.get_bind_port());
    }

  void generic_tcp_server::run() {
    thread_pool::pool_keeper pk(config_.get_thread_pool_size(), tss_->get_fd());
  }

  generic_tcp_server::~generic_tcp_server() {
    tss_->cleanup();
    delete tss_;
  }

  void generic_tcp_server::shutdown() {
  }

}
