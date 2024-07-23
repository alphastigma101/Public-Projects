#pragma once
#ifndef LANGUAGES_H
#define LANGUAGES_H
#include <cfg/context_free_grammar.h>
#include <string>
#include <iostream>
#include "lookup_languages.h"
#include "macros.h" // has pargma once inside the file so the macros inside it cannot be called in other files


inline std::string replace(std::string &code, const std::string for_loops, const std::string while_loops, const std::string if_blocks, const std::string function) {
    if (code.find("FUNCTION")) {
        std::size_t pos = code.find("FUNCTION");
        code.replace((int)pos, (int)pos, function);
    }
    if (code.find("FOR")) {
        std::size_t pos = code.find("FOR");
        code.replace((int)pos, (int)pos, for_loops);

    }
    if (code.find("WHILE")) {
        std::size_t pos = code.find("WHILE");
        code.replace((int)pos, (int)pos, while_loops);
    }
    if (code.find("IF")) {
        std::size_t pos = code.find("IF");
        code.replace((int)pos, (int)pos, if_blocks);
    }
    return code;
}

inline const std::string C() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(C_CODE); // make a copy and modify the copy and not the origional
    replace(code, for_loops, while_loops, if_blocks, function);
    return code;
}

inline const std::string CPP() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(CPP_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
    // Use the parser class to parse the token even farther 

}

inline const std::string Java() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(JAVA_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Python() {
    const std::string for_loop = "for i in range(0, 10):\n\t # Fill in your code here!"; 
    const std::string while_loop = "while (True):\n\t# Fill in your code here and replace true with something else!\n";
    const std::string if_blocks = "if (true):\n\t#fill in your code here!\nelif (True): \n\t#Fill in your code here!\n";
    const std::string function = "# You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(PYTHON_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}

inline const std::string JavaScript() {
    const std::string for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code= std::const_cast<static std::string>(JAVASCRIPT_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Ruby() {
    const std::string for_loop = "class Array\ndef find\nfor i in 0...size\nvalue = self[i]\nreturn value if yield(value)\nend\nreturn nil\nend\nend\n"; // Each end needs to align 
    const std::string while_loop = "while i1 <= max\nyield i1\ni1, i2 = i2, i1+i2\nend"; // end needs to be aligned with while
    const std::string if_blocks = "if block_given?\nresult = yield <object>\nend"; // yield outputs the value to the terminal
    const function = "// You can call in function by providing their signatures inside this field or any other field\n[1, 3, 5, 7, 9].find {|v| v*v > 30 }";
    static std::string code = std::const_cast<static std::string>(RUBY_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}

inline const std::string Swift() {
    const std::string for_loops = "for val in sequence{\n// statements\n}";
    const std::string while_loops = "while (condition){\n// body of loop\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain this field or any other field";
    static std::string code = std::const_cast<static std::string>(SWIFT_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Go() {
    const std::string for_loop = "for i:=0; i < 3; i++ { // Fill in your code here!}"; 
    const std::string while_loop = "while true {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if true {\n fill in your code here!\n}\nelse if true {\n\t//Fill in your code here!\n}";
    static std::string code = std::const_cast<static std::string>(GO_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}

inline const std::string Kotlin() {
    const std::string for_loops = "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\nfor (item in items) {\nprintln(item)\n}";
    const std::string if_blocks = "if (true) {\n// FMI\n}\nelse {\n// FMI\n}";
    const std::string while_loops = "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\nvar index = 0\nwhile (index < items.size) {\nprintln(\"item at $index is ${items[index]}\")\nindex++";
    static std::string code = std::const_cast<static std::string>(KOTLIN_CODE); // returns a string literal 
    replace(code, for_loops, while_loops, if_blocks, function);
    #define FINAL(CODE)  _Pragma(#CODE) // pass in the arguments into the pragma 
    static const std::string result = FINAL(code);
    // Call in the parser and parse the string literal even further. Hopefully it removes the \n \t
    return result; // return the final string literal 
}

inline const std::string Scala() {
    const std::string for_loop = "val buffer = new ListBuffer[Int]()\n for i <- ints do\nbuffer += i * 2\sbuffer.toList"; // buffer.toList needs to be outside of the for loop and not inside of it 
    const std::string if_blocks = "if (test1) {\n\t // FMI }\n else if (test2) {\n // FMI\n}\n else {\n//FMI\n}\n";
    static std::string code = std::const_cast<static std::string>(SCALA_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}

inline const std::string TypeScript() {
    const std::string for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(TYPESCRIPT_CODE); // Make a copy of the macro and write it to a buffer 
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string PHP() {
    const std::string front_tag = "<?php\n";
    const std::string end_tag = "?>;
    const std::string for_loop = "echo 'Single digit odd numbers from range():  ';\nforeach (range(1, 9, 2) as $number) {\n echo \"$number \";\n}\necho \"\n\";
    const std::string while_loop = "";
    const std::string if_block = "if ($start <= $limit) {\nif ($step <= 0) {\n//Replace the objects with existing objects\nthrow new LogicException('Step must be positive');\n}\nfor ($i = $start; $i <= $limit; $i += $step) {\nyield $i;\n}\n} else {\nif ($step >= 0) {\n
            throw new LogicException(\"Step must be negative\");\n}\n";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(PHP_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
    static const std::string result = FINAL(code);
    return result;
}

inline const std::string Perl() {
    static std::string code = std::const_cast<static std::string>(PERL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}

inline const std::string R() {
    static std::string code = std::const_cast<static std::string>(R_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string ObjectiveC() {
    static std::string code = std::const_cast<static std::string>(OBJECTIVEC_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}

inline const std::string Haskell() {
    static std::string code = std::const_cast<static std::string>(HASKELL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Rust() {
    static std::string code = std::const_cast<static std::string>(RUST_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Dart() {
    static std::string code = std::const_cast<static std::string>(DART_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Lua() {
    static std::string code = std::const_cast<static std::string>(LUA_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Shell() {
    static std::string code = std::const_cast<static std::string>(SHELL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string HTMLCSS() {
    static std::string code = std::const_cast<static std::string>(HTMLCSS_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string SQL() {
    static std::string code = std::const_cast<static std::string>(SQL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string MATLAB() {
    static std::string code = std::const_cast<static std::string>(MATLAB_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string VHDLVerilog() {
    static std::string code = std::const_cast<static std::string>(VHDL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string FSharp() {
    static std::string code = std::const_cast<static std::string>(FSHARP_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string CSharp() {
    static std::string code = std::const_cast<static std::string>(CSHARP_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string VBA() {
    static std::string code = std::const_cast<static std::string>(VBA_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Fortran() {
    static std::string code = std::const_cast<static std::string>(FORTAN_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string COBOL() {
    static std::string code = std::const_cast<static std::string>(COBOL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Pascal() {
    static std::string code = std::const_cast<static std::string>(PASCAL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string LISPScheme() {
    static std::string code = std::const_cast<static std::string>(LISPSCHEME_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Groovy() {
    static std::string code = std::const_cast<static std::string>(GROOVY_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Erlang() {
    static std::string code = std::const_cast<static std::string>(ERLANG_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Clojure() {
    static std::string code = std::const_cast<static std::string>(CLOJURE_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Prolog() {
    static std::string code = std::const_cast<static std::string>(PROLOG_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Ada() {
    static std::string code = std::const_cast<static std::string>(ADA_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string AWK() {
    static std::string code = std::const_cast<static std::string>(AWK_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string TCL() {
    static std::string code = std::const_cast<static std::string>(TCL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Dlang() {
    static std::string code = std::const_cast<static std::string>(DLANG_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Julia() {
    static std::string code = std::const_cast<static std::string>(JULIA_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string VisualBasic() {
    static std::string code = std::const_cast<static std::string>(VISUALBASIC_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string PowerShell() {
    static std::string code = std::const_cast<static std::string>(POWERSHELL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Racket() {
    static std::string code = std::const_cast<static std::string>(RACKET_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Elm() {
    static std::string code = std::const_cast<static std::string>(ELM_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Eiffel() {
    static std::string code = std::const_cast<static std::string>(EIFFEL_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string LabVIEW() {
    static std::string code = std::const_cast<static std::string>(LABVIEW_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string Smalltalk() {
    static std::string code = std::const_cast<static std::string>(SMALLTALK_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);
}

inline const std::string StandardML() {
    static std::string code = std::const_cast<static std::string>(STANDARDML_CODE);
    replace(code, for_loops, while_loops, if_blocks, function);

}
