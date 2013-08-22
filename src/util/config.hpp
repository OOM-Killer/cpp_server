
#ifndef __UTIL_CONFIG_H_INCLUDED__
#define __UTIL_CONFIG_H_INCLUDED__

#include <string>
#include <generic_handler.hpp>

namespace util {

  class config {
    public:
      explicit config(std::string bind_hostname, int bind_port, int thread_pool_size);
      config();
      void print_config();

      std::string get_bind_hostname();
      int get_bind_port();
      int get_thread_pool_size();
      void set_handler(request_handler::generic_handler* handler);
      request_handler::generic_handler* get_handler();

    private:
      request_handler::generic_handler* handler_;
      std::string bind_hostname_;
      int bind_port_;
      int thread_pool_size_;
  };
}

#endif
