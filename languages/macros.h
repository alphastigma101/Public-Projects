#pragma once // prevents macros from being called multiple times 
#ifndef MACROS_H
#define MACROS_H
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
    "function fmi(arr) {\n" \
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
    "return arr\n"\
    "}"

#define SWIFT_CODE _Pragma(#SWIFT_CODE_STR)


#define KOTLIN_CODE_STR \
    "fun fmi(): None {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\t\"IF\"\n" \
    "\t\"FUNCTION\"\n" \
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
  "\thelper(Function)\n" 

#define TYPESCRIPT_CODE_STR \
    "function fmi(arr) {\n" \
    "\t\"FOR\"\n" \
    "\t\"WHILE\"\n" \
    "\tconsole.log(\"Hello, embedded javascript code fmi()\")\n" \
    "}\n" \
    "function fmi_1() {\n" \
    "\t\"FUNCTION\"\n" \
    "\t\"IF\"\n" \
    "\tconsole.log(\"Hello embedded javascript code fmi()_1\")\n" \
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
        ....FMI

#define PERL_CODE _Pragma(#PERL_CODE_STR)


#define RUST_CODE_STR \
        ....FMI
#define RUST_CODE _Pragma(#RUST_CODE_STR)

#define HASKEL_CODE_STR \
        ...FMI

#define HASKEL_CODE _Pragma(#HASKELL_CODE_STR)

#define EML_CODE_STR \ 
    ...FMI
#define LAU_CODE_STR \ 
    ...FMI

#define DARTS_CODE_STR \ 
    ...FMI

#endif
