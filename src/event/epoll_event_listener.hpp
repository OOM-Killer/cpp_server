#ifndef ___EVENT_EPOLL_EVENT_LISTENER_H_DEFINED___
#define ___EVENT_EPOLL_EVENT_LISTENER_H_DEFINED___

#include <sys/epoll.h>
#include <generic_handler.hpp>

namespace event {
  class epoll_event_listener {
    public:
      epoll_event_listener(int);
      enum subsystems {
        EPOLL
      };
      void listen();
      void add_listening_socket(int);
      void shutdown();
      void add_request_handler(request_handler::generic_handler*);
    private:
      void register_event(uint32_t, int);
      void del_fd(int);
      int keep_running_;
      int efd_;
      int sfd_;
      int maxevents_;
      struct epoll_event* events_;
      struct epoll_event event_;
      request_handler::generic_handler* event_handler_;
  };
}

#endif
