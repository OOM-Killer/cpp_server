#include <msg_exception.hpp>

namespace server {
namespace net {

  class socket_exception: public util::msg_exception
  {
    public:
      explicit socket_exception(const char *message); 
      explicit socket_exception(const std::string message); 
  };

}
}
