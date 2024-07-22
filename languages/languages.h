#pragma once
#ifndef LANGUAGES_H
#define LANGUAGES_H
#include <cfg/context_free_grammar.h>
#include "lookup_languages.h"
#include "macros.h" // has pargma once inside the file so the macros inside it cannot be called in other files

inline const *char C() {
    const *char for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const *char while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain fields";
    static *char code = &C_CODE; // make a copy and modify the copy and not the origional
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther for each inline function
    return code;
}

inline const *char CPP() {
    const *char for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}"; 
    const *char while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain fields";
    static *char code = &CPP_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther 

}

inline const *char Java() {
    const *char for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const *char while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain fields";
    static *char code = &JAVA_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther 
}

inline const *char Python() {
    const *char for_loop = "for i in range(0, 10):\n\t # Fill in your code here!"; 
    const *char while_loop = "while (True):\n\t# Fill in your code here and replace true with something else!\n";
    const *char if_blocks = "if (true):\n\t#fill in your code here!\nelif (True): \n\t#Fill in your code here!\n";
    const *char function = "# You can call in function by providing their signatures inside certain fields";
    static *char code = &PYTHON_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther 

}

inline const *char JavaScript() {
    const *char for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const *char while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain fields";
    static *char code = &JAVASCRIPT_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const *char Ruby() {
    const *char for_loop = "class Array\ndef find\nfor i in 0...size\nvalue = self[i]\nreturn value if yield(value)\nend\nreturn nil\nend\nend\n"; // Each end needs to align 
    const *char while_loop = "while i1 <= max\nyield i1\ni1, i2 = i2, i1+i2\nend"; // end needs to be aligned with while
    const *char if_blocks = "if block_given?\nresult = yield <object>\nend"; // yield outputs the value to the terminal
    const *char function = "// You can call in function by providing their signatures inside this field or any other field\n[1, 3, 5, 7, 9].find {|v| v*v > 30 }";
    static *char code = &RUBY_CODE;
    // prepend for_loop inside code
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object

}

inline const *char Swift() {
    const *char for_loops = "for val in sequence{\n// statements\n}";
    const *char while_loops = "while (condition){\n// body of loop\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain this field or any other field";
    static *char code = &SWIFT_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const *char Go() {
    const *char for_loop = "for i:=0; i < 3; i++ { // Fill in your code here!}"; 
    const *char while_loop = "while true {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if true {\n fill in your code here!\n}\nelse if true {\n\t//Fill in your code here!\n}";
    static *char code = &GO_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object

}

inline const *char Kotlin() {
    const *char for_loops = "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\nfor (item in items) {\nprintln(item)\n}";
    const *char if_blocks = "if (true) {\n// FMI\n}\nelse {\n// FMI\n}";
    const *char while_loops = "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\nvar index = 0\nwhile (index < items.size) {\nprintln(\"item at $index is ${items[index]}\")\nindex++";
    static *char code = &KOTLIN_CODE; // returns a string literal 
    // Modify it and add the string literals above into it by iterating through it by finding words: FOR, WHILE, IF, and FUNCTION
    // Code goes here ...
    // Code goes here ....
    // tokenize it once more 
    #define FINAL(CODE)  _Pragma(#CODE) // pass in the arguments into the pragma 
    static const *char result = FINAL(code);
    // Call in the parser and parse the string literal even further. Hopefully it removes the \n \t
    return result; // return the final string literal 
}

inline const *char Scala() {
    const *char for_loop = "val buffer = new ListBuffer[Int]()\n for i <- ints do\nbuffer += i * 2\sbuffer.toList"; // buffer.toList needs to be outside of the for loop and not inside of it 
    const *char if_blocks = "if (test1) {\n\t // FMI }\n else if (test2) {\n // FMI\n}\n else {\n//FMI\n}\n";
    static *char code = &SCALA_CODE;
    // Iterate through code and inject additional code into it 
    // where FOR and IF show up inject the corresponding objects into the code object

}

inline const *char TypeScript() {
    const *char for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const *char while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain fields";
    static *char code = &TYPESCRIPT_CODE; // Make a copy of the macro 
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char PHP() {
    const *char for_loop = "echo 'Single digit odd numbers from range():  ';\nforeach (range(1, 9, 2) as $number) {\n echo \"$number \";\n}\necho \"\n\";
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    static const *char result = FINAL(code);
}

inline *char Perl() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char R() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char ObjectiveC() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Haskell() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Rust() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Dart() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Lua() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Shell() {
   // Iterate through code and inject additional code into it 
   // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char HTMLCSS() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char SQL() {
    // Iterate through code and inject additional code into it 
    // This is going to need a different approach 
}

inline *char MATLAB() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char VHDLVerilog() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char FSharp() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char CSharp() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char VBA() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Fortran() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char COBOL() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Pascal() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char LISPScheme() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Groovy() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Erlang() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char Clojure() {
   // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Prolog() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Ada() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void AWK() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void TCL() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Dlang() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Julia() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void VisualBasic() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void PowerShell() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Racket() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Elm() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Eiffel() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void LabVIEW() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void Smalltalk() {
   // Iterate through code and inject additional code into it 
   // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline void StandardML() {
   // Iterate through code and inject additional code into it 
   // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}
