#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"
#include <vector>
#include <map>

class Scanner: private Interface {
    public:
        Scanner(std::string Source);
        std::vector<Token> scanTokens();
    private:
        std::string Source;
        std::vector<Token> tokens; 
        int start = 0;
        int current = 0;
        int line = 1;
        void scanToken();
        void addToken(TokenType type);
        void addToken(TokenType type, const char* literal);
        void identifier();
        static const std::map<std::string, TokenType> keywords;
};
#endif
