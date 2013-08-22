#include <string>
#include <iostream>
#include "util.hpp"

namespace server {

  class socket_exception: public std::exception
  {
    public:
      explicit socket_exception(const char *message); 
      explicit socket_exception(const std::string message); 
      virtual ~socket_exception() throw (){};
      virtual const char* what() const throw(); 

    private:
      std::string msg_;
  };

  class generic_socket {
    public:
      generic_socket(int type, int protocol);
      void set_addr_port(std::string bind_hostname, int bind_port);
    protected:
      int socket_descriptor;
  };

  class tcp_server_socket : public generic_socket {
    public:
      explicit tcp_server_socket(std::string bind_hostname, int bind_port);
      void set_listen(int queue_len = 5);
  };

  class generic_tcp_server {
    public:
      explicit generic_tcp_server (util::config config);
      void run();
    private:
      util::config config_;
  };

}
