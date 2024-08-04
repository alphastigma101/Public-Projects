#pragma once // prevents macros from being called multiple times 
#ifndef MACROS_H
#define MACROS_H
#include <string>
// This file creates a handleful of macros that are considered as strings that can be parsed by the scanner
//
/* Notes you should consider are: 
 * pre-processing directive function like constants
 * therefore, do not need any storage unless you take the address of it 
 * directives have a # infront of it allowing to control/optimize your code in a specific way 
*/
#define C_CODE_STR \
    "#include <stdio.h>\n" \
    "void fmi() {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\tprintf(\"Hello from embedded C code!\");\n" \
    "\t\"FUNCTION\"\n" \
    "}\n" \
    "int main(int argc, char** argv) {\n" \
    "\tprintf(\"Hello World!\");\n" \
    "\tIF\n" \
    "\treturn 0;\n" \
    "}\n"

#define C_CODE _Pragma(#C_CODE_STR)

#define PYTHON_CODE_STR \
    "def fmi():\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\tprint(\"Embedded python function\")\n" \
    "\n" \
    "\t\"FUNCTION\"\n" \ 
    "\n" \
    "if __name__ == '__main__':\n" \
    "\t\"IF\"\n" \
    "\tarr = []\n" \
    "\tmy_dict = {}\n"

#define PYTHON_CODE _Pragma(#PYTHON_CODE_STR)

#define JAVA_CODE_STR \
  "class Main {\n" \
  "\tpublic static void main(String[] args) {\n" \
  "\t\"FOR\"\n" \
  "\t\"WHILE\"\n" \
  "\t\"IF\"\n" \ 
  "\t\"FUNCTION\"\n" \
  "\tSystem.out.println(\"Hello world!\");\n" \
  "\tarr[15];\n" \
  "\tdict = {}\n" \
  "\t}\n" \
  "}\n" 

#define JAVA_CODE _Pragma(#JAVA_CODE_STR)


#define CPP_CODE_STR \ 
  "#include <iostream>\n" \
  "void fmi() {\n" \
  "\t\"FOR\"\n" \
  "\t\"WHILE\"\n" \
  "\tstd::cout << \"Hello embedded c++ code!\";\n" \
  "\t\"FUNCTION\"\n" \
  "}\n" \ 
  "int main(int argc, char **argv) {\n" \ 
  "\t\"IF\"\n" \
  "\tchar buffer[512];\n" \ 
  "\treturn 0;\n" \ 
  "}\n" 

#define CPP_CODE _Pragma(#CPP_CODE_STR)

#define GO_CODE_STR \
    "package main\n" \
    "\timport \"fmt\"\n" \
    "func fmi() {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\tfmt.Println(\"Hello, embedded Go Code\")\n" \
    "\t\"FUNCTION\"\n" \
    "}\n" \
    "func main() {\n" \
    "\t\"IF\"\n" \
    "\tfmt.Println(\"Hello, World!\")\n" \
    "}\n" 

#define GO_CODE _Pragma(#GO_CODE_STR)


#define JAVASCRIPT_CODE_STR \
    "function fmi() {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\tconsole.log(\"Hello, embedded javascript code fmi()\")\n" \
    "}\n" \
    "\t\"FUNCTION\"\n" \
    "\t\"IF\"\n" \
    "}\n"

#define JAVASCRIPT_CODE _Pragma(#JAVASCRIPT_CODE_STR)


#define RUBY_CODE_STR \
    "def fmi\n" \
    "\tyield\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\t\"IF\"\n" \
    "\t\"FUNCTION\"\n" \
    "end\n" \
    "fmi {puts \"Hello, embedded ruby code\"}\n" 

#define RUBY_CODE _Pragma(#RUBY_CODE_STR)
    

#define SWIFT_CODE_STR \ 
    "func fmi() -> None {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\t\"IF\"\n" \ 
    "\t\"FUNCTION\"\n" \
    "\tvar numbers : [Int] = [2, 4, 6, 8]\n" \
    "\tprint("Array: \(numbers)")\n" \
    "\tvar dict = [\"FMI\": \"space\"]\n" \
    "}"

#define SWIFT_CODE _Pragma(#SWIFT_CODE_STR)

#define KOTLIN_CODE_STR \
    "fun fmi(): None {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\t\"IF\"\n" \
    "\t\"FUNCTION\"\n" \
    "\tval simpleArray = arrayOf(1, 2, 3)\n" \
    "\tval numbersMap = mapOf(\"key1\" to 1, \"key2\" to 2, \"key3\" to 3, \"key4\" to 1)\n" \
    "}"

#define KOTLIN_CODE _Pragma(#KOTLIN_CODE_STR)


#define SCALA_CODE_STR \
  "def helper(callback: () => Unit): Unit =\n" \
  "\twhile true do { callback(); Thread.sleep(1000) }\n" \
  "def Function(): Unit =\n" \
  "\tprintln(\"This is function calling in scala\")\n" \
  "\tdef fmi(ints: List[Int]): Unit =\n" \
  "\t\"FOR\"\n" \
  "\t\"IF\"\n" \
  "\t\"FUNCTION\"\n" \
  "@main def Driver: Unit =\n" \
  "\tArr = List(1,2,3)\n" \
  "\tMap = Map(\"FMI\" -> 0)\n" \
  "\thelper(Function)\n" 


#define TYPESCRIPT_CODE_STR \
    "function fmi() {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\tconsole.log(\"Hello, embedded typescript code fmi()\")\n" \
    "\t\"FUNCTION\"\n" \
    "\t\"IF\"\n" \
    "}\n"

#define TYPESCRIPT_CODE _Pragma(#TYPESCRIPT_CODE_STR)


#define PHP_CODE_STR \
    "function fmi() {\n" \
    "\techo \"Hello embedded php code!\"\n" \ 
    "\t\"FUNCTION\"\n" \ 
    "\t\"WHILE\"\n" \
    "\tFOR\n" \
    "\t\"IF\"\n" \
    "}" 

#define PERL_CODE_STR \
        "Perl code goes here..."

#define PERL_CODE _Pragma(#PERL_CODE_STR)


#define R_CODE_STR \
    "R code goes here..."

#define R_CODE _Pragma(#R_CODE_STR)


#define OBJECTIVEC_CODE_STR \
    "Objective-C code goes here..."


#define OBJECTIVEC_CODE _Pragma(#OBJECTIVEC_CODE_STR)


#define HASKELL_CODE_STR \
    "Haskell code goes here..."

#define HASKELL_CODE _Pragma(#HASKELL_CODE_STR)


#define RUST_CODE_STR \
    "Rust code goes here..."


#define RUST_CODE _Pragma(#RUST_CODE_STR)


#define DART_CODE_STR \
    "Dart code goes here..."


#define DART_CODE _Pragma(#DART_CODE_STR)


#define LUA_CODE_STR \
    "Lua code goes here..."


#define LUA_CODE _Pragma(#LUA_CODE_STR)


#define SHELL_CODE_STR \
    "Shell script code goes here..."


#define SHELL_CODE _Pragma(#SHELL_CODE_STR)


#define HTMLCSS_CODE_STR \
    "HTML/CSS code goes here..."


#define HTMLCSS_CODE _Pragma(#HTMLCSS_CODE_STR)


#define SQL_CODE_STR \
    "SQL code goes here..."


#define SQL_CODE _Pragma(#SQL_CODE_STR)


#define VHDL_CODE_STR \
    "VHDL code goes here..."


#define VHDL_CODE _Pragma(#VHDL_CODE_STR)


#define FSHARP_CODE_STR \
    "F# code goes here..."


#define FSHARP_CODE _Pragma(#FSHARP_CODE_STR)


#define CSHARP_CODE_STR \
    "C# code goes here..."


#define CSHARP_CODE _Pragma(#CSHARP_CODE_STR)


#define VBA_CODE_STR \
    "VBA code goes here..."


#define VBA_CODE _Pragma(#VBA_CODE_STR)


#define FORTAN_CODE_STR \
    "Fortran code goes here..."


#define FORTAN_CODE _Pragma(#FORTAN_CODE_STR)


#define COBOL_CODE_STR \
    "COBOL code goes here..."


#define COBOL_CODE _Pragma(#COBOL_CODE_STR)


#define PASCAL_CODE_STR \
    "Pascal code goes here..."


#define PASCAL_CODE _Pragma(#PASCAL_CODE_STR)


#define LISPSCHEME_CODE_STR \
    "Lisp/Scheme code goes here..."


#define LISPSCHEME_CODE _Pragma(#LISPSCHEME_CODE_STR)


#define GROOVY_CODE_STR \
    "Groovy code goes here..."


#define GROOVY_CODE _Pragma(#GROOVY_CODE_STR)


#define ERLANG_CODE_STR \
    "Erlang code goes here..."


#define ERLANG_CODE _Pragma(#ERLANG_CODE_STR)


#define CLOJURE_CODE_STR \
    "Clojure code goes here..."


#define CLOJURE_CODE _Pragma(#CLOJURE_CODE_STR)


#define PROLOG_CODE_STR \
    "Prolog code goes here..."


#define PROLOG_CODE _Pragma(#PROLOG_CODE_STR)


#define ADA_CODE_STR \
    "Ada code goes here..."


#define ADA_CODE _Pragma(#ADA_CODE_STR)


#define AWK_CODE_STR \
    "AWK code goes here..."


#define AWK_CODE _Pragma(#AWK_CODE_STR)


#define TCL_CODE_STR \
    "Tcl code goes here..."


#define TCL_CODE _Pragma(#TCL_CODE_STR)


#define DLANG_CODE_STR \
    "D code goes here..."


#define DLANG_CODE _Pragma(#DLANG_CODE_STR)


#define JULIA_CODE_STR \
    "Julia code goes here..."


#define JULIA_CODE _Pragma(#JULIA_CODE_STR)


#define VISUALBASIC_CODE_STR \
    "Visual Basic code goes here..."


#define VISUALBASIC_CODE _Pragma(#VISUALBASIC_CODE_STR)


#define POWERSHELL_CODE_STR \
    "PowerShell code goes here..."


#define POWERSHELL_CODE _Pragma(#POWERSHELL_CODE_STR)


#define RACKET_CODE_STR \
    "Racket code goes here..."


#define RACKET_CODE _Pragma(#RACKET_CODE_STR)


#define ELM_CODE_STR \
    "Elm code goes here..."


#define ELM_CODE _Pragma(#ELM_CODE_STR)


#define EIFFEL_CODE_STR \
    "Eiffel code goes here..."
    

#define EIFFEL_CODE _Pragma(#EIFFEL_CODE_STR)


#define LABVIEW_CODE_STR \
    "LabVIEW code goes here..."


#define LABVIEW_CODE _Pragma(#LABVIEW_CODE_STR)


#define SMALLTALK_CODE_STR \
    "Smalltalk code goes here..."


#define SMALLTALK_CODE _Pragma(#SMALLTALK_CODE_STR)


#define STANDARDML_CODE_STR \
    "Standard ML code goes here..."


#define STANDARDML_CODE _Pragma(#STANDARDML_CODE_STR)


#endif
