#ifndef ABSTRACTION_TREE_SYNTAX
#define ABSTRACTION_TREE_SYNTAX
#include "context_free_grammar.h"
#include <vector>
#include <iostream>
#include <string>
class ast {
    public:
        ast();
        static void defineAst(std::string outputDir, std::string baseName, std::vector<std::string> types);
        std::string outputDir;
    protected:
        //
    private:
        //

};

#endif
