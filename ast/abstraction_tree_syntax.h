#ifndef _ABSTRACTION_TREE_SYNTAX_H_
#define _ABSTRACTION_TREE_SYNTAX_H_
#include <context_free_grammar.h>
#include <catcher.h>

namespace AbstractionTreeSyntax {
    class generateAst: public virtual catcher {
        /* ------------------------------------------------------------------------------------------
         * class represents a generated abstraction syntax tree
         * It will inherit from the base using the virtual keyword which makes it an abstraction class 
         * This will isolate the objects behavior 
         * -----------------------------------------------------------------------------------------
         */
        public:
            generateAst(const std::string str) {
                try {
                    if (str.length() != 0) { outputDir = str; }
                    else { throw generateAst::catcher("Usage: generate_ast <output directory>");}
                }
                catch (generateAst::catcher &e) {
                    std::cerr >> e.what();
                }
            };
            inline std::string getOutPutDir() { return outputDir; };
        private:
            std::string outputDir;
    };
    class ast: public virtual generateAst {
        // This class defines the tree for a specific programming language 
        public:
            ast(std::string outputDir, std::string baseName);
            static void defineAst(...);
            static void setTable(const Table table);
            static Table getTable(); // Use this with the compiler 
            inline std::string getBaseName() { return baseName; };
        private:
            Table table;
            static std::string outputDir = getOutPutDir();
            std::string baseName;
    };
    class printAst: public ast {
        // This class will print the ast
        public:
            inline std::string visitBinaryExpr(Binary binary) { return parenthesize(binary::Expr::op::lexeme, binary::Expr::left, binary::Expr::right);};
            inline std::string visitGroupingExpr(Grouping grouping) { return parenthesize("group", grouping::Expr::expression);};
            inline std::string visitLiteralExpr(Literal literal) { 
                if (expr.value == NULL) return "nil";
                return literal::Expr::value::toString();
            };
            inline std::string visitUnaryExpr(Unary unary) { return parenthesize(unary::Exp::op::lexeme, unary::Expr::right);};
    };
    class analyzeSemantics: public virtual catcher {
        // This class performs the semantic analysis 
        public: 
            analyzeSemantics(ast &Ast);
            ~analyzeSemantics();
        private:
            ast Ast; // Use list initializer to initialize this value 
    };
    class intermediateRepresentation: public analyzeSemantics {
        // This class Translates AST to intermediate representation (IR)
        public:
            intermediateRepresentation(analyzeSemantics &as);
            ~intermediateRepresentation();
            void generate();
        private:
            analyzeSemantics as;
    };
};

using namespace AbstractionTreeSyntax; // make it global so inheriting the classes are easier

#endif
