#include <scanner.h>
/*
 *
 * Arguments:
 * outputDir: Is the name of the file that will hold the ast structure 
 * baseName: The name of the file code is getting written to 
*/
ast::ast(std::string outputDir, std::string baseName): outputDir(this->outputDir) baseName(this->baseName) {
    ast::generateAst(outputDir);
    // OPTIONAL: include a rich eco system based on the file extension the user chooses and add it to baseName
}

ast::~ast() {}

/*
 * 
 *
*/
void ast::setTable(const Table table) {
    table = initTable(); // inline function defined in lookup_table.h
}
/*
 *
 *
*/
Table ast::getTable() { return table; }
/*
 *
 * Arguments:
    *  ...: Is a vardic argument which allows optional arguments 
*/
void ast::defineAst(...) {
    // pass in arguments if a file already does exist 
    // Otherwise, create the ast tree for the file
    setTable(table);
    std::cout << "List of supported languages" << std::endl;
    for (const &it: table) { std::cout << it->fist << std::endl; }
    std::string user;
    // need to check and see if the user passed in a argument 
    while (!(table.find(user))) {
        std::cout << "> ";
        std::getline(std::cin, user);
    }
    baseName += function_table.at(user); // referenced value is a function call that returns a const string
    Scanner scanner = new Scanner(baseName);
    std::vector<Token> tokens = scanner.ScanTokens();
    Parser parser = new Parser(tokens);
}

