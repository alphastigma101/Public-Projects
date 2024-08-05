#include <abstraction_tree_syntax.h>
/*
 * (ast): The default constructor 
 * Arguments:
 * outputDir: Is the name of the file that will hold the ast structure 
 * baseName: The name of the file code is getting written to 
*/
ast::ast(std::string& outputDir, std::string& baseName): outputDir(this->outputDir) baseName(this->baseName) {
    ast::generateAst(outputDir);
    // OPTIONAL: include a rich eco system based on the file extension the user chooses and add it to baseName
}

/*
 *
 *
 *
*/
void ast::defineAst() {
    if (d.code == '\0') {
        /*
         * d.code == null
            * Means the user did not executed main.cc. They executed generate_code.cc 
         * d.code != null
            * Means user did execute main.cc 
         */
        setTable(table);
        std::cout << "List of supported languages" << std::endl;
        for (const &it: table) { std::cout << it->first << std::endl; }
        std::string user;
        // need to check and see if the user passed in a argument 
        while (!(table.find(user))) {
            std::cout << "> ";
            std::getline(std::cin, user);
        }
        code += function_table.at(user); // referenced value is a function call that returns a const string
        Scanner scanner = new Scanner(code);
        std::vector<Token> tokens = scanner.ScanTokens();
        Parser parser = new Parser(tokens);
    }
    else {
        // user still needs to choose a name for file or get the name of the file at the scanner 
        code = d.code;
        std::vector<Token> tokens = getTokens();
        Parser parser = new Parser(tokens);
    }
}

