#ifndef ___THREAD_POOL_POOL_KEEPER_H_DEFINED___
#define ___THREAD_POOL_POOL_KEEPER_H_DEFINED___


#include <thread>
#include <vector>

namespace thread_pool {

  class pool_keeper {

    public:
      pool_keeper(int, int);
      void workers_listen(int);
    private:
      std::vector< std::thread > workers_;
      int pool_size_;
      int socket_fd_;
  };

}

#endif
