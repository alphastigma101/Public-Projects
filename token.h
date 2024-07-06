#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
/*
 * This enum class object supports multiple languages
 * To add support for a custom programming language you would add the tokens here
*/
enum TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE,
    RIGHT_BRACE, COMMA, DOT, 
    MINUS, PLUS, SEMICOLON,
    SLASH, STAR,
    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    // Literals.
    IDENTIFIER, STRING, NUMBER, INT, FLOAT, CHAR, VOID, 
    AUTO,
    // General Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE, PUBLIC, 
    PRIVATE, PROTECTED, IMPORT, PACKAGE, STATIC, FINAL, STD, 
    CATCH,
    // Python Tokens
    DEF, ELIF, TRY, EXCEPT, FINALLY, WITH, AS,
    // JavaScript Tokens
    LET, CONST, FUNCTION, EXPORT,
    // Ruby Tokens
    END, ELSIF, UNLESS, MODULE, REQUIRE,
    // Swift Tokens & Go Tokens
    FUNC, PACKAGE, STRUCT, INTERFACE,
    // Kotlin Tokens
    VAL
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
    DEFUN, SETQ, LAMBDA, PROGN, LOOP,
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
    // Julia Tokens
    TYPE,
    // Elm Tokens
    EXPOSING, ALIAS,
    PORT, ELM_IF, THEN, OF,
    IN, ARROW, EQUALS,
    // Racket Tokens
    DEFINE, COND,
    QUOTE, UNQUOTE, QUASIQUOTE,
    SYNTAX, SYNTAX_RULES,

    // GraphQL Tokens
    QUERY, MUTATION, SUBSCRIPTION, UNION, 
    ENUM, SCALAR, GRAPHQL_INPUT, FRAGMENT,
    ON, NULL, TRUE, BOOLEAN, LIST, NON_NULL,
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
