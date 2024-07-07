# Define all target
all: exec_compiler

# Compile scanner object file
scanner.o: scanner.cc
	g++ -std=c++17 -c scanner.cc -o scanner.o

# Compile main object file, depends on scanner.o
main.o: main.cc scanner.o
	g++ -std=c++17 -c main.cc -o main.o
# Compile the token object file, scanner.o depends on it 
token.o: token.cc
	g++ -std=c++17 -c token.cc -o token.o 
# Link object files to create executable 'exec_compiler', depends on scanner.o and main.o
exec_compiler: scanner.o main.o token.o 
	g++ -g -std=c++17 scanner.o main.o token.o -o exec_compiler

# Clean up object files
clean:
	rm -rf *.o
