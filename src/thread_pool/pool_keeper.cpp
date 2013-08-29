#include <pool_keeper.hpp>
#include <worker.hpp>

#include <iostream>
#include <thread>

namespace thread_pool {

  pool_keeper::pool_keeper(int pool_size) {
    int i;
    pool_size_ = pool_size;
    for (i=0; i<pool_size_; i++) {
      std::cout << "creating worker number " << i << "\n";
      workers_.push_back(std::thread(worker(*this)));
    }
    //thread_pool::worker worker1(*this);
    //std::thread t1 = std::thread(worker1);
    //workers_.push_back(worker1);
    //std::thread thread = std::thread(worker1);
    //workers_.push_back(std::thread(worker(*this)));
  }


}
