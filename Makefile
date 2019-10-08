CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g

all: keygen decrypt encrypt

debug: rlidebug ntdebug

coverage: rlicoverage 

rlidebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
		$(CC) $(FLAGS) -o ReallyLongIntTest ReallyLongInt_TEST.cpp ReallyLongInt.o
		./ReallyLongIntTest

ntdebug: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
		$(CC) $(FLAGS) -o numberTheoryTest numberTheory_TEST.cpp numberTheory.o
		./numberTheoryTest

rlicoverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		$(CC) $(CFLAGE) --coverage ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		./a.out
		gcov ReallyLongInt_TEST.cpp
		gcov -f ReallyLongInt_TEST.cpp
		gcov -b ReallyLongInt_TEST.cpp

ntcoverage: numberTheory_TEST.cpp numberTheory.cpp ReallyLongInt.hpp
		$(CC) $(CFLAGE) --coverage numberTheory_TEST.cpp numberTheory.cpp ReallyLongInt.cpp

ReallyLongInt: ReallyLongInt.cpp
		$(CC) $(FLAGS) -o ReallyLongInt.exe ReallyLongInt.cpp

numberTheory: numberTheory.cpp
		$(CC) $(FLAGS) -o numberTheory.exe numberTheory.cpp

keygen: keygen.cpp ReallyLongInt.cpp numberTheory.cpp
		$(CC) $(FLAGS) -o keygen.exe keygen.cpp

encrypt: ReallyLongInt.cpp numberTheory.cpp
		$(CC) $(FLAGS) -o encrypt.exe encrypt.cpp

decrypt: ReallyLongInt.cpp numberTheory.cpp
		$(CC) $(FLAGS) -o decrypt.exe decrypt.cpp

clean:
	rm -f *.o *.gcda *.info *.gcno *.gcov *.dSYM *.exe numberTheory_TEST coverage a.out ReallyLongInt_TEST *.txt







 