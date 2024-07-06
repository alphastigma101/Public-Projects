#include "scanner.h"

Scanner::Scanner(std::string Source): Source(this->Source) {
    if (tokens == nullptr) { tokens = new std::vector<Token>(); }
}

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
    tokens.push_back(new Token(EOF, "", nullptr, line));
    return tokens;

}

bool Scanner::isAtEnd() { return current >= Source.length(); }

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (Source.at(current) != expected) return false;
    current++;
    return true;
}

void Scanner::scanToken() {
    char c = Scanner::advance();
    // continue to add more lexemes for lexical analysis
    // lexical analysis is when you turn something not meaningful into something meaningful
    // Ex: language
    // pull out gua which is the process of lexical analysis

    switch (c) {
        // Single-character tokens
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(Token::RIGHT_BRACE); break;
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
                   while (Scanner::peek() != '\n' && !Scanner::isAtEnd()) Scanner::advance();
               } else {
                   addToken(TokenType::SLASH);
               }
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
        case '"': string(); break;
        default: 
               if (Scanner::isDigit(c)) { 
                   Scanner::number();
               } 
               else if (Scanner::isAlpha(c)) { 
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
    std::string text = Source.substr(start, current);
    tokens.push_back(new Token(type, text, literal, line));
}

char Scanner::peek()  {
    if (Scanner::isAtEnd()) return '\0';
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
    Scanner::advance();

    // Trim the surrounding quotes.
    std::string value = Source.substr(start + 1, current - 1);
    addToken(TokenType::STRING, value);
}
void Scanner::number() {
    while (isDigit(Scanner::peek())) advance();
    // Look for a fractional part.
    if (Scanner::peek() == '.' && Scanner::isDigit(Scanner::peekNext())) {
        // Consume the "."
        Scanner::advance();
        while (isDigit(peek())) advance();
    }
    addToken(TokenType::NUMBER,Source.substr(start, current));
}

char Scanner::peekNext() {
    if (current + 1 >= Source.length()) return '\0';
    return Source.at(current + 1);
}

void Scanner::identifier() {
    while (Scanner::isAlphaNumeric(Scanner::peek())) Scanner::advance();
    std::string text = Source.substr(start, current);
    TokenType type = keywords.get(text);
    if (type == (void*)0) type = TokenType::IDENTIFIER;
    addToken(type);
}

bool Scanner::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
            c == '_';
}

bool Scanner::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}
