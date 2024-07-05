#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"
#include <vector>

class Scanner : public Interface {
    public:
        Scanner(std::string Source);
        std::vector<Token> scanTokens();
    private:
        std::string Source;
        std::vector<Token> tokens; 
        int start = 0;
        int current = 0;
        int line = 1;
        bool isAtEnd();
        void scanToken();
        char advance();
        void addToken(TokenType type);
        void addToken(TokenType type, const char* literal);
};

#endif
