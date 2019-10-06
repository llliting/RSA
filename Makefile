CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g
COVERAGE = --coverage

all: keygen decrypt encrypt

debug: catchdebug ntdebug

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
		$(CC) $(FLAGS) $(CATCHINC) -o ReallyLongIntTest ReallyLongInt_TEST.cpp ReallyLongInt.o

ntdebug: numberTheory_TEST.cpp numberTheory.o
		$(CC) $(FLAGS) $(CATCHINC) -o numberTheoryTest numberTheory_TEST.cpp numberTheory.o

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

ReallyLongInt: ReallyLongInt.cpp
		$(CC) $(FLAGS) -o ReallyLongInt.exe ReallyLongInt.cpp

keygen: keygen.cpp ReallyLongInt.cpp numberTheory.cpp
		$(CC) $(FLAGS) -o keygen.exe keygen.cpp

encrypt: ReallyLongInt.cpp numberTheory.cpp
		$(CC) $(FLAGS) -o encrypt.exe encrypt.cpp

decrypt: ReallyLongInt.cpp numberTheory.cpp
		$(CC) $(FLAGS) -o decrypt.exe decrypt.cpp

cleantest:
	rm *.gcov;
	rm *.gcda;
	rm *.gcno;
	rm *.o;
	rm a.out;

clean:
	rm *.exe;




 