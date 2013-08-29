#include <thread>
#include <iostream>

#include <worker.hpp>
#include <pool_keeper.hpp>

namespace thread_pool {

  worker::worker(thread_pool::pool_keeper& pool_keeper):
    pool_keeper_(pool_keeper) {
    std::cout << "hello from worker\n";
  }

  void worker::operator()() {
    std::cout << "operating\n";
    std::cout << "operating, thread " << std::this_thread::get_id()  << "\n";
  }
}
