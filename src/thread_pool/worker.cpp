#include <thread>
#include <iostream>
#include <exception>

#include <epoll_event_listener.hpp>
#include <worker.hpp>
#include <worker_config.hpp>
#include <pool_keeper.hpp>
#include <generic_handler.hpp>
#include <strlen_handler.hpp>
#include <echo_handler.hpp>

namespace thread_pool {

  worker::worker(thread_pool::shared_status* shared_status)
  : worker_conf_(
    new thread_pool::worker_config(shared_status->get_server_fd(), shared_status->get_pool_keeper(), new request_handler::strlen_handler())) {
    event_listener_ = new event::epoll_event_listener(5);
  }

  worker::~worker() { }

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
    event_listener_->add_listening_socket(worker_conf_->get_server_fd());
    event_listener_->add_request_handler(worker_conf_->get_request_handler());
    event_listener_->listen();
  }
}
