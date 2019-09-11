CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g
COVERAGE = --coverage


all: ReallyLongInt

ReallyLongInt: ReallyLongInt.cpp ReallyLongInt.hpp
	$(CC) $(FLAGS) -o ReallyLongInt.exe ReallyLongInt.cpp

clean:
	rm *.o;
	rm ReallyLongInt.exe;

