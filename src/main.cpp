#include "main.hpp"
#include <generic_tcp_server.hpp>
#include <argument_parser.hpp>
#include <bad_args.hpp>
#include <helper.hpp>
#include <echo_handler.hpp>

using namespace std;

int main (int argc, char **argv)
{
  try {
    util::argument_parser ap(argc, argv);
    util::config config = ap.get_config();

    //config.set_handler(handler);
   
    server::generic_tcp_server gts(ap.get_config());
    gts.run();
    return 0;
  } catch (util::bad_args &e) {
    util::helper().print(e.what(), argv[0]);
    return -1;
  }
}