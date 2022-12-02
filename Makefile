CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = CommonSub.o main.o Similarity.o

CommonSub.o: CommonSub.cpp CommonSub.hpp
	$(CXX) $(CXXFLAGS) -c CommonSub.cpp

main.o: main.cpp CommonSub.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Similarity.o: similarity.cpp similarity.hpp 
	$(CXX) $(CXXFLAGS) -c Similarity.cpp

main: ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean:
	rm ${OBJS} main

