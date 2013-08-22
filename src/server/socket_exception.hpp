
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

}
