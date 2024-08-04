#pragma once
#ifndef LANGUAGES_H
#define LANGUAGES_H
#include "macros.h" // has pargma once inside the file so the macros inside it cannot be called in other files
#include <lookup_languages.h>

//TODO: add argument support
#define FINAL(CODE)  _Pragma(#CODE)

struct languages {
    std::string replace(std::string &code, const std::string for_loops, const std::string while_loops, const std::string if_blocks, const std::string function);
    const std::string C();
    const std::string CPP(); 
    const std::string Java();
    const std::string Python();
    const std::string JavaScript();
    const std::string Ruby();
    const std::string Swift();
    const std::string Go();
    const std::string Kotlin();
    const std::string Scala();
    const std::string TypeScript();
    const std::string PHP();    
    const std::string Perl();
    const std::string R();
    const std::string ObjectiveC();
    const std::string Haskell();
    const std::string Rust();
    const std::string Dart();
    const std::string Lua();
    const std::string Shell();
    const std::string HTMLCSS();
    const std::string SQL();
    const std::string MATLAB();
    const std::string VHDLVerilog();
    const std::string FSharp();
    const std::string CSharp();
    const std::string VBA();
    const std::string Fortran();
    const std::string COBOL();
    const std::string Pascal();
    const std::string LISPScheme();
    const std::string Groovy();
    const std::string Erlang();
    const std::string Clojure();
    const std::string Prolog();
    const std::string Ada();
    const std::string AWK();
    const std::string TCL();
    const std::string Dlang();
    const std::string Julia();
    const std::string VisualBasic();
    const std::string PowerShell();
    const std::string Racket();
    const std::string Elm();
    const std::string Eiffel();
    const std::string LabVIEW();
    const std::string Smalltalk();
    const std::string StandardML();
};

typedef languages lang;
extern lang;

#endif 

