#include "scanner.h"

Scanner::Scanner(std::string Source): Source(this->Source) {}
Scanner::~Scanner() {} ;
const std::map<std::string, TokenType> Scanner::keywords = {
    // Add all the Keywrods here
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
    tokens.push_back(Token(TokenType::END_OF_FILE, "", nullptr, line));
    return tokens;

}

void Scanner::scanToken() {
    char c = advance();
    // continue to add more lexemes for lexical analysis
    // lexical analysis is when you turn something not meaningful into something meaningful
    // Ex: language
    // pull out gua which is the process of lexical analysis

    switch (c) {
        // Single-character tokens
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;
        case '!': addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=': addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<': addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;
        case '>': addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
        case '/':
               if (match('/')) {
                   // A comment goes until the end of the line.
                   while (peek() != '\n' && !isAtEnd()) advance();
               } else { addToken(TokenType::SLASH); }
               break;
        case 'o':
               // Need to also add support for | and || 
               if (match('r')) { addToken(TokenType::OR); }
               break;
        case ' ':
        case '\r':
        case '\t':
               // Ignore whitespace.
                break;
        case '\n':
                line++;
                break;
        case '"': String(); break;
        default: 
               if (isDigit(c)) {number();} 
               else if (isAlpha(c)) { identifier(); }
               else { std::cout << line << "Unexpected character."; }
               break;
    }
}

void Scanner::addToken(TokenType type) { addToken(type, ""); }

void Scanner::addToken(TokenType type, const std::string literal) {
    std::string text = Source.substr(start, current);
    tokens.push_back(Token(type, text, literal, line));
}

void Scanner::identifier() {
    while (isAlphaNumeric(peek())) advance();
    std::string text = Source.substr(start, current);
    auto it = keywords.find(text);
    TokenType type;
    if (it != keywords.end()) {
        type = it->second;
    } else {
        type = TokenType::IDENTIFIER; // Default type if not found in keywords
    }
    addToken(type);
}

