#Put Makefile here! 
CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJS = main.o address.o credit_card.o person.o product.o transaction.o store.o

all: main.out

main.out: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.out

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests: main.out
	./main.out

clean:
	rm -f *.o main.out

.PHONY: all tests clean