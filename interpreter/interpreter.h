#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_
#include <language_specific_unary_operations.h> // declares the Vistor template
#include <language_specific_binary_operations.h>
#include <language_specific_truthy_operations.h> // declares the Vistor template
#include <typeinfo>
class interpreter: public Check, public NonMemberConv, public unaryOperations {
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
        void checkNumberOperands(const Visitor& op, const Visitor& left, const Visitor& right);
        void checkNumberOperand(const Visitor& op, const Visitor& right);
        LanguageTypes currentLanguage;
        void evaluateBinaryTokens(LanguageTypes& currentLanguage, Visitor& expr, Visitor& left, Visitor& right);
    protected:
        auto evaluate(Visitor* expr) {return expr->accept(*this);};
        inline bool isString(const Type& value) override { return value.type() == typeid(std::string);};
};
#endif
