#include <msg_exception.hpp>

namespace util {

  class bad_args: public util::msg_exception
  {
    public:
      explicit bad_args(const char *message); 
      explicit bad_args(const std::string message); 
  };
}
