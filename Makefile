# Define all target
all: exec_compiler

# This allows me to declare each header with angle brackets around them to avoid multiple collisions 
DATABASE =: -I database/
PARSER =: -I parser/
TOKENS =: -I tokens/
INTERFACE =: -I interface/
INTERPRETER =: -I interpreter/
CFG =: -I cfg/
SCANNER =: -I scanner/
OPTIMIZATION =: -I optimization/
LANGUAGES =: -I languages/
AST =: -I ast/



# Compile scanner object file
scanner.o: scanner.cc
	g++ -std=c++17 $(TOKENS) $(SCANNER) -c scanner.cc -o scanner.o

# Compile main object file, depends on scanner.o
main.o: main.cc scanner.o
	g++ -std=c++17 $(SCANNER) -c main.cc -o main.o
# Compile the token object file, scanner.o depends on it 

token.o: token.cc
	g++ -std=c++17 $(INTERFACE) $(TOKENS) -c token.cc -o token.o 

# Link object files to create executable 'exec_compiler', depends on scanner.o and main.o
exec_compiler: scanner.o main.o token.o 
	g++ -g -std=c++17 scanner.o main.o token.o -o exec_compiler

#generat_code: generate_code.cc
	#g++ -g -std=c++17 $(AST) $(CFG) $(LANGUAGES) $(PARSER) -c generate_code.cc -o generate_code

# Clean up object files
clean:
	rm -rf *.o
