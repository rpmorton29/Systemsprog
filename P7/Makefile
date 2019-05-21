 
CXX = g++ -Wall -std=c++11


SRC = $(wildcard *.cpp)
OBJECTS = $(SRC:.cpp=.o)


LIBRARY = -lcrypto 




all: $(OBJECTS) #$(LIBRARY)
	$(CXX) -o cmt $(OBJECTS) #$(LIBRARY)


clean:
	rm -f $(OBJECTS) cat



tools.o: tools.cpp
Params.o: Params.cpp Params.hpp tools.hpp
FileData.o: FileData.cpp FileData.hpp Params.hpp tools.hpp
Controller.o: Controller.cpp Controller.hpp Params.hpp tools.hpp
main.o: main.cpp Controller.hpp Params.hpp tools.hpp




