#ifndef LOOKUP_TABLE_H
#define LOOKUP_TABLE_H
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
static const std::unordered_map<std::string, std::vector<std::string>> languageExtensions = {
        {"C", {".c"}},
        {"C++ (CPP)", {".cpp", ".cc", ".cxx"}},
        {"Java", {".java"}},
        {"Python", {".py"}},
        {"JavaScript", {".js"}},
        {"Ruby", {".rb"}},
        {"Swift", {".swift"}},
        {"Go", {".go"}},
        {"Kotlin", {".kt", ".kts"}},
        {"Scala", {".scala"}},
        {"TypeScript", {".ts"}},
        {"PHP", {".php"}},
        {"Perl", {".pl"}},
        {"R", {".r", ".R"}},
        {"Objective-C", {".m"}},
        {"Haskell", {".hs"}},
        {"Rust", {".rs"}},
        {"Dart", {".dart"}},
        {"Lua", {".lua"}},
        {"Shell (Bash)", {".sh"}},
        {"HTML/CSS", {".html", ".css"}},
        {"SQL", {".sql"}},
        {"MATLAB", {".m"}},
        {"VHDL/Verilog", {".vhd", ".vhdl", ".v", ".sv", ".svh"}},
        {"F# (FSharp)", {".fs", ".fsx", ".fsscript"}},
        {"C# (CSHARP)", {".cs"}},
        {"VBA", {".vba"}},
        {"Fortran", {".f", ".f90", ".f95", ".f03", ".f08"}},
        {"COBOL", {".cob", ".cbl"}},
        {"Pascal", {".pas"}},
        {"LISP/Scheme", {".lisp", ".scm"}},
        {"Groovy", {".groovy"}},
        {"Erlang", {".erl"}},
        {"Clojure", {".clj"}},
        {"Prolog", {".pl", ".pro"}},
        {"Ada", {".ada", ".adb"}},
        {"AWK", {".awk"}},
        {"TCL", {".tcl"}},
        {"D", {".d"}},
        {"Julia", {".jl"}},
        {"Visual Basic", {".vb"}},
        {"PowerShell", {".ps1", ".psm1", ".psd1"}},
        {"Racket", {".rkt"}},
        {"Elm", {".elm"}},
        {"Eiffel", {".e"}},
        {"LabVIEW", {".vi"}},
        {"Smalltalk", {".st"}}, // No specific extension, commonly ".st" or others
        {"Standard ML (SML)", {".sml", ".ml"}}
    };

static const std::unorded_map<std::string, std::vector<TokenType>> languageTokenCategories = {
    {"C", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
           TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"C++ (CPP)", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                   TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Java", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
              TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Python", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"JavaScript", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                    TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Ruby", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
              TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Swift", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
               TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Go", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
            TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Kotlin", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Scala", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
               TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"TypeScript", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                    TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"PHP", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
             TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Perl", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
              TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"R", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
           TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Objective-C", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                     TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Haskell", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                 TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Rust", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
              TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Dart", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
              TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Lua", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
             TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"Shell (Bash)", {TokenType::LEFT_PAREN, TokenType::RIGHT_PAREN, TokenType::LEFT_BRACE, TokenType::RIGHT_BRACE, TokenType::COMMA, TokenType::DOT,
                      TokenType::MINUS, TokenType::PLUS, TokenType::SEMICOLON, TokenType::SLASH, TokenType::STAR}},
    {"HTML/CSS", {TokenType::TAG_OPEN, TokenType::TAG_CLOSE, TokenType::ATTR_NAME, TokenType::ATTR_VALUE}},
    {"SQL", {TokenType::SELECT, TokenType::INSERT, TokenType::UPDATE, TokenType::DELETE, TokenType::CREATE,
             TokenType::DROP, TokenType::WHERE, TokenType::FROM, TokenType::INTO, TokenType::VALUES, TokenType::SET}},
    {"MATLAB", {TokenType::CLASSDEF}},
    {"VHDL/Verilog", {TokenType::ENTITY, TokenType::ARCHITECTURE, TokenType::SIGNAL, TokenType::PROCESS}},
    {"F# (FSharp)", {TokenType::MATCH}},
    {"C# (CSHARP)", {TokenType::USING, TokenType::NAMESPACE}},
    {"VBA", {TokenType::SUB, TokenType::DIM}},
    {"Fortran", {TokenType::INTEGER, TokenType::REAL, TokenType::DO, TokenType::ENDDO, TokenType::SUBROUTINE}},
    {"COBOL", {TokenType::IDENTIFICATION, TokenType::DIVISION, TokenType::SECTION, TokenType::PERFORM, TokenType::STOP, TokenType::RUN}},
    {"Pascal", {TokenType::PROGRAM, TokenType::BEGIN, TokenType::PROCEDURE}},
    {"LISP/Scheme", {TokenType::DEFUN, TokenType::SETQ, TokenType::LAMBDA, TokenType::PROGN, TokenType::LOOP}},
    {"Clojure", {TokenType::DEFN, TokenType::RECUR}},
    {"Prolog", {TokenType::FACT, TokenType::RULE}},
    {"TCL", {TokenType::PROC}},
    {"Julia", {TokenType::TYPE}},
    {"Elm", {TokenType::EXPOSING, TokenType::ALIAS, TokenType::PORT, TokenType::THEN, TokenType::OF, TokenType::IN, TokenType::ARROW, TokenType::EQUALS}},
    {"Racket", {TokenType::QUOTE, TokenType::UNQUOTE, TokenType::QUASIQUOTE, TokenType::SYNTAX, TokenType::SYNTAX_RULES}},
    {"Smalltalk", {TokenType::TOKEN}}, // Placeholder, as Smalltalk has no specific token extensions
    {"Standard ML (SML)", {TokenType::TOKEN}} // Placeholder, as SML has no specific token extensions
};

typedef std::string Key;
typedef std::vector<std::string> Extension;
typedef std::vector<TokenType> TokenValues;
typedef std::map<Key, std::pair<Extension, TokenValues>> Table;
static const inline Table initTable() {
    Table languageTable;
    for (auto it = languageExtensions.begin(); it != languageExtensions.end(); ++it) {
        const Key& key = it->first;
        const Extension& extension = it->second;
        
        auto tokenIt = languageTokenCategories.find(key);
        if (tokenIt != languageTokenCategories.end()) {
            const TokenValues& tokenValues = tokenIt->second;
            languageTable[key] = std::make_pair(extension, tokenValues);
        }
    }
    return languageTable;
}; 

