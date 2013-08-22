#include <string>

#ifndef __UTIL_CONFIG_H_INCLUDED__
#define __UTIL_CONFIG_H_INCLUDED__

namespace util {

  class config {
    public:
      explicit config(std::string bind_hostname, int bind_port, int thread_pool_size);
      config();
      void print_config();

      std::string get_bind_hostname();
      int get_bind_port();
      int get_thread_pool_size();

    private:
      std::string bind_hostname_;
      int bind_port_;
      int thread_pool_size_;
  };
}

#endif
