#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_
#include <stdexcept> // runtime_error can be used
#include <language_specific_unary_operations.h> // declares the Vistor template
#include <language_specific_binary_operations.h>
#include <language_specific_truthy_operations.h> // declares the Vistor template

namespace Interpreter {
    class RunTimeError: public std::run_time {


    };
    class interpreter: public unaryOperations, public binaryOperations, public isTruthyOperations, public RunTimeError {
        // A class object that visits Binary, Unary, Grouping, or Literal.
        public:
            interpreter(Vistor* expr, LanguageTypes& lang): expr(this->expr) currentLanguage(lang) {};
            ~interpreter(){};
            auto visitLiteralExpr(Visitor* expr) {return expr->value;};
            auto visitUnaryExpr(Visitor* expr);
            auto visitBinaryExpr(Visitor* expr);
        private:
            using Any = std::any; 
            Vistor* expr;
            bool isTruthy(Visitor* object);
            LanguageTypes currentLanguage;
        protected:
            auto evaluate(Visitor* expr) {return expr->accept(*this);};
    };
};
#endif
