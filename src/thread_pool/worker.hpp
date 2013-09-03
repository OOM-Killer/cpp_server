#ifndef ___THREAD_POOL_WORKER_H_DEFINED___
#define ___THREAD_POOL_WORKER_H_DEFINED___
#include <pool_keeper.hpp>
#include <epoll_event_listener.hpp>
#include <worker_config.hpp>
#include <shared_status.hpp>

namespace thread_pool {

  class worker {
    public: 
      worker(thread_pool::shared_status*);
      void operator()();
      ~worker();
    private:
      void listen();

      event::epoll_event_listener* event_listener_;
      thread_pool::worker_config* worker_conf_;

  };
}

#endif
