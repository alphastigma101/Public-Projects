#ifndef SCANNER_H
#define SCANNER_H
#include <tokens/token.h>

class Scanner: private Interface {
    public:
        Scanner(std::string Source);
        ~Scanner();
        std::vector<Token> ScanTokens();
    private:
        std::string Source;
        std::vector<Token> tokens; 
        int start = 0;
        int current = 0;
        int line = 1;
        void scanToken();
        void addToken(TokenType type);
        void addToken(TokenType type, const std::string literal);
        void identifier();
        // Below are the virtual specifier functions 
        bool match(char expected) override {
            if (isAtEnd()) return false;
            if (Source.at(current) != expected) return false;
            current++;
            return true;
        };
        //bool consume(const char* literal) override;
        bool isAtEnd() override { return current >= Source.length();}; 
        char advance() override { return Source.at(current++); };    
        bool isAlpha(char c) override { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'; };
        bool isAlphaNumeric(char c) override { return isAlpha(c) || isDigit(c); };
        bool isDigit(char c) { return c >= '0' && c <= '9'; };
        char peek() override {
            if (isAtEnd()) return '\0';
            return Source.at(current);
        };
        void String() override {
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
            std::string value = Source.substr(start + 1, current - 1);
            addToken(TokenType::STRING, value);
        };
        void number() override {    
            while (isDigit(peek())) advance();
            // Look for a fractional part.
            if (Scanner::peek() == '.' && isDigit(peekNext())) {
                // Consume the "."
                advance();
                while (isDigit(peek())) advance();
            }
            addToken(TokenType::NUMBER,Source.substr(start, current));
        };
        char peekNext() override {
            if (current + 1 >= Source.length()) return '\0';
            return Source.at(current + 1);
        };
        static const std::unordered_map<std::string, TokenType> keywords;
};
#endif
