#ifndef ___THREAD_POOL_WORKER_H_DEFINED___
#define ___THREAD_POOL_WORKER_H_DEFINED___
#include <pool_keeper.hpp>
#include <epoll_event_listener.hpp>

namespace thread_pool {

  class worker {
    public: 
      worker(thread_pool::pool_keeper&, int);
      void operator()();
      ~worker();
    private:
      void listen();

      int socket_fd_;
      thread_pool::pool_keeper& pool_keeper_;
      event::epoll_event_listener* event_listener_;

  };
}

#endif
