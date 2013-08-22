#!/bin/bash

OUTPUT_FILE="server "
COMPILER_FLAGS=""
if [ "${1}" == "debug" ]
then
  COMPILER_FLAGS="${COMPILER_FLAGS} -g -ggdb "
  OUTPUT_FILE="server_debug "
fi

OBJECTS="main src/server/net/generic_socket src/server/generic_tcp_server src/server/net/socket_exception src/server/net/tcp_server_socket src/util/argument_parser src/util/bad_args src/util/config src/util/helper src/server/net/communicating_tcp_socket"
OBJECT_BUILD_CMD="g++ ${COMPILER_FLAGS} -c -Isrc/util -Isrc/server -Isrc -Isrc/server/net"
OBJECT_LINK_CMD="g++ ${COMPILER_FLAGS} -o ${OUTPUT_FILE} "


find . -name "*.gch" -exec rm {} \; 2> /dev/null
find . -name "*.o" -exec rm {} \; 2> /dev/null
rm ${OUTPUT_FILE} 2> /dev/null

echo "compiling"
for OBJECT in ${OBJECTS}
do
  CMD="${OBJECT_BUILD_CMD} -o ${OBJECT}.o ${OBJECT}.cpp"
  echo ${CMD}
  ${CMD}
done

OBJECT_STRING=""
for OBJECT in ${OBJECTS}
do
  OBJECT_STRING="${OBJECT_STRING} ${OBJECT}.o"
done

echo "linking"
CMD="${OBJECT_LINK_CMD} ${OBJECT_STRING}"
echo ${CMD}
${CMD}

find . -name "*.gch" -exec rm {} \; 2> /dev/null
find . -name "*.o" -exec rm {} \; 2> /dev/null
