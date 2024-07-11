#ifndef CONTEXT_FREE_GRAMMAR
#define CONTEXT_FREE_GRAMMAR
#include "token.h"

static class Binary: public Expr {
    public:
        Binary(Expr left, Token op, Expr right): left(this->left), right(this->right), op(this->op){};
    protected:
        //
    private:
        Expr left;
        Expr right;
        Token op;
};

virtual class Expr {

    final Expr left;
    final Token operator;
    final Expr right;

  // Other expressions...

};

#endif 
