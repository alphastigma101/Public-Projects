#ifndef ABSTRACTION_TREE_SYNTAX
#define ABSTRACTION_TREE_SYNTAX
#include <languages/languages.h>

class ast {
    // This class ....
    public:
        ast(std::string outputDir, std::string baseName);
        static void defineAst(std::string outputDir, std::string baseName, std::vector<std::string> types);
        static void defineType(std::string baseName, std::vector<std::string> fields);
        static void defineVisitor(std::string baseName, std::vector<std::string> types);
    protected:
        //
    private:
        std::string outputDir;

};

class printast {
    // This class ...
    public:
        inline std::string visitBinaryExpr(Expr.Binary expr) { return parenthesize(expr.op.lexeme, expr.left, expr.right);};
        inline std::string visitGroupingExpr(Expr.Grouping expr) { return parenthesize("group", expr.expression);};
        inline std::string visitLiteralExpr(Expr.Literal expr) { 
            if (expr.value == NULL) return "nil";
            return expr.value.toString();
        };
        inline std::string visitUnaryExpr(Expr.Unary expr) { return parenthesize(expr.op.lexeme, expr.right);};
};

#endif
