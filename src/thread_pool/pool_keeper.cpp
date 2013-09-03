
#include <pool_keeper.hpp>
#include <worker.hpp>
#include <shared_status.hpp>

#include <algorithm>
#include <iostream>
#include <thread>

namespace thread_pool {

  pool_keeper::pool_keeper(int pool_size, int socket_fd) 
  : pool_size_(pool_size), 
    socket_fd_(socket_fd) {
    int i;
    thread_pool::shared_status shared_status = thread_pool::shared_status(socket_fd, 1, *this);
    
    for (i=0; i<pool_size_; i++) {
      workers_.push_back(std::thread(worker(&shared_status)));
    }
    while ( 1 ) {
      sleep(120);
    }
  }

}
