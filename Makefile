CC=g++
LDFLAGS=
DEBUGFLAGS=-g -ggdb -O0
PROFILEFLAGS=-pg
CFLAGS=-c -Wall -Werror -Isrc/util -Isrc/server -Isrc -Isrc/server/net -Isrc/request_handler
SOURCES=src/main.cpp src/server/net/generic_socket.cpp src/server/generic_tcp_server.cpp src/server/net/socket_exception.cpp src/server/net/tcp_server_socket.cpp src/util/argument_parser.cpp src/util/bad_args.cpp src/util/config.cpp src/util/helper.cpp src/server/net/communicating_tcp_socket.cpp src/request_handler/echo_handler.cpp src/request_handler/generic_handler.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=server

all: $(SOURCES) $(EXECUTABLE)

debug: $(SOURCES) $(EXECUTABLE)_debug

profile: $(SOURCES) $(EXECUTABLE)_profile

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(EXECUTABLE)_debug: $(OBJECTS)
	$(CC) $(DEBUGFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

$(EXECUTABLE)_profile: $(OBJECTS)
	$(CC) $(PROFILEFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

clean: 
	find . -name "*.o" -exec rm {} \;
	rm -f server server_profile server_debug

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
