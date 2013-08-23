#ifndef ___SRC_UTIL_MSG_EXCEPTION_H_DEFINED___
#define ___SRC_UTIL_MSG_EXCEPTION_H_DEFINED___

#include <string>

namespace util {

  class msg_exception: public std::exception
  {
    public:
      explicit msg_exception(const char *message); 
      explicit msg_exception(const std::string message); 
      virtual ~msg_exception() throw (){};
      virtual const char* what() const throw(); 

    private:
      std::string msg_;
  };
}

#endif
