C_FLAGS=-std=c++11 -Wall -Wextra
SRCS=$(wildcard src/*.cpp)
HEADERS=$(wildcard src/*.hpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: A6

A6: $(OBJS)
	g++ $(OBJS) -o main 

%.o: %.cpp $(HEADERS)
	g++ $(C_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)
