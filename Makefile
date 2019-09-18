CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g
COVERAGE = --coverage

all: ReallyLongInt

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
		$(CC) $(FLAGS) $(CATCHINC) -o ReallyLongIntTest ReallyLongInt_TEST.cpp ReallyLongInt.o

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
		$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

ReallyLongInt: ReallyLongInt.cpp
		$(CC) $(FLAGS) -o ReallyLongInt.exe ReallyLongInt.cpp

cleantest:
	rm *.gcov;
	rm *.gcda;
	rm *.gcno;
	rm *.o;
	rm a.out;

clean:
	#rm *.o;
	rm ReallyLongInt.exe;
	#rm main;




