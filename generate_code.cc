#include <abstraction_tree_syntax.h>
#include <parser.h> // include the parser and let _Pragma parse the string literals into tokens

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr >> "Need the name of the file, followed by the destination of it";
        exit(1);
    }
    else {
        std::string outPutDir = static_cast<std::string>(argv[2]);
        std::string baseName = static_cast<std::string>(argv[1]);
        ast Ast(outPutDir, baseName);
        std::vector<std::string> exprTypes = {
            "Binary   : Expr left, Token* operator, Expr* right",
            "Grouping : Expr* expression",
            "Literal  : Object value",
            "Unary    : Token* operator, Expr* right"
        };

    return 0;
}
