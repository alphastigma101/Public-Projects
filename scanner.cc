#include "scanner.h"
#include "languages.h"


Scanner::Scanner(std::string Source): Source(this->Source) {
    if (tokens == (void*)0) { tokens = new std::vector<>(); }
}

const std::map<std::string, TokenType> Scanner::keywords = {
    {"and",    TokenType::AND},
    {"class",  TokenType::CLASS},
    {"else",   TokenType::ELSE},
    {"false",  TokenType::FALSE},
    {"for",    TokenType::FOR},
    {"fun",    TokenType::FUN},
    {"if",     TokenType::IF},
    {"nil",    TokenType::NIL},
    {"or",     TokenType::OR},
    {"print",  TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super",  TokenType::SUPER},
    {"this",   TokenType::THIS},
    {"true",   TokenType::TRUE},
    {"var",    TokenType::VAR},
    {"while",  TokenType::WHILE}
};

std::vector<Token> Scanner::ScanTokens() {
    while (!isAtEnd()) {
        // We are at the beginning of the next lexeme.
        start = current;
        scanToken();
    }
    tokens.push_back(new Token(EOF, "", (void*)0, line));
    return tokens;

}

bool Scanner::isAtEnd() { return current >= Source.length(); }

void Scanner::scanToken() {
    char c = advance();
    // continue to add more lexemes for lexical analysis
    // lexical analysis is when you turn something not meaningful into something meaningful
    // Ex: language
    // pull out gua which is the process of lexical analysis

    switch (c) {
        // TODO: Going to move all the other cases into a different file called languages.cc so it can get tokenized there instead of here
        // Going to add some threading as well 

        // C/C++
        case 'i': if (match('n') && match('t')) addToken(INT); break;
        case 'f': if (match('l') && match('o') && match('a') && match('t')) addToken(C_FLOAT); break;
        // Add cases for other C/C++ tokens
        // Java
        case 'p': if (match('u') && match('b') && match('l') && match('i') && match('c')) addToken(PUBLIC); break;
        // Add cases for other Java tokens
        // Python
        case 'd': if (match('e') && match('f')) addToken(DEF); break;
        // Add cases for other Python tokens
        // JavaScript
        case 'v': if (match('a') && match('r')) addToken(VAR); break;
        // Add cases for other JavaScript tokens
        // Ruby
        // Add cases for other Ruby tokens
        // Swift
        case 'f': if (match('u') && match('n') && match('c')) addToken(FUNC); break;
        // Add cases for other Swift tokens
        // Go
        // Add cases for other Go tokens
        // Kotlin
        case 'f': if (match('u') && match('n')) addToken(Token::FUN); break;
        // Add cases for other Kotlin tokens
        // Scala
        // Add cases for other Scala tokens
        // TypeScript
        // Add cases for other TypeScript tokens
        // PHP
        case 'f': if (match('u') && match('n') && match('c') && match('t') && match('i') && match('o') && match('n')) addToken(FUNCTION); break;
        // Add cases for other PHP tokens
        // R
        // Add cases for other R tokens
        // Objective-C
        case '@': if (match('i') && match('n') && match('t')) addToken(OBJC_INT); break;
        // Add cases for other Objective-C tokens
        // Rust
        case 'f': if (match('n')) addToken(FN); break;
        // Add cases for other Rust tokens
        // Dart
        // Add cases for other Dart tokens
        // Lua
        // Add cases for other Lua tokens
        // Shell
        case 'i': if (match('f')) addToken(IF); break;
        // Add cases for other Shell tokens
        // HTML
        case '<': addToken(HTML_TAG_OPEN); break;
        // Add cases for other HTML tokens
        // CSS
        case '.': addToken(CSS_SELECTOR); break;
        // Add cases for other CSS tokens
        // SQL
        case 'S': if (match('E') && match('L') && match('E') && match('C') && match('T')) addToken(SQL_SELECT); break;
        // Add cases for other SQL tokens
        // MATLAB
        // Add cases for other MATLAB tokens
        // Verilog
        case 'm': if (match('o') && match('d') && match('u') && match('l') && match('e')) addToken(VERILOG_MODULE); break;
        // Add cases for other Verilog tokens
        // VHDL
        case 'e': if (match('n') && match('t') && match('i') && match('t') && match('y')) addToken(VHDL_ENTITY); break;
        // Add cases for other VHDL tokens
        // F#
        case 'l': if (match('e') && match('t')) addToken(LET); break;
        // Add cases for other F# tokens
        // C#
        // Add cases for other C# tokens
        // VBA
        case 'S': if (match('u') && match('b')) addToken(VBA_SUB); break;
        // Add cases for other VBA tokens
        // Fortran
        case 'i': if (match('n') && match('t') && match('e') && match('g') && match('e') && match('r')) addToken(INTEGER); break;
        // Add cases for other Fortran tokens
        // COBOL
        case 'I': if (match('D') && match('E') && match('N') && match('T') && match('I') && match('F') && match('I') && match('C') && match('A') && match('T') && match('I') && match('O') && match('N')) addToken(IDENTIFICATION); break;
        // Add cases for other COBOL tokens
        // Pascal
        case 'p': if (match('r') && match('o') && match('g') && match('r') && match('a') && match('m')) addToken(PROGRAM); break;
        // Add cases for other Pascal tokens
        // LISP
        case 'd': if (match('e') && match('f') && match('u') && match('n')) addToken(DEFUN); break;
        // Add cases for other LISP tokens
        // Scheme
        case 'd': if (match('e') && match('f') && match('i') && match('n') && match('e')) addToken(DEFINE); break;
        // Add cases for other Scheme tokens
        // Groovy
        // Add cases for other Groovy tokens
        // Erlang
        // Add cases for other Erlang tokens
        // Clojure
        case 'd': if (match('e') && match('f') && match('n')) addToken(DEFN); break;
        // Add cases for other Clojure tokens
        // Prolog
        case 'f': if (match('a') && match('c') && match('t')) addToken(FACT); break;
        // Add cases for other Prolog tokens
        // Ada
        case 'p': if (match('r') && match('o') && match('c') && match('e') && match('d') && match('u') && match('r') && match('e')) addToken(PROCEDURE); break;
        // Add cases for other Ada tokens
        // AWK
        case 'b': if (match('e') && match('g') && match('i') && match('n')) addToken(BEGIN); break;

        // Single-character tokens
        case '(': addToken(Token::LEFT_PAREN); break;
        case ')': addToken(Token::RIGHT_PAREN); break;
        case '{': addToken(Token::LEFT_BRACE); break;
        case '}': addToken(Token::RIGHT_BRACE); break;
        case ',': addToken(Token::COMMA); break;
        case '.': addToken(Token::DOT); break;
        case '-': addToken(Token::MINUS); break;
        case '+': addToken(Token::PLUS); break;
        case ';': addToken(Token::SEMICOLON); break;
        case '*': addToken(Token::STAR); break;
        case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
        case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
        case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
        case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
        case '/':
               if (match('/')) {
                   // A comment goes until the end of the line.
                   while (peek() != '\n' && !isAtEnd()) advance();
               } else {
                   addToken(Token::SLASH);
               }
               break;
        case 'o':
               // Need to also add support for | and || 
               if (match('r')) { addToken(OR); }
               break;
        case ' ':
        case '\r':
        case '\t':
               // Ignore whitespace.
                break;
        case '\n':
                line++;
                break;
        case '"': string(); break;
        default: 
               if (isDigit(c)) { 
                   number();
               } 
               else if (isAlpha(c)) { 
                   identifier();
               }
               else { 
                   std::cout << line << "Unexpected character."; 
               }
               break;
    }
}
char Scanner::advance() { return source.at(current++); }

void Scanner::addToken(TokenType type) { addToken(type, (void*)0); }

void Scanner::addToken(TokenType type, const char* literal) {
    std::string text = Source.substring(start, current);
    tokens.push_back(new Token(type, text, literal, line));
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return Source.at(current);
}

void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }
    if (isAtEnd()) {
        std::cout << line << "Unterminated string.";
        return;
    }
    // The closing ".
    advance();

    // Trim the surrounding quotes.
    std::string value = Source.substring(start + 1, current - 1);
    addToken(Token::STRING, value);
}
void Scanner::number() {
    while (isDigit(peek())) advance();
    // Look for a fractional part.
    if (peek() == '.' && isDigit(peekNext())) {
        // Consume the "."
        advance();
        while (isDigit(peek())) advance();
    }
    addToken(Token::NUMBER,Source.substring(start, current));
}

char Scanner::peekNext() {
    if (current + 1 >= source.length()) return '\0';
    return source.charAt(current + 1);
}

void Scanner::identifier() {
    while (isAlphaNumeric(peek())) advance();
    addToken(IDENTIFIER);
}

bool Scanner::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
            c == '_';
}

bool Scanner::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}
