#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "db.h"
#include "interface.h"
enum TokenType {
  // Single-character tokens.
  LEFT_PAREN = '(', RIGHT_PAREN =')', LEFT_BRACE = '{', 
  RIGHT_BRACE = '}',
  COMMA = ',', DOT = '.', MINUS = '-', PLUS = '+', SEMICOLON = ';', 
  SLASH = '/', STAR = '*',

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  EOF
}

typedef struct Token {
    // Add some primtive types here in the structs field 
};



class Tokenizer {
    public:
        Tokenizer();
        bool consume(const char* literal);
    protected:
        //
    private:
        //
};

#endif
