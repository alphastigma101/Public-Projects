# Define all target
all: exec_interpreter exec_generator exec_vm

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
COMPILER =: -I compiler/
VM =: -I vm/
CATCH =: -I catch/

token.o: token.cc $(TOKENS)
	echo "Attempting to compile token.cc into a object file"
	g++ -std=c++17 $(TOKENS) $(INTERFACE) $(LANGUAGES) -c tokens/token.cc -o token.o 

ast.o: token.o abstraction_syntax_tree.cc $(AST)
	echo "Attempting to compile abstraction_syntax_tree.cc into an object file"
	g++ -std=c++17 $(AST) $(CFG) $(CATCH) -c ast/abstraction_syntax_tree.cc -o ast.o

scanner.o: ast.o scanner.cc
	echo "Attempting to compile scanner.cc file into an object file"
	g++ -std=c++17 $(TOKENS) $(SCANNER) -c scanner/scanner.cc -o scanner.o

parser.o: scanner.o token.o parser.cc
	g++ -std=c++17 -c parser/parser.cc -o parser.o

interpreter.o: scanner.o token.o parser.o interpreter.cc
	g++ -std=c++17 $(INTERPRETER) -c interpreter/interpreter.cc -o interp.o
	
# Compile main object file, depends on scanner.o
main.o: main.cc scanner.o
	g++ -std=c++17 $(SCANNER) -c main.cc -o main.o

interpreter.o: interpreter.cc 
	g++ -std=c++17 -c interpreter/interpreter.cc -o interpreter.o 

# Link object files to create executable 'exec_compiler', depends on scanner.o and main.o
exec_interpreter: scanner.o parser.o interpreter.o main.o ast.o 
	g++ -g -std=c++17 scanner.o main.o ast.o -o exec_interpreter

compiler.o: ast.o compiler.cc $(AST)
	g++ -std=c++17 $(AST) -c copmiler/compiler.cc -o compiler.o

generate_code.o: token.o ast.o parser.o generate_code.cc
	g++ -std=c++17 $(AST) $(CFG) $(LANGUAGES) $(PARSER) $(TOKENS) -c generate_code.cc -o gc.o

exec_generator: ast.o parser.o gc.o token.o
	g++ -g -std=c++17 parser.o ast.o gc.o token.o -o exec_generator 

config_virtual_machine.o: compiler.o ast.o token.o parser.o virtual_machine.cc vm.cc
	g++ -std=c++17 $(AST) $(CFG) $(LANGUAGES) $(PARSER) $(COMPILER) $(TOKENS) $(VM) -c vm/config_virtual_machine.cc -o config_vm.o

exec_vm: config_virtual_machine.o compiler.o parser.o ast.o token.o
	g++ -g -std=c++17 config_vm.o compiler.o parser.o ast.o token.o -o exec_vm 

# Clean up object files
clean:
	rm -rf *.o
