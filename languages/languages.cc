#include <languages.h>

//TODO: add argument support
#define FINAL(CODE)  _Pragma(#CODE)

std::string operations::replace(std::string &code, const std::string for_loops, const std::string while_loops, const std::string if_blocks, const std::string function) {
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

std::string static_languages::C() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields like this field, but the function needs to be defined before you call it";
    static std::string code = std::const_cast<static std::string>(C_CODE); // make a copy and modify the copy and not the origional
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string static_languages::CPP() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(CPP_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Java() {
    const std::string for_loop = "for (int i = 0; i < 10; i++) { // Fill in your code here!}";
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(JAVA_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::Python() {
    const std::string for_loop = "for i in range(0, 10):\n\t # Fill in your code here!"; 
    const std::string while_loop = "while (True):\n\t# Fill in your code here and replace true with something else!\n";
    const std::string if_blocks = "if (true):\n\t#fill in your code here!\nelif (True): \n\t#Fill in your code here!\n";
    const std::string function = "# You can call in function by providing their signatures inside certain fields";
    static std::string code = std::const_cast<static std::string>(PYTHON_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::JavaScript() {
    const std::string for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields ex: some_function()";
    static std::string code = std::const_cast<static std::string>(JAVASCRIPT_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::Ruby() {
    const std::string notes = "// the yield keyword allows you to print things.\nAn example of a for loop is insde the Array class as you need to create your own instances";
    const std::string class_block = "class Array\ndef find\nfor i in 0...size\nvalue = self[i]\nreturn value if yield(value)\nend\nreturn nil\nend\nend\n"; // Each end needs to align 
    const std::string for_loops = "for i in 0...size\nvalue = self[i]\nreturn value if yield(value)";
    const std::string while_loop = "while i1 <= max\nyield i1\ni1, i2 = i2, i1+i2\nend"; // end needs to be aligned with while
    const std::string if_blocks = "if block_given?\nresult = yield <object>\nend"; // yield outputs the value to the terminal
    const std::string function = "// You can call in function or instance of a class by providing their signatures inside this field or any other field\n[1, 3, 5, 7, 9].find {|v| v*v > 30 }";
    static std::string code = std::const_cast<static std::string>(RUBY_CODE);
    code.insert(0, notes);
    code.insert(1, class_block);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Swift() {
    const std::string for_loops = "for val in sequence{\n// statements\n}";
    const std::string while_loops = "while (condition){\n// body of loop\n}";
    const std::string if_blocks = "if (true){\n fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain this field or any other field";
    static std::string code = std::const_cast<static std::string>(SWIFT_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Go() {
    const std::string for_loop = "for i:=0; i < 3; i++ { // Fill in your code here!}"; 
    const std::string while_loop = "while true {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if true {\n\t//fill in your code here!\n}\nelse if true {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in the function by defining it and declaring it inside a field";
    static std::string code = std::const_cast<static std::string>(GO_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Kotlin() {
    const std::string notes = "// There are three ways to create arrays in Kotlin: /*\n\t1) arrayOf() Which is an array of types you can specify\n2)\sarrayOfNulls() this is self explainatory\n3)\semptyArray()\swhich is also self explainatory\n*/";
    const std::string for_loops = "for (item in items) {\nprintln(item)\n}";
    const std::string if_blocks = "if (true) {\n\t// FMI\n}\nelse {\n\t//FMI\n}";
    const std::string while_loops = "var index = 0\nwhile (index < items.size) {\nprintln(\"item at $index is ${items[index]}\")\nindex++";
    const std::string function = "// Define the funciton and pass it inside a field";
    static std::string code = std::const_cast<static std::string>(KOTLIN_CODE); // returns a string literal 
    code.insert(0, notes);
    code.insert(1, "val items = listOf(\"apple\", \"banana\", \"kiwifruit\")\s//\sThis is how you create a list in kotlin\n");
    const std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    static const std::string result = FINAL(code);
    //TODO: remove the constant type and return it 
    return result;
}

std::string static_languages::Scala() {
    const std::string for_loop = "val buffer = new ListBuffer[Int]()\n for i <- ints do\nbuffer += i * 2\sbuffer.toList"; // buffer.toList needs to be outside of the for loop and not inside of it 
    const std::string if_blocks = "if (true) {\n\s//FMI\n}\n else if (test2) {\n//FMI\n}\nelse{\n//FMI\n}\n";
    const std::string function = "// You can call in the function as long as it is defined inside a field, ex: some_function()";
    static std::string code = std::const_cast<static std::string>(SCALA_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string static_languages::TypeScript() {
    const std::string for_loop = "for (var i in arr) { // Fill in your code here!}"; 
    const std::string while_loop = "while (true) {\n\t// Fill in your code here and replace true with something else!\n}";
    const std::string if_blocks = "if (true){\n\t//fill in your code here!\n}\nelse if (true) {\n\t//Fill in your code here!\n}";
    const std::string function = "// You can call in function by providing their signatures inside certain fields ex: some_function()";
    static std::string code = std::const_cast<static std::string>(TYPESCRIPT_CODE); // Make a copy of the macro and write it to a buffer 
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::PHP() {
    const std::string notes = "// This is how you create variables in php: /* $var = 'Bob';\n $Var = 'Joe';*/\n//As you can see it is similar to bash in a way. You can also reference an object like so:\n/* $foo = 'Bob';\n$bar = &$foo;*/\n// Now replace the variables that do not exist with existing variables\n";
    const std::string front_tag = "<?php\n";
    const std::string end_tag = "?>";
    const std::string for_loop = "echo 'Single digit odd numbers from range():  ';\nforeach (range(1, 9, 2) as $number) {\n echo \"$number \";\n}\necho \"\n\";
    const std::string while_loop = "$i = 1;\nwhile ($i < 6) {\n\techo $i;\n$i++;\n}\n";
    const std::string if_block = "if ($start <= $limit) {\nif ($step <= 0) {\n\t//Replace the objects with existing objects\n\tthrow new LogicException('Step must be positive');\n}\nfor ($i = $start; $i <= $limit; $i += $step) {\nyield $i;\n}\n} else {\nif ($step >= 0) {\n
            throw new LogicException(\"Step must be negative\");\n}\n";
    const std::string function "echo \"You need to define the function first somewhere inside the tag field and you can call it here\"";
    static std::string code = std::const_cast<static std::string>(PHP_CODE);
    code.insert(0, front_tag);
    code.insert(1, notes);
    code.insert(2, "class FMI {\n// As you can see, the class syntax in php is similar to c++. Instead of doing public: you do something below:\npublic $var = 'a default value';\n
    public function fmi() {\necho $this->var;\n}\n}");
    code.insert(3, "// You can create an array using arry(//fill stuff in here ); or you can do it like this:\n/*$array = [\"foo\" => \"bar\",\n\"bar\" => \"foo\", \"c\"\n];*/\n//This is the syntax:/*\n$arr[key] = value;\n$arr[] = value;\n//Meaning that it is an element if it does not have =>, but will be a dictionary if it has a element mapped to another element using the =>");
    code.push_back(end_tag);
    const std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    static const std::string result = FINAL(updated_code);
    return result;
}

std::string dynamic_languages::Perl() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(PERL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string lang::R() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(R_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::ObjectiveC() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(OBJECTIVEC_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Haskell() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(HASKELL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Rust() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(RUST_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Dart() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(DART_CODE);
    const std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::Lua() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(LUA_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::Shell() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(SHELL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string other_languages::HTMLCSS() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(HTMLCSS_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string other_languages::SQL() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(SQL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::MATLAB() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(MATLAB_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::VHDLVerilog() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(VHDL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string static_languages::FSharp() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(FSHARP_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string static_languages::CSharp() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(CSHARP_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::VBA() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(VBA_CODE);
    const std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::Fortran() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(FORTAN_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string static_languages::COBOL() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(COBOL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string static_languages::Pascal() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(PASCAL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::LISPScheme() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(LISPSCHEME_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::Groovy() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(GROOVY_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::Erlang() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(ERLANG_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string lang::Clojure() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(CLOJURE_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::Prolog() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(PROLOG_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string static_languages::Ada() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(ADA_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::AWK() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(AWK_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::TCL() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(TCL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string other_languages::Dlang() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(DLANG_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;

}

std::string dynamic_languages::Julia() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(JULIA_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string other_languages::VisualBasic() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(VISUALBASIC_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::PowerShell() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(POWERSHELL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::Racket() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(RACKET_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string other_languages::Elm() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(ELM_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string other_languages::Eiffel() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(EIFFEL_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string other_languages::LabVIEW() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(LABVIEW_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string dynamic_languages::Smalltalk() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(SMALLTALK_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}

std::string other_languages::StandardML() {
    const std::string front_tag = "";
    const std::string end_tag = "";
    const std::string for_loop = "";
    const std::string while_loop = "";
    const std::string if_block = "";
    const std::string function "FMI";
    static std::string code = std::const_cast<static std::string>(STANDARDML_CODE);
    std::string updated_code = replace(code, for_loops, while_loops, if_blocks, function);
    return updated_code;
}
