#include "scanner.h"
#include <filesystem>
#include <system_error>
#include <fstream>
static bool hadError = false;
/* 
 * This function will implement > at runtime 
 */
static void runPrompt() {
     try {
         for (;;) { 
             std::cout << "> ";
             std::string line;
             std::getline(cin, line); // get user input
             if (line == (void*)0) break; // value is '\0' break
             run(line);
         }
    }
    catch(const std::system_error& e) {
        std::cout << "Caught system_error with code " "[" << e.code() << "] meaning " "[" << e.what() << "]\n";
    }
}

/*
 * This function calls in scanner class 
 */
static void run(const std::string source) {
    Scanner scanner = new Scanner(source); // Create a new scanner instance
    std::vector<Token> tokens = scanner.scanTokens();

    // For now, just print the tokens.
    for (Token token : tokens) {
      System.out.println(token);
    }
  }
}

static void error(int line, std::string message) {
    report(line, "", message);
}

static void report(int line, const std::string where, const std::string message) {
    std::cout << "[line " <<  line << "] Error" << where << ": " + message;
    hadError = true;
}

static void runFile(const std::string filePath) {
    std::string source,line;
    if (std::filesystem::path(filePath)) {
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
int main(int argc, char argv[]) {
    if (argc > 1) {
        std::cerr << "Usage: [script]";
        exit(1); 
    }
    else if (argc == 1) {
        runFile(argv[1]);
    } 
    else { runPrompt(); }
    return 0;
}
