#include <abstraction_tree_syntax.h>

/*
 *
 *
*/
ast::ast(std::string outputDir, std::string baseName): outputDir(this->outputDir) baseName(this->baseName) {
    ast::generateAst(outputDir);
    // OPTIONAL: include a rich eco system based on the file extension the user chooses 
}

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
Table ast::getTable() {
    return table;
}
/*
 *
 *
*/
void ast::defineAst() {
    setTable(table);
    std::cout << "List of supported languages" << std::endl;
    for (const &it: table) { std::cout << it->fist << std::endl; }
    std::string user;
    while (!(table.find(user))) {
        std::cout << "> ";
        std::getline(std::cin, user);
    }
    baseName += function_table.at(user); // referenced value is a function call that returns a const string

    for (std::string type : types) {
        // Print through the types and start processing the strings
    }
}
/*
 *
 *
*/
void ast::defineType(std::string baseName, std::vector<std::string> fields) {
    // This method will define if there is a type of not
}

/*
 *
 *
*/
void ast::defineVisitor(std::string baseName, std::vector<std::string> types) {


}
