#include <parser.h>


Expr Parser::equality() {
    Expr expr = comparison();
    while (match(TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL)) {
        const Token op = previous();
        Expr right = comparison();
        expr = new Binary(expr, op, right);
    }
    return expr;
}

Expr Parser::comparison() {
    Expr expr = term();
    while (match(TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL)) {
        Token op = previous();
        Expr right = term();
        expr = new Binary(expr, op, right);
    }
    return expr;
}

Expr Parser::term() {
    Expr expr = factor();
    while (match(TokenType::MINUS, TokenType::PLUS)) {
      const Token op = previous();
      Expr right = factor();
      expr = new Binary(expr, op, right);
    }
    return expr;
  }
}

Expr Parser::factor() {
    Expr expr = unary();
    while (match(TokenType::SLASH, TokenType::STAR)) {
        const Token op = previous();
        Expr right = unary();
        expr = new Binary(expr, op, right);
    }
    return expr;
}

Expr Parser::unary() {
    if (match(TokenType::BANG, TokenType::MINUS)) {
      const Token op = previous();
      Expr right = unary();
      return new Expr.Unary(op, right);
    }
    return primary();
}

Expr Parser::primary() {
    if (match(TokenType::FALSE)) return new Literal(false);
    if (match(TokenType::TRUE)) return new Literal(true);
    if (match(TokenType::NIL)) return new Literal(null);

    if (match(TokenType::NUMBER, TokenType::STRING)) {
      return new Literal(previous().literal);
    }

    if (match(TokenType::LEFT_PAREN)) {
      Expr expr = expression();
      consume(RIGHT_PAREN, "Expect ')' after expression.");
      return new Grouping(expr);
    }
}
