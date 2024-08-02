#ifndef _CONTEXT_FREE_GRAMMAR_H_
#define _CONTEXT_FREE_GRAMMAR_H_
#include <token.h>
#include <languages.h>
#include <filesystem>

/*
 * A Context Free Grammar consists of a head and a body, which describes what it can generate.
 * The body's purest form will be a list of symbols and these symbols are:
    * (Terminal):
        * letter from the grammar’s alphabet, which you can think of it as a literal value. They are the endpoints in a sense as you only produce one symbol
    * (Nonterminal):
        * is a reference of another grammar rule, which allows you to pick any rules for it 
 * The rule is on the very left side of the ->. On the other side of it are: 
    * Quoted strings which represent the "terminal"
    * Lowercase letters that are  "nonterminal"
*/


namespace ContextFreeGrammar {
    class Expr: public std::filesystem::path  {
        /* 
         * A representation of an abstraction classs which is also considered as a disoriented object
         * ------------------------(Additional Info Below)-------------------------------------------
         * By creating an abstraction class, and allowing a class to inherit it, you basically are allowing them to communicate with eachother
         * Which allows it to not be associated with any type of behavior which usually methods/functions etc are what defined the behavior of an object
         */
        public:
            /*
             * The 'visiting design pattern' is crucial for the abstraction syntax tree to work as it will visit the nodes 
            */
            Expr() {};
            virtual ~Expr() = default;
            virtual void visit(Expr expr) = 0;
            virtual void accept(Expr expr) = 0;
            final Expr left;
            final Token op;
            final Expr right;
    };
    class Binary: public virtual Expr {
        public:
            Binary(Expr left, Token op, Expr right): left(this->left), right(this->right), op(this->op) {};
            ~Binary() {};
            void visit(Binary binary) override {};
            void accecpt(Binary binary) override { binary.visit(this); };
        private:
            Expr left;
            Expr right;
            Token op;
    };
    class Unary: public virtual Expr {
        public:
            Unary() {};
            ~Unary(){};
            void visit(Unary unary) override {};
            void accecpt(Unary unary) override { unary.vist(this); };  
    };
    class Grouping: public virtual Expr {
        public:
            Grouping() {};
            ~Grouping() {};
            void visit(Grouping group) override {};
            void accept(Grouping group) override { group.visit(this); };
    };
    class Literal: public virtual Expr {
        public:
            Literal(){};
            ~Literal(){};
            void visit(Literal literal) override {};
            void accept(Literal literal) override { literal.visit(this); };
    };
};
using ContextFreeGrammar;
#endif 
