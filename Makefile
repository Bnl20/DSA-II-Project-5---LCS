CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = CommonSub.o main.o

CommonSub.o: CommonSub.cpp CommonSub.hpp
	$(CXX) $(CXXFLAGS) -c CommonSub.cpp

main.o: main.cpp CommonSub.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

main: ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean:
	rm ${OBJS} main

