#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <iostream>
#include <thread>

#include <msg_exception.hpp>
#include <worker.hpp>
#include <epoll_event_listener.hpp>


namespace event {

  void epoll_event_listener::dispatcher(int fd) {
    std::cout << "event to dispatch in thread " << std::this_thread::get_id() << "\n";
  }

  epoll_event_listener::epoll_event_listener(int maxevents) {
    maxevents_ = maxevents;
    keep_running_ = 1;
    efd_ = epoll_create1(0);
    if (efd_ == -1)
      throw util::msg_exception(strerror(errno));
    events_ = (struct epoll_event*) calloc(maxevents, sizeof(struct epoll_event));
  }

  void epoll_event_listener::add_listening_socket(int sfd) {
    sfd_ = sfd;
    register_event(EPOLLIN | EPOLLET, sfd_);
  }

  void epoll_event_listener::register_event(uint32_t events, int fd) {

    event_.data.fd = fd;
    event_.events = events;
    epoll_ctl(efd_, EPOLL_CTL_ADD, fd, &event_);
  }

  void epoll_event_listener::shutdown() {
    std::cout << "shutting down\n";
    keep_running_ = 0;
  }

  void epoll_event_listener::listen() {
    int n, i, newfd;

    while (keep_running_ == 1) {
      n = epoll_wait(efd_, events_, maxevents_, -1);

      for (i=0; i<n; i++) {
        if (events_[i].data.fd == sfd_) {
          newfd = accept(sfd_, NULL, NULL);
          register_event(EPOLLIN | EPOLLET, newfd);
          std::cout << "event on listening socket at thread " << std::this_thread::get_id() << "\n";
        } else {
          dispatcher(events_[i].data.fd);
        }
      }
    }
  }

  void epoll_event_listener::del_fd(int fd) {}
}
