#include <parser.h>

Parser::Parser(std::vector<Token> tokens): tokens(this->tokens) {}

Parser::~Parser() {}


Expr Parser::equality() {
    Expr expr = comparison();
    while (match(TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL)) {
        const Token op = previous();
        expr.right = comparison();
        expr = new Binary(expr, op, expr);
    }
    return expr;
}

Expr Parser::comparison() {
    Expr expr;
    return expr;

}
