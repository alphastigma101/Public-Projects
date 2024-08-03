#ifndef _PARSER_H_
#define _PARSER_H_
#include <context_free_grammar.h>

class Parser {
    public:
        Parser(std::vector<Token> tokens);
        ~Parser();
    private:
        static int current = 0;
        final std::vector<Token> tokens;
        Expr equality();
        Expr comparison();
        Expr expression();

};

#endif
