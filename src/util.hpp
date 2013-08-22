#include <iostream>
#include <string>
#include <exception>
#include <string.h>
#include <stdlib.h>

namespace util {

  class config {
    public:
      explicit config(std::string bind_hostname, int bind_port, int thread_pool_size);
      config();
      void print_config();

      std::string get_bind_hostname();
      int get_bind_port();
      int get_thread_pool_size();

    private:
      std::string bind_hostname_;
      int bind_port_;
      int thread_pool_size_;
  };

  class bad_args: public std::exception
  {
    public:
      explicit bad_args(const char *message); 
      explicit bad_args(const std::string message); 
      virtual ~bad_args() throw (){};
      virtual const char* what() const throw(); 

    private:
      std::string msg_;
  };

  class argument_parser {
    public:
      argument_parser(int argc, char **argv);  
      config get_config();

    private:
      int bind_port_;
      int thread_pool_size_;
      std::string bind_hostname_;
  };

  class helper {
    public:
      void print(const char *msg, const char *argv0);
  };

}
