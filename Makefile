all: scanner.o main.o exec_compiler

scanner.o: scanner.cc
	g++ --std=c++17 -c scanner.cc -o scanner.o


main.o: scanner.o
	g++ --std=c++17 scanner.o -c main.cc -o main.o

exec_compiler:
	g++ -g --std=c++17 main.o exec_compiler


clean:
	rm -rf *.o


