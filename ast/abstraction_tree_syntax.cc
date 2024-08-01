#include <abstraction_tree_syntax.h>

ast::ast(std::string outputDir, std::string baseName): outputDir(this->outputDir) baseName(this->baseName) {
    ast::generateAst(outputDir);
    // OPTIONAL: include the file system based on the file extension the user chooses 
}


void ast::setTable(const Table table) {
    table = initTable(); // inline function defined in lookup_table.h
    // Key will be the name of the programming language, the values are the extension and the tokens needed for the compiler
}

Table ast::getTable() {
    return table;
}

void ast::defineAst() {
    setTable(table);

    for (std::string type : types) {
        // Print through the types and start processing the strings
    }

}

void ast::defineType(std::string baseName, std::vector<std::string> fields) {
    // This method will define if there is a type of not
}

void ast::defineVisitor(std::string baseName, std::vector<std::string> types) {


}

