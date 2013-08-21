#include "util.hpp"

namespace util {

  config::config(std::string bind_hostname, int bind_port, int thread_pool_size) {
    bind_hostname_ = bind_hostname;
    bind_port_ = bind_port;
    thread_pool_size_ = thread_pool_size;
  }

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

  bad_args::bad_args(const char *message):
    msg_(message) {}

  bad_args::bad_args(const std::string message):
    msg_(message) {}

  const char* bad_args::what() const throw() {
    return msg_.c_str();
  }

  argument_parser::argument_parser(int argc, char **argv) {
    int i;

    if (argc < 4)
      throw bad_args("too few arguments");
    if (argc > 4)
      throw bad_args("too many arguments");
    for (i = 0; i < strlen(argv[2]); ++i) {
      if (!isdigit(argv[2][i]))
        throw bad_args("bind port has to be numeric");
    }
    for (i = 0; i < strlen(argv[3]); ++i) {
      if (!isdigit(argv[3][i]))
        throw bad_args("thread pool size has to be numeric");
    }

    bind_hostname_ = std::string(argv[1]);
    bind_port_ = atoi(argv[2]);
    thread_pool_size_ = atoi(argv[3]);
  }

  config argument_parser::get_config() {
    return config(bind_hostname_, bind_port_, thread_pool_size_);
  }

  void helper::print(const char *msg, const char *argv0) {
    std::cout << msg << "\n";
    std::cout << "syntax:\n";
    std::cout << argv0 << " <bind ip> <bind port> <thread pool size>\n";
  }
}
