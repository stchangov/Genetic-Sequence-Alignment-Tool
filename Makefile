CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
INCLUDEDIR = -I/opt/homebrew/Cellar/boost/1.86.0_2/include/ -I/opt/homebrew/Cellar/sfml/2.6.1/include/
LIBDIR = -L/opt/homebrew/Cellar/boost/1.86.0_2/lib/ -L/opt/homebrew/Cellar/sfml/2.6.1/lib/


DEPS = EDistance.hpp

OBJECTS = EDistance.o

PROGRAM = EDistance

.PHONY: all clean lint

all: $(PROGRAM) $(PROGRAM).a test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(INCLUDEDIR)

test : test.o $(PROGRAM).a
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIB)

$(PROGRAM).a : $(OBJECTS)
	ar rcs $@ $^

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIB)

clean:
	rm *.o $(PROGRAM) test $(PROGRAM).a

lint:
	cpplint *.cpp *.hpp
