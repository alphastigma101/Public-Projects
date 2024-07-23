#pragma once
#ifndef LANGUAGES_H
#define LANGUAGES_H
#include <cfg/context_free_grammar.h>
#include <string>
#include <iostream>
#include "lookup_languages.h"
#include "macros.h" // has pargma once inside the file so the macros inside it cannot be called in other files

inline const std::string C() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static *char>(C_CODE); // make a copy and modify the copy and not the origional
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther for each inline function
    return code;
}

inline const std::string CPP() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(CPP_CODE);
    
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther 

}

inline const std::string Java() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(JAVA_CODE);
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther 
}

inline const std::string Python() {
    const std::string for_loop = "for i in range(0, 10):\n\t # Fill in your code here!"; 
    const std::string while_loop = "while (True):\n\t# Fill in your code here and replace true with something else!\n";
    const std::string if_blocks = "if (true):\n\t#fill in your code here!\nelif (True): \n\t#Fill in your code here!\n";
    const std::string function = "# You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(PYTHON_CODE);
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    // Use the parser class to parse the token even farther 

}

inline const std::string JavaScript() {
    const std::string for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code= std::const_cast<static std::string>(JAVASCRIPT_CODE);
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const *char Ruby() {
    const std::string for_loop = "class Array\ndef find\nfor i in 0...size\nvalue = self[i]\nreturn value if yield(value)\nend\nreturn nil\nend\nend\n"; // Each end needs to align 
    const std::string while_loop = "while i1 <= max\nyield i1\ni1, i2 = i2, i1+i2\nend"; // end needs to be aligned with while
    const std::string if_blocks = "if block_given?\nresult = yield <object>\nend"; // yield outputs the value to the terminal
    const function = "// You can call in function by providing their signatures inside this field or any other field\n[1, 3, 5, 7, 9].find {|v| v*v > 30 }";
    static char code = std::const_cast<static *char>(RUBY_CODE);
    // prepend for_loop inside code
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object

}

inline const *char Swift() {
    const *char for_loops = "for val in sequence{\n// statements\n}";
    const *char while_loops = "while (condition){\n// body of loop\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain this field or any other field";
    static char code[] = std::const_cast<static *char>(SWIFT_CODE);
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const *char Go() {
    const *char for_loop = "for i:=0; i < 3; i++ { // Fill in your code here!}"; 
    const *char while_loop = "while true {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if true {\n fill in your code here!\n}\nelse if true {\n\t//Fill in your code here!\n}";
    static char code[] = std::const_cast<static *char>(GO_CODE);
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object

}

inline const *char Kotlin() {
    const *char for_loops = "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\nfor (item in items) {\nprintln(item)\n}";
    const *char if_blocks = "if (true) {\n// FMI\n}\nelse {\n// FMI\n}";
    const *char while_loops = "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\nvar index = 0\nwhile (index < items.size) {\nprintln(\"item at $index is ${items[index]}\")\nindex++";
    static char[] code = std::const_cast<static *char>(KOTLIN_CODE); // returns a string literal 
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
    static char[] code = std::const_cast<static *char>(SCALA_CODE);
    // Iterate through code and inject additional code into it 
    // where FOR and IF show up inject the corresponding objects into the code object

}

inline const *char TypeScript() {
    const *char for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const *char while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const *char if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const *char function = "// You can call in function by providing their signatures inside certain fields";
    static char code[] = std::const_cast<static *char>(TYPESCRIPT_CODE); // Make a copy of the macro and write it to a buffer 
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline *char PHP() {
    const *char front_tag = "<?php\n";
    *char end_tag = "?>;
    const *char for_loop = "echo 'Single digit odd numbers from range():  ';\nforeach (range(1, 9, 2) as $number) {\n echo \"$number \";\n}\necho \"\n\";
    const *char while_loop = "";
    const *char if_block = "if ($start <= $limit) {\nif ($step <= 0) {\n//Replace the objects with existing objects\nthrow new LogicException('Step must be positive');\n}\nfor ($i = $start; $i <= $limit; $i += $step) {\nyield $i;\n}\n} else {\nif ($step >= 0) {\n
            throw new LogicException(\"Step must be negative\");\n}\n";
    static char code[] = front_tag; // prepend the front tag
    size_t *buff_size = sizeof(code) / sizeof(char); // make it a pointer
    code[buff_size + 1] = std::const_cast<static *char>(PHP_CODE);
    buff_size = sizeof(code) / sizeof(char); // make a pointy 
    code[*buff_size + 1] = end_tag; // add the end tag
    code[*buff_size + 2] = '\0'; // add a null terminator at the very end of the buffer
    
    size_t indexes[] = replace(code, buff_size);
    static char front[] = code[indexes[0]];
    size_t *front_size = sizeof(front) / sizeof(char);
    static char end[] = code[*buff_size - *front_size];
    size_t *end_size = sizeof(end) / sizeof(char);
    // Whenever the front_size gets assigned a new pointy it should be changing the size for front and for end when it is dereferenced inside the [] field
    // Meaning that end should be increasing in size 
    front[*front_size - function_literal] = function; // append the literal
    buff_size = (sizeof(front) / sizeof(char)) + (sizeof(end) / sizeof(char));
    code[*buff_size] = static_cast<static *char>(front) + static_cast<static *char>(end);
    
    front_size = code[indexes[1]];
    front[*front_size - if_literal] = if_blocks;
    code[*buff_size] = static_cast<static *char>(front) + static_cast<static *char>(end);
    
    front_size = code[indexes[2]];
    front[*front_size - for_literal] = for_loop;
    code[*buff_size] = static_cast<static *char>(front) + static_cast<static *char>(end);
    
    front_size = code[indexes[3]];
    front[*front_size - while_literal] = while_loop;
    code[*buff_size] = static_cast<static *char>(front) + static_cast<static *char>(end);
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
    static const *char result = FINAL(code);
    return result;
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

inline const std::string Prolog() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Ada() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string AWK() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string TCL() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Dlang() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Julia() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string VisualBasic() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string PowerShell() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Racket() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Elm() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Eiffel() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string LabVIEW() {
    // Iterate through code and inject additional code into it 
    // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string Smalltalk() {
   // Iterate through code and inject additional code into it 
   // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}

inline const std::string StandardML() {
   // Iterate through code and inject additional code into it 
   // where FOR, WHILE, FUNCTION, and IF show up inject the corresponding objects into the code object
}
