#include "main.hpp"

using namespace std;

int main (int argc, char **argv)
{
  try {
    util::argument_parser ap(argc, argv);
    server::generic_tcp_server gts(ap.get_config());
    gts.run();
    return 0;
  } catch (util::bad_args &e) {
    util::helper().print(e.what(), argv[0]);
    return -1;
  }
}
