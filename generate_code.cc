#include "abstraction_tree_syntax.h"


ast::ast(std::string outputDir, std::string baseName): outputDir(this->outputDir) {
    // Constructor should define the imports for whcih ever programming language that is getting generated
    // It should only generate functions for any modern programming langauage 
}


void ast::defineAst() {
    for (std::string type : types) {
        // Print through the types and start processing the strings 
    }

}

void ast::defineType(std::string baseName, std::vector<std::string> fields) {
    // This method will define if there is a type of not 
}

void ast::defineVisitor(std::string baseName, std::vector<std::string> types) {


}


int main(int argc, char** argv) {
    std::vector<std::string> exprTypes = {
        "Binary   : Expr left, Token* operator, Expr* right",
        "Grouping : Expr* expression",
        "Literal  : Object value",
        "Unary    : Token* operator, Expr* right"
    };


    return 0;
}
