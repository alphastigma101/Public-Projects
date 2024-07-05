#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
/*
 * This enum class object supports multiple languages
 * Supports: 
    * Go, Java, Javascript/TypeScript, C/C++, Python, Cobol, Scala
    * Koltin, Swift, Ruby, R, Objective-C, Rust, Dart, PHP, Lua
    * Shell, Groovy, VHDL, Lisp, Ada, Awk, D,
    *
 */
enum class TokenType: char {
    // Single-character tokens.
    LEFT_PAREN = '(', RIGHT_PAREN =')', LEFT_BRACE = '{',
  RIGHT_BRACE = '}',
  COMMA = ',', DOT = '.', MINUS = '-', PLUS = '+', SEMICOLON = ';',
  SLASH = '/', STAR = '*',

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL = '=', EQUAL_EQUAL = '==',
  GREATER = '>', GREATER_EQUAL = '>=',
  LESS = '<', LESS_EQUAL = '<=',

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // General Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  // C/C++ Tokens
  INT, FLOAT, CHAR, VOID, AUTO, STD, CATCH

  // Java Tokens
  PUBLIC, PRIVATE, PROTECTED,
  IMPORT, PACKAGE, STATIC, FINAL,

  // Python Tokens
  DEF, ELIF, TRY, EXCEPT, FINALLY, WITH, AS,

  // JavaScript Tokens
  LET, CONST, FUNCTION, EXPORT,

  // Ruby Tokens
  END, RUBY_IF, ELSIF, UNLESS, MODULE, REQUIRE,

  // Swift Tokens & Go Tokens
  FUNC, PACKAGE, STRUCT, INTERFACE,

  // Kotlin Tokens
  KOTLIN_FUN, VAL

  // TypeScript Tokens
  TS_VAR, TS_LET, TS_CONST, TS_FUNCTION, TS_RETURN, TS_IF, TS_ELSE,
  TS_FOR, TS_WHILE, TS_CLASS, TS_IMPORT, TS_EXPORT,

  // PHP Tokens
  INCLUDE,

  // R Tokens
  LIBRARY,

  // Rust Tokens
  MUT, ENUM, IMPL,


  // Lua Tokens
  LOCAL, 

  // HTML Tokens
  TAG_OPEN, TAG_CLOSE, ATTR_NAME, ATTR_VALUE,

  // CSS Tokens
  SELECTOR, PROPERTY, VALUE,  ID,

  // SQL Tokens
  SELECT, INSERT, UPDATE, DELETE, CREATE,
  DROP, WHERE, FROM, INTO, VALUES, SET,

  // MATLAB Tokens
  CLASSDEF,

  // Verilog Tokens
  MODULE, ENDMODULE, INPUT, OUTPUT,
  ALWAYS, ASSIGN,

  // VHDL Tokens
  ENTITY, ARCHITECTURE, SIGNAL, PROCESS,

  // F# Tokens
  MATCH,

  // C# Tokens
  USING, NAMESPACE,

  // VBA Tokens
  SUB, DIM,

  // Fortran Tokens
  INTEGER, REAL, DO, ENDDO, SUBROUTINE,

  // COBOL Tokens
  IDENTIFICATION, DIVISION, SECTION, PERFORM, STOP, RUN,

  // Pascal Tokens
  PROGRAM, BEGIN, PROCEDURE,

  // LISP Tokens
  DEFUN, LISP_IF, LISP_ELSE, SETQ, LAMBDA,
  PROGN, LOOP,

  // Scheme Tokens
  DEFINE, SET, COND,

  // Erlang Tokens
  CASE, RECEIVE, SWITCH,

  // Clojure Tokens
  DEFN, RECUR,

  // Prolog Tokens
  FACT, RULE,


  // TCL Tokens
  PROC,

  // D Tokens
  D_INT, D_FLOAT, D_CHAR, D_IF, D_ELSE, D_FOR, D_WHILE,
  D_RETURN, D_CLASS, D_IMPORT,

  // Julia Tokens
  TYPE,

   // Elm Tokens
  EXPOSING, ALIAS,
  PORT, ELM_IF, THEN, OF,
  ELM_LET, IN, ARROW, EQUALS,

  // Racket Tokens
  DEFINE, COND,
  QUOTE, UNQUOTE, QUASIQUOTE,
  SYNTAX, SYNTAX_RULES,

  // GraphQL Tokens
  QUERY, MUTATION, SUBSCRIPTION, UNION, 
  ENUM, SCALAR, GRAPHQL_INPUT, FRAGMENT,
  ON, NULL, TRUE, 
  GRAPHQL_INT, GRAPHQL_FLOAT, GRAPHQL_STRING, BOOLEAN, LIST, NON_NULL,
  SPREAD, AT, EXCLAMATION, BRACES, PARENS,
}

class Token {
    public:
        Token(TokenType type, std::string lexeme, const char* literal, int line);
        std::string toString();
    protected:
        //
    private:
        TokenType type;
        std::string lexeme;
        const char* literal; 
        int line;

};

#endif
