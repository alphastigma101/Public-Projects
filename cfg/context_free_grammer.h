#ifndef _CONTEXT_FREE_GRAMMAR_H_
#define _CONTEXT_FREE_GRAMMAR_H_
#include <token.h>
#include <lookup_language.h>
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
            Expr() {};
            virtual ~Expr() = default;
            final Expr left;
            final Token op;
            final Expr right;

    };

    class Binary: public virtual Expr {
        public:
            Binary(Expr left, Token op, Expr right): left(this->left), right(this->right), op(this->op) {};

        protected:
            //
        private:
            Expr left;
            Expr right;
            Token op;
    };
};
using ContextFreeGrammar;
#endif 
