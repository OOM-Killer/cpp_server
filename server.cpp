#include <iostream>
#include <string>
#include <exception>
#include "src/util.hpp"
#include "src/server.hpp"

using namespace std;

int main (int argc, char **argv)
{
  try {
    util::argument_parser ap(argc, argv);
    //ap.get_config().print_config();
    server::generic_tcp(ap.get_config());
    return 0;
  } catch (util::bad_args &e) {
    util::helper helper;
    helper.print(e.what(), argv[0]);
    return -1;
  }
}
