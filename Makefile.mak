CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = CommSub.o main.o

GenData.o : CommSub.cpp CommSub.hpp
	$(CXX) $(CXXFLAGS) -c CommSub.cpp

main.o : main.cpp CommSub.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

main : ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean :
	rm ${OBJS} main

