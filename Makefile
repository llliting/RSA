CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g
COVERAGE = --coverage

all: keygen decrypt encrypt

debug: rlidebug ntdebug

rlidebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
		$(CC) $(FLAGS) $(CATCHINC) -o ReallyLongIntTest ReallyLongInt_TEST.cpp ReallyLongInt.o
		./ReallyLongIntTest

ntdebug: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
		$(CC) $(FLAGS) $(CATCHINC) -o numberTheoryTest numberTheory_TEST.cpp numberTheory.o
		./numberTheoryTest

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

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








 