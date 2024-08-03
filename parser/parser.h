#ifndef _PARSER_H_
#define _PARSER_H_
#include <context_free_grammar.h>
class Parser {
    /* 
     * An object that represents a parser. 
     * To add more to the parser, you need to add the new rules to the existing grammar, and define it them inside the class field 
     * 
     */
    public:
        Parser::Parser(std::vector<Token> tokens): tokens(this->tokens){};
        Parser::~Parser(){};
    protected:
        // Current rules that were made from a grammar 
        Expr equality();
        Expr comparison();
        Expr expression();
        Expr term();
        Expr factor();
    private:
        int current = 0;
        final std::vector<Token> tokens;
        inline Token previous() {return tokens.at(current - 1);};
        inline Token peek() {return tokens.at(current);};
        inline boolean isAtEnd() {return peek().type == EOF;};
        inline Token advance() {
            if (!isAtEnd()) current++;
            return previous();
        };
        inline bool check(TokenType type) {
            if (isAtEnd()) return false;
            return peek().type == type;
        };
        inline bool match(std::vector<TokenType> types) {
            for (TokenType type : types) {
                if (check(type)) {
                    advance();
                    return true;
                }
            }
            return false;
        };
        inline Token consume(TokenType type, std::string message) {
            if (check(type)) return advance();
            throw error(peek(), message);
        };
        auto error(Token token, String message) {
            // Implement a catcher that will catch the syntax error
        };
};

#endif
