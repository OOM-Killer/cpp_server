#ifndef ___THREAD_POOL_SHARED_STATUS_H_DEFINED___
#define ___THREAD_POOL_SHARED_STATUS_H_DEFINED___

#include <pool_keeper.hpp>

namespace thread_pool {

  class shared_status {
    public:
      shared_status(int, int, thread_pool::pool_keeper&);
      int get_keep_running();
      int get_server_fd();
      thread_pool::pool_keeper& get_pool_keeper();
    private:
      int keep_running_;
      int server_fd_;
      thread_pool::pool_keeper& pool_keeper_;
  };

}

#endif
