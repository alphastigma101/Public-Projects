#ifndef CONTEXT_FREE_GRAMMAR
#define CONTEXT_FREE_GRAMMAR
#include "token.h"
#include <filesystem>

class Expr {
    // A representation of an abstraction classs
    public:
        virtual Expr();
        virtual ~Expr();
        final Expr left;
        final Token op;
        final Expr right;

};


class Binary: public Expr {
    public:
        inline Binary(Expr left, Token op, Expr right): left(this->left), right(this->right), op(this->op) {
                // Inject some code in here
        };
    protected:
        //
    private:
        Expr left;
        Expr right;
        Token op;
};


#endif 
