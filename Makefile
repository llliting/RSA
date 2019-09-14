CC = g++
FLAGS = -Wall -O0
DEBUG = --DDEBUG -g
COVERAGE = --coverage


all: ReallyLongInt

ReallyLongInt.o: ReallyLongInt.cpp 
	$(CC) -c ReallyLongInt.cpp

main.o: main_ref.cpp
	$(CC) -c main_ref.cpp

main: main.o ReallyLongInt.o
	$(CC) $(FLAGS) -o main main_ref.o ReallyLongInt.o

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(FLAGS) $(CATCHINC) -o ReallyLongInt_UNIT ReallyLongInt_TEST.cpp ReallyLongInt.o

ReallyLongInt: 
	$(CC) $(FLAGS) -o ReallyLongInt.exe ReallyLongInt.cpp

cleantest:
	rm *.gcov;
	rm *.gcda;
	rm *.gcno;
	rm a.out;

clean:
	#rm *.o;
	rm ReallyLongInt.exe;
	#rm main;




