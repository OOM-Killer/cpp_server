#ifndef ___EVENT_EPOLL_EVENT_LISTENER_H_DEFINED___
#define ___EVENT_EPOLL_EVENT_LISTENER_H_DEFINED___

#include <sys/epoll.h>

namespace event {
  class epoll_event_listener {
    public:
      epoll_event_listener(int);
      enum subsystems {
        EPOLL
      };
      void del_fd(int);
      void listen();
      void register_event(uint32_t, int);
      void add_listening_socket(int);
      void dispatcher(int);
      void shutdown();
    private:
      int keep_running_;
      int efd_;
      int sfd_;
      int maxevents_;
      struct epoll_event* events_;
      struct epoll_event event_;
  };
}

#endif
