#include <worker_config.hpp>
#include <pool_keeper.hpp>
#include <generic_handler.hpp>

namespace thread_pool {

  worker_config::worker_config(int server_fd, thread_pool::pool_keeper& pool_keeper, request_handler::generic_handler* request_handler) 
    : server_fd_(server_fd),
    pool_keeper_(pool_keeper),
    request_handler_(request_handler)
    { }

  int worker_config::get_server_fd() {
    return server_fd_;
  }

  thread_pool::pool_keeper& worker_config::get_pool_keeper() {
    return pool_keeper_;
  }

  request_handler::generic_handler* worker_config::get_request_handler() {
    return request_handler_;
  }
}
