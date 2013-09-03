#ifndef ___THREAD_POOL_WORKER_CONFIG_HPP_DEFINE___
#define ___THREAD_POOL_WORKER_CONFIG_HPP_DEFINE___

#include <pool_keeper.hpp>
#include <generic_handler.hpp>

namespace thread_pool {
  class worker_config {
    public:
      worker_config(int, thread_pool::pool_keeper&, request_handler::generic_handler*);

      int get_server_fd();
      thread_pool::pool_keeper& get_pool_keeper();
      request_handler::generic_handler* get_request_handler();

    private:
      int server_fd_;
      thread_pool::pool_keeper& pool_keeper_;
      request_handler::generic_handler* request_handler_;
  };
}


#endif
