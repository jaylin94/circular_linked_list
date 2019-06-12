CXX = g++
CXXFLAGS = -std=c++11 -g
OBJS = menu.o queueNode.o queue.o linked.o
SRCS = menu.cpp queueNode.cpp queue.cpp linked.cpp
HEADERS = menu.hpp queueNode.hpp queue.hpp

linked:${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o linked

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o linked

zip:
	zip -D circular_linked_list.zip *.cpp *.hpp *.pdf makefile

val:
	valgrind --leak-check=full ./linked