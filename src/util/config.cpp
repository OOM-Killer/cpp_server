#include <iostream>

#include <config.hpp>

namespace util {

  config::config(std::string bind_hostname, int bind_port, int thread_pool_size) {
    bind_hostname_ = bind_hostname;
    bind_port_ = bind_port;
    thread_pool_size_ = thread_pool_size;
  }

  config::config() {}

  void config::print_config() {
    std::cout << "bind_hostname: " << bind_hostname_ << "\n";
    std::cout << "bind_port: " << bind_port_ << "\n";
    std::cout << "thread_pool_size: " << thread_pool_size_ << "\n";
  }

  std::string config::get_bind_hostname() {
    return bind_hostname_;
  }

  int config::get_bind_port() {
    return bind_port_;
  }

  int config::get_thread_pool_size() {
    return thread_pool_size_;
  }

}
