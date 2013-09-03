CC=g++
LDFLAGS=-pthread
PROFILEFLAGS=-pg
OPTFLAGS=
CFLAGS=-c -Wall -Werror -Isrc/util -Isrc/server -Isrc -Isrc/server/net -Isrc/request_handler -Isrc/event -Isrc/thread_pool -std=gnu++0x -pthread
SOURCES=src/main.cpp src/server/net/generic_socket.cpp src/server/generic_tcp_server.cpp src/server/net/socket_exception.cpp src/server/net/tcp_server_socket.cpp src/util/argument_parser.cpp src/util/msg_exception.cpp src/util/bad_args.cpp src/util/config.cpp src/util/helper.cpp src/server/net/communicating_tcp_socket.cpp src/request_handler/echo_handler.cpp src/request_handler/generic_handler.cpp src/request_handler/strlen_handler.cpp src/request_handler/handler_exception.cpp src/event/epoll_event_listener.cpp src/thread_pool/pool_keeper.cpp src/thread_pool/worker.cpp src/thread_pool/worker_config.cpp src/thread_pool/shared_status.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=server

all: $(SOURCES) $(EXECUTABLE)

debug: OPTFLAGS += -g -ggdb -O0
debug: all

release: OPTFLAGS += -O3
release: all

profile: OPTFLAGS += -pg
profile: all

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OPTFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

clean: 
	find . -name "*.o" -exec rm {} \;
	rm -f server

.cpp.o:
	$(CC) $(OPTFLAGS) $(CFLAGS) $< -o $@
