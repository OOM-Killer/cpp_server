#include <shared_status.hpp>

namespace thread_pool {
  
  shared_status::shared_status(int server_fd, int keep_running, thread_pool::pool_keeper& pool_keeper)
  : keep_running_(keep_running),
    server_fd_(server_fd),
    pool_keeper_(pool_keeper) {
  }

  int shared_status::get_server_fd() {
    return server_fd_;
  }

  int shared_status::get_keep_running() {
    return keep_running_;
  }

  thread_pool::pool_keeper& shared_status::get_pool_keeper() {
    return pool_keeper_;
  }

}
