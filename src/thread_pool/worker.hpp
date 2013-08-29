#ifndef ___THREAD_POOL_WORKER_H_DEFINED___
#define ___THREAD_POOL_WORKER_H_DEFINED___
#include <pool_keeper.hpp>

namespace thread_pool {

  class worker {
    public: 
      worker(thread_pool::pool_keeper&);
      void operator()();
    private:
      thread_pool::pool_keeper& pool_keeper_;
  };
}

#endif
