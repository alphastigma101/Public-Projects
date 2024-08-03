#include <scanner.h> // includes token.h, languages.h 
#include <parser.h> // includes abstraction_syntax_tree.h, context_free_grammar.h, token.h, languages.h
#include <filesystem>
#include <system_error>
#include <fstream>
static bool hadError = false;

// Overload the << operator for Token
std::ostream& operator<<(std::ostream& os, Token& token) {
    TokenType type = token.getType();
    std::string lexeme = token.getLexeme();
    return os << "Token(" << static_cast<int>(type) << ", " << lexeme << ")";
}

/*
 * (run): Is a standalone static void function that runs the user input 
 * Parameters:
 * source: is a file that contains data of possibly of a language 
 */
static void run(const std::string source) {
    Scanner scanner(source); // Create a new scanner instance
    d.setCode(source); // set the code 
    std::vector<Token> tokens = scanner.ScanTokens();
    Parser parser = new Parser(tokens);
}


/* 
 * This function will implement > at runtime 
 */
static void runPrompt() {
     try {
         for (;;) { 
             std::cout << "> ";
             std::string line;
             std::getline(std::cin, line); // get user input
             if (line[0] == '\0' || line.empty()) break;
             run(line);
         }
    }
    catch(const std::system_error& e) {
        std::cout << "Caught system_error with code " "[" << e.code() << "] meaning " "[" << e.what() << "]\n";
    }
}

static void report(int line, const std::string where, const std::string message) {
    std::cout << "[line " <<  line << "] Error" << where << ": " + message;
    hadError = true;
}

static void error(int line, std::string message) {
    report(line, "", message);
}

static void runFile(const std::string filePath) {
    std::string source,line;
    if (std::filesystem::exists(filePath)) {
        std::ifstream file (std::filesystem::path(filePath).stem());
        if (file.is_open()) { 
            while (std::getline(file, line)) {
                source.append(line);
            }
            file.close();
            run(source);
            // Indicate an error in the exit code.
            if (hadError) exit(1);
        }
    }
    else {
        std::cout << "Not a valid file" << std::endl;
        runPrompt();
    }
}


// This is the driver code
int main(int argc, char **argv) {
    if (argc > 1) {
        std::cerr << "Usage: [script]";
        exit(1); 
    }
    else if (argc == 1) {
        runFile((std::string)argv[1]);
    } 
    else { runPrompt(); }
    return 0;
}
