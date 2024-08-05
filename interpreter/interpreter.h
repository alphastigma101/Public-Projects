#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

template<class VistorType>
class interpreter {
    // A class object that visits Binary, Unary, Grouping, or Literal.
    public:
        interpreter(VistorType* expr): expr(this->expr) {};
        ~interpreter(){};
        auto visitLiteralExpr(VisitorType* expr) {return expr.value;}; // This could cause a bug because it will be returning whatever it is and not an actual object
        auto visitUnaryExpr(VisitorType* expr);
        auto visitBinaryExpr(VisitorType* expr);
    private:
        VistorType* expr;
        bool isTruthy(VisitorType* object);
    protected:
        auto evaluate(VisitorType* expr) {return expr->accept(*this);};
};
#endif
