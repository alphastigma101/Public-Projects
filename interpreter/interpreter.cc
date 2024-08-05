#include <interpreter.h>


auto interpreter::visitUnaryExpr(VisitorType* expr) {
    auto right = evaluate(expr->right);
    switch (expr->op->getType()) {
        case TokenType::BANG:
            return !isTruthy(right);
        case TokenType::MINUS:
            return -(double)right;
    }
    // Unreachable.
    return NULL;
}

auto interpreter::visitBinaryExpr(VisitorType* expr) {
    auto left = evaluate(expr->left);
    auto right = evaluate(expr->right);

    switch (expr.operator.type) {
        case TokenType::MINUS:
            return (double)left - (double)right;
        case TokenType::SLASH:
            return (double)left / (double)right;
        case TokenType::STAR:
            return (double)left * (double)right;
    }
    // Unreachable.
    return NULL;
}

bool interpreter::isTruthy(VisitorType* object) {
    if (object == NULL) return false;
    if (object == bool) return (bool)object; // TODO: Need to check the actual instance of it 
    return true;
}
