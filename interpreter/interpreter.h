#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_
#include <token.h>

template<class VistorType>
class interpreter {
    // A class object that visits Binary, Unary, Grouping, or Literal.
    public:
        interpreter(VistorType* expr, LanguageTypes& lang): expr(this->expr) currentLanguage(lang) {};
        ~interpreter(){};
        auto visitLiteralExpr(VisitorType* expr) {return expr->value;};
        auto visitUnaryExpr(VisitorType* expr);
        auto visitBinaryExpr(VisitorType* expr);
    private:
        using Any = std::any; 
        VistorType* expr;
        bool isTruthy(VisitorType* object);
        void checkNumberOperands(const Token& op, const Expr::left& left, const Expr::right& right);
        LanguageTypes currentLanguage;
    protected:
        auto evaluate(VisitorType* expr) {return expr->accept(*this);};
};
#endif
