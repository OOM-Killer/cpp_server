
namespace util {

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
}
