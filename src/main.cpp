#include <signal.h>

#include "main.hpp"
#include <generic_tcp_server.hpp>
#include <argument_parser.hpp>
#include <bad_args.hpp>
#include <helper.hpp>
#include <echo_handler.hpp>

using namespace std;

server::generic_tcp_server* global_server;
int keep_running = 1;

void register_signal_handlers();
void shutdown_server(int);

int main (int argc, char **argv)
{
  register_signal_handlers();

  try {
    util::argument_parser ap(argc, argv);
    util::config config = ap.get_config();

    server::generic_tcp_server gts(ap.get_config());
    global_server = &gts;
    global_server->run();

    return 0;
  } catch (util::bad_args &e) {
    util::helper().print(e.what(), argv[0]);
    return -1;
  }
}

void register_signal_handlers()
{
  signal(SIGINT, shutdown_server);  
  signal(SIGFPE, shutdown_server);  
  signal(SIGILL, shutdown_server);  
  signal(SIGABRT, shutdown_server);  
  signal(SIGSEGV, shutdown_server);  
  signal(SIGTERM, shutdown_server);  
}

void shutdown_server(int param)
{
  global_server->shutdown();
}
