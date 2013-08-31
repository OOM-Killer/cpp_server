#include <thread>
#include <iostream>
#include <exception>

#include <epoll_event_listener.hpp>
#include <worker.hpp>
#include <pool_keeper.hpp>

namespace thread_pool {

  worker::worker(thread_pool::pool_keeper& pool_keeper, int socket_fd)
  : socket_fd_(socket_fd), 
    pool_keeper_(pool_keeper) {
    event_listener_ = new event::epoll_event_listener(5);
  }

  worker::~worker() {
    //delete event_listener_;
  }

  void worker::operator()() {
    std::cout << "operating, thread " << std::this_thread::get_id()  << "\n";

    try {
      listen();
    } catch (std::exception &e) {
      std::cout << "caught exception '" << e.what() << "'\n";
    }

    std::cout << "worker finished, stopping now\n";
  }

  void worker::listen() {
    event_listener_->add_listening_socket(socket_fd_);
    event_listener_->listen();
  }
}
