#!/bin/bash


OUTPUT_FILE="server "
OBJECTS="main src/server src/util"
OBJECT_BUILD_CMD="g++ -c "
OBJECT_LINK_CMD="g++ -o ${OUTPUT_FILE} "

find . -name "*.gch" -exec rm {} \;
find . -name "*.o" -exec rm {} \;
rm ${OUTPUT_FILE}

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

find . -name "*.gch" -exec rm {} \;
find . -name "*.o" -exec rm {} \;
