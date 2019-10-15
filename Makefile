CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g

all: keygen decrypt encrypt

debug: rlidebug ntdebug

coverage: rlicov ntcov
rlicov: rlicoverage rli_lcov
ntcov: ntcoverage nt_lcov

rlidebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
		$(CC) $(FLAGS) -o ReallyLongIntTest.exe ReallyLongInt_TEST.cpp ReallyLongInt.o
		./ReallyLongIntTest.exe

ntdebug: numberTheory_TEST.cpp ReallyLongInt.o numberTheory.o
		g++ numberTheory_TEST.cpp -o numberTheoryTest.exe
		./numberTheoryTest.exe

rlicoverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		$(CC) $(CFLAGE) --coverage ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		./a.out
		gcov ReallyLongInt_TEST.cpp
		gcov -f ReallyLongInt_TEST.cpp
		gcov -b ReallyLongInt_TEST.cpp

rli_lcov:
		lcov --directory . --zerocounters
		./a.out
		lcov --directory . --capture --output-file rli.info
		genhtml rli.info -o rli

ntcoverage: numberTheory_TEST.cpp numberTheory.cpp ReallyLongInt.cpp
		g++ --coverage numberTheory_TEST.cpp -o ntcov.out
		./ntcov.out
		gcov ReallyLongInt_TEST.cpp
		gcov -f ReallyLongInt_TEST.cpp
		gcov -b ReallyLongInt_TEST.cpp

nt_lcov:
		lcov --directory . --zerocounters
		./ntcov.out
		lcov --directory . --capture --output-file nt.info
		genhtml nt.info -o nt

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
	rm -f *.exe *.info *.out *.txt *.o *.gcno *.gcda
	rm -r -f nt rli







 