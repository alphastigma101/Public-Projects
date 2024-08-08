#include <language_specific_binary_operations.h>
/* ----------------------------------------------------------------------------------------------------------------------------------------------------
 * checkNumberOperands Description: 
    Is a method that calls in isNumeric, the helper function
 * Arguments:
    * auto& expr: It is an place holder type object that references the abstraction syntax, (ast) that is currently being used. In this case, it would be the Binary ast
    * auto& left: Is a generic type that must have a concrete type during run time, and will visit the binary abstract syntax tree left side (lh)
    * auto& right: Is a generic type that must have a concrete type during run time, and will visit the binary abstract syntax tree right side (rh)
 * Returns:
    True if a and b are equal
    Otherwise, return false 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------
*/
void binaryOperations::checkNumberOperands(auto& expr, auto& left, auto& right) {
    if ((isNumeric(left) == true) && (isNumeric(right) == true)) return;
    throw new RuntimeError(expr.op, "Operands must be numbers.");
}

/* -----------------------------------------------------------------------------
 * isNumeric Description:
    Is a helper function for (checkNumberOperands) and (checkNumberOperands)
 * Arguments:
    * Type: Is a generic type that must have a concrete type during run time
 * Returns:
    True if the object at runtime is type: int, int64_t, float, double, etc.
    Otherwise, return false
 * ----------------------------------------------------------------------------
*/
bool binaryOperations::isNumeric(const Type& value) override {
    // TODO: Need to add more supported types here. refer to languages_types.h
    return value.type() == typeid(int) ||
           value.type() == typeid(int64_t) ||
           value.type() == typeid(float) ||
           value.type() == typeid(double);
}


/* -----------------------------------------------------------------------------------------------------------------------------------------------
 * isEqual Description: 
    Is a method that checks to see if one object equals the other
 * Arguments:
    * Visitor a: Is a generic type that must have a concrete type during run time, and will visit the binary abstract syntax tree left side (lh)
    * Visitor b: Is a generic type that must have a concrete type during run time, and will visit the binary abstract syntax tree right side (rh)
 * Returns:
    True if a and b are equal
    Otherwise, return false 
 * -----------------------------------------------------------------------------------------------------------------------------------------------
*/
bool binaryOperations::isEqual(auto& a, auto& b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL) return false;
    return a.equals(b);
}

/* ----------------------------
 *
 *
 *
 * ---------------------------
*/
Type binaryOperations::toNumeric(const Type& value) override {
    // explicit casting syntax is keywords<objec type>(user defined object)
    if (value.type() == typeid(int)) return static_cast<int>(value);
    if (value.type() == typeid(int64_t)) return static_cast<int64_t>(value);
    if (value.type() == typeid(float)) return static_cast<float>(value);
    if (value.type() == typeid(double)) return static_cast<double>(value);
    return NULL;
}


// return trailing type is a template called Binary 
auto binaryOperations::arithmeticOperations(Binary* expr, Binary& left, Binary& right) -> Binary {
    switch (expr->op->getType()) {
        case TokenType::PLUS:
            try {
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) + toNumeric(right); }
                if ((isString(left) == true) && (isString(right) == true)) { return (std::string)left + (std::string)right; }
            }
            catch(b->catcher("Something happened!")& e) {
                
                return NULL;
            }
            break;
        case TokenType::MINUS:
            try {if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) - toNumeric(right); }}
            catch(b->catcher("Something happened!")& e) {

                return NULL;
            }
            break;
        case TokenType::SLASH:
            try {if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) / toNumeric(right); }}
            catch(b->catcher("Something happened!")& e) {

            }
            break;
        case TokenType::STAR:
            try { if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) * toNumeric(right); }}
            catch(b->catcher("Something happened!")& e) {

                return NULL;
            }
            break;
        case TokenType::GREATER:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) > toNumeric(right); }
            }
            catch(b->catcher("Something happened!")& e) {

                return NULL;
            }
            break;
        case TokenType::GREATER_EQUAL:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) >= toNumeric(right); }
            } catch(b->catcher("Something happened!")& e) {

                return NULL;
            }
        case TokenType::LESS:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) < toNumeric(right); }
            } catch(b->catcher("Something happened!")& e) {

                return NULL;
            }
            break;
        case TokenType::LESS_EQUAL:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) <= toNumeric(right); }
            }
            catch(b->catcher("Something happened!")& e) {
            
                return NULL;
            }
            break;
        case TokenType::BANG_EQUAL: return !isEqual(left, right);
        case TokenType::EQUAL_EQUAL: return isEqual(left, right);
        default: return NULL;
    }
}

