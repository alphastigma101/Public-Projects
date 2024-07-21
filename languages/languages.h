#ifndef LANGUAGES_H
#define LANGUAGES_H
#include <cfg/context_free_grammar.h>
#include "lookup_languages.h"
#include "macros.h" // has pargma once inside the file so the macros inside it cannot be called in other files

inline *char C() {
    static const *char func = C_CODE;
    return func;
}

inline *char CPP() {
    std::cout << "Function for C++ (CPP)\n";
}

inline *char Java() {
    std::cout << "Function for Java\n";
}

inline *char Python() {
    std::cout << "Function for Python\n";
}

inline *char JavaScript() {
    std::cout << "Function for JavaScript\n";
}

inline *char Ruby() {
    std::cout << "Function for Ruby\n";
}

inline *char Swift() {
    std::cout << "Function for Swift\n";
}

inline *char Go() {
    std::cout << "Function for Go\n";
}

inline *char Kotlin() {
    std::cout << "Function for Kotlin\n";
}

inline *char Scala() {
    std::cout << "Function for Scala\n";
}

inline *char TypeScript() {
    std::cout << "Function for TypeScript\n";
}

inline *char PHP() {
    std::cout << "Function for PHP\n";
}

inline *char Perl() {
    std::cout << "Function for Perl\n";
}

inline *char R() {
    std::cout << "Function for R\n";
}

inline *char ObjectiveC() {
    std::cout << "Function for Objective-C\n";
}

inline *char Haskell() {
    std::cout << "Function for Haskell\n";
}

inline *char Rust() {
    std::cout << "Function for Rust\n";
}

inline *char Dart() {
    std::cout << "Function for Dart\n";
}

inline *char Lua() {
    std::cout << "Function for Lua\n";
}

inline *char Shell() {
    std::cout << "Function for Shell (Bash)\n";
}

inline *char HTMLCSS() {
    std::cout << "Function for HTML/CSS\n";
}

inline *char SQL() {
    std::cout << "Function for SQL\n";
}

inline *char MATLAB() {
    std::cout << "Function for MATLAB\n";
}

inline *char VHDLVerilog() {
    std::cout << "Function for VHDL/Verilog\n";
}

inline *char FSharp() {
    std::cout << "Function for F# (FSharp)\n";
}

inline *char CSharp() {
    std::cout << "Function for C# (CSHARP)\n";
}

inline *char VBA() {
    std::cout << "Function for VBA\n";
}

inline *char Fortran() {
    std::cout << "Function for Fortran\n";
}

inline *char COBOL() {
    std::cout << "Function for COBOL\n";
}

inline *char Pascal() {
    std::cout << "Function for Pascal\n";
}

inline *char LISPScheme() {
    std::cout << "Function for LISP/Scheme\n";
}

inline *char Groovy() {
    std::cout << "Function for Groovy\n";
}

inline *char Erlang() {
    std::cout << "Function for Erlang\n";
}

inline *char Clojure() {
    std::cout << "Function for Clojure\n";
}

inline void Prolog() {
    std::cout << "Function for Prolog\n";
}

inline void Ada() {
    std::cout << "Function for Ada\n";
}

inline void AWK() {
    std::cout << "Function for AWK\n";
}

inline void TCL() {
    std::cout << "Function for TCL\n";
}

inline void Dlang() {
    std::cout << "Function for D\n";
}

inline void Julia() {
    std::cout << "Function for Julia\n";
}

inline void VisualBasic() {
    std::cout << "Function for Visual Basic\n";
}

inline void PowerShell() {
    std::cout << "Function for PowerShell\n";
}

inline void Racket() {
    std::cout << "Function for Racket\n";
}

inline void Elm() {
    std::cout << "Function for Elm\n";
}

inline void Eiffel() {
    std::cout << "Function for Eiffel\n";
}

inline void LabVIEW() {
    std::cout << "Function for LabVIEW\n";
}

inline void Smalltalk() {
    std::cout << "Function for Smalltalk\n";
}

inline void StandardML() {
    std::cout << "Function for Standard ML (SML)\n";
}
