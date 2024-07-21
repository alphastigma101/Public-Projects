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
    "\tprintf(\"Hello from embedded C code!\");\n" \
    "}\n" \
    "void fmi_1() {\n" \
    "\tprintf(\"Hello from embedded C code!\");\n" \
    "}\n" \
    "void fmi_2() {\n" \
    "\tprintf(\"Hello from embedded C code!\");\n" \
    "}\n" \
    "int main(int argc, char** argv) {\n" \
    "\tprintf(\"Hello World!\");\n" \
    "}\n"

#define C_CODE _Pragma(#C_CODE_STR)

#define PYTHON_CODE_STR \
    "def fmi():\n" \
    "\tprint(\"Embedded python function one\")\n" \
    "\n" \
    "def fmi_1():\n" \
    "\tprint(\"Embedded python function two\")\n" \
    "\n" \
    "if __name__ == '__main__':\n" \
    "\tfmi()\n" \
    "\tfmi_1()\n"

#define PYTHON_CODE _Pragma(#PYTHON_CODE_STR)


#endif
