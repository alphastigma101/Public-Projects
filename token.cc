#include "token.h"

/*
 *
 * Default constructor is using list-initializing 
 */
Token::Token(TokenType type, std::string lexeme, const std::string literal, int line): type(this->type), lexeme(this->lexeme), literal(this->literal), line(this->line) {}


Token::toString() { return (std::string)type + " " + (const std::string)lexeme + " " + (std::string)literal; }

