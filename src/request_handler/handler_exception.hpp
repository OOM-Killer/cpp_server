namespace request_handler {

  class handler_exception: public std::exception
  {
    public:
      enum cmd_e {
        CONN_CLOSE,
        CMD_QUIT,
        CMD_DIE
      };
      handler_exception(handler_exception::cmd_e);
      handler_exception::cmd_e get_cmd();
    private:
      cmd_e cmd_;
  };
}
