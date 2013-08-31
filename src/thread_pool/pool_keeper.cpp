#include <unistd.h>

#include <pool_keeper.hpp>
#include <worker.hpp>

#include <algorithm>
#include <iostream>
#include <thread>

namespace thread_pool {

  pool_keeper::pool_keeper(int pool_size, int socket_fd) 
  : socket_fd_(socket_fd) {
    int i;
    pool_size_ = pool_size;
    for (i=0; i<pool_size_; i++) {
      workers_.push_back(std::thread(worker(*this, socket_fd_)));
    }
    sleep(120);
  }

}
