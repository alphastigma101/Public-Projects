#include <ast/abstraction_tree_syntax.h>
#include "crow_all.h" 
#include <parser/parser.h> // include the parser and let _Pragma parse the string literals into tokens
static const Table table = initTable(); // Get the table so it will be easier to generate the code

// (crows) which is a web frame work which I will be using these api functions:
// call 
// Using inja as the template engine 


// TODO:
    // Need to create routes that will get the data from template/generate_code.html 
    // The user will have a menu to click on that will display all the current programming languages supported
    // Depending on what the user selects from the drop menu, it will route to a function here which will call the inline functions inside languages.h respectively
    // That means each inline function inside languages.h needs to be implemented correctly 
    // Also optimization should also be added to the navbar.html after generation is a success but will add the bits and pieces for it 


int main(int argc, char** argv) {
    std::vector<std::string> exprTypes = {
        "Binary   : Expr left, Token* operator, Expr* right",
        "Grouping : Expr* expression",
        "Literal  : Object value",
        "Unary    : Token* operator, Expr* right"
    };



    return 0;
}
