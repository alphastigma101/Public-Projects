#include <interpreter.h>
/* -------------------------------------------------------------------------------------------------------------------------
 * visitUnaryExpr Description: 
    Is a method that visits the unary abstract syntax tree
 * Arguments:
    * Visitor: Is a generic type that must have a concrete type during run time and will visit the abstraction syntax tree
 * Returns:
    A Unary abstraction tree syntax node
 * -------------------------------------------------------------------------------------------------------------------------   
*/
auto interpreter::visitUnaryExpr(Visitor* expr) -> Any {
    auto right = evaluate(expr->right);
    switch (expr->op->getType()) {
        case TokenType::BANG:
            return !isTruthy(right);
        case TokenType::MINUS:
            checkNumberOperand(expr->op, *right);
            switch(currentLanguage) {
                case LanguageTypes::Python:
                    return u-Python(LanguageTypes::Python, right);
                case LanguageTypes::JavaScript:
                    return u-JavaScript(LanguageTypes::JavaScript, right);
                case LanguageTypes::Ruby:
                    return u-Ruby(LanguageTypes::Ruby, right);
                case LanguageTypes::C:
                    return u-C(LanguageTypes::C, right);
                case LanguageTypes::CPP:
                    return u-CPP(LanguageTypes::CPP, right);
                case LanguageTypes::Java:
                    return u-Java(LanguageTypes::Java, right);
                case LanguageTypes::Go:
                    return u-Go(LanguageTypes::Go, right);
                case LanguageTypes::Kotlin:
                    return u-Kotlin(LanguageTypes::Kotlin, right);
                case LanguageTypes::Swift:
                    return u-Swift(LanguageTypes::Swift, right);
                case LanguageTypes::Rust:
                    return u-Rust(LanguageTypes::Rust, right);
                case LanguageTypes::CSharp:
                    return u-CSharp(LanguagesTypes::CSharp, right);
                case LanguageTypes::FSharp:
                    return u-FSharp(LanguageTypes::FSharp, right);
                case LanguageTypes::ObjectiveC:
                    return u-ObjectiveC(LanguageTypes::ObjectiveC, right);
                case LanguageTypes::Scala:
                    return u-Scala(LanguageTypes::Scala, right);
                case LanguageTypes::TypeScript:
                    return u-TypeScript(LanguageTypes::TypeScript, right);
                case LanguageTypes::Dart:
                    return u-Dart(LanguageTypes::Dart, right);
                case LanguageTypes::PHP:
                    return u-PHP(LanguageTypes::PHP, right);
                case LanguageTypes::R:
                    return u-R(LanguageTypes::R, right);
                case LanguageTypes::Lua:
                    return u-Lua(LanguageTypes::Lua, right);
                case LanguageTypes::MATLAB:
                    return u-MATLAB(LanguageTypes::MATLAB, right);
                case LanguageTypes::VBA:
                    return u-VBA(LanguageTypes::VBA, right);
                case LanguageTypes::Groovy: 
                    return u-Groovy(LanguageTypes::Groovy, right);
                case LanguageTypes::Julia:
                    return u-Julia(LanguageTypes::Julia, right);
                case LanguageTypes::PowerShell:
                    return u-PowerShell(LanguageTypes::PowerShell, right);
                case LanguageTypes::VisualBasic:
                    return u-VisualBasic(LanguageTypes::VisualBasic, right);
                case LanguageTypes::Dlang:
                    return u-Dlang(LanguageTypes::Dlang, right);
                case LanguageTypes::Haskell:
                    return u-Haskell(LanguageTypes::Haskell, right);
                case LanguageTypes::Erlang:
                    return u-Erlang(LanguageTypes::Erlang, right);
                case LanguageTypes::Clojure:
                    return u-Clojure(LanguageTypes::Clojure, right);
                case LanguageTypes::StandardML:
                    return u-StandardML(LanguageTypes::StandardML, right);
                case LanguageTypes::Elm:
                    return u-Elm(LanguageTypes::Elm, right);
                case LanguageTypes::VHDLVerilog:
                    return u-VHDLVerilog(LanguageTypes::VHDLVerilog, right);
                case LanguageTypes::Fortran:
                    return u-Fortran(LanguageTypes::Fortran, right);
                case LanguageTypes::COBOL:
                    return u-COBOL(LanguageTypes::COBOL, right);
                case LanguageTypes::Pascal:
                    return u-Pascal(LanguageTypes::Pascal, right);
                case LanguageTypes::Ada:
                    return u-Ada(LanguageTypes::Ada, right);
                case LanguageTypes::Perl:
                    return u-Perl(LanguageTypes::Perl, right);
                case LanguageTypes::AWK:
                    return u-AWK(LanguageTypes::AWK, right);
                case LanguageTypes::TCL:
                    return u-TCL(LanguageTypes::TCL, right);
                case LanguageTypes::Shell:
                    return u-Shell(LanguageTypes::Shell, right);
                case LanguageTypes::LISPScheme:
                    return u-LISPScheme(LanguageTypes::LISPScheme, right);
                case LanguageTypes::Racket:
                    return u-Racket(LanguageTypes::Racket, right);
                case LanguageTypes::Prolog:
                    return u-Prolog(LanguageTypes::Prolog, right);
                case LanguageTypes::Smalltalk:
                    return u-SmallTalk(LanguageTypes::SmallTalk, right);
                case LanguageTypes::HTMLCSS:
                    return u-HTMLCSS(LanguageTypes::HTMLCSS, right);
                case LanguageTypes::SQL:
                    return u-SQL(LanguageTypes::SQL, right);
                case LanguageTypes::LabVIEW:
                    return u-LabVIEW(LanguageTypes::LabVIEW, right);
                case LanguageTypes::Eiffel:
                    return u-Eiffel(LanguageTypes::Eiffel, right);
                case LanguageTypes::Custom:
                    // TODO: This needs to be redone
                    // This should be defined as a struct using templates for the objects to add flexibility 
                    return u-Custom(LanguageTypes::Custom, right);
                default:
                    throw std::runtime_error("Operand must be a number.");           
            }
        }
        throw std::runtime_error("Operand must be a number.");
    }
    // Unreachable.
    return NULL;
}
/* --------------------------------------------------------------------------------------------------------------------
 * visitBinaryExpr Description: 
    Is a method that visits the Binary abstraction syntax tree 
 * Arguments:
    * Visitor: Is a generic type that must have a concrete type during run time and the tree it will visit at run time
 * Returns:
    A Binary abstraction syntax tree node 
 * --------------------------------------------------------------------------------------------------------------------
*/
auto interpreter::visitBinaryExpr(Visitor* expr) -> Any {
    // In go, := makes a object. It must be represented in c++ as = 
    auto left = evaluate(expr->left);
    auto right = evaluate(expr->right);
    switch (currentLanguage) {
        case LanguageTypes::Python:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::JavaScript:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Ruby:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::C:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::CPP:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Java:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Go:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Kotlin:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Swift:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Rust:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::CSharp:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::FSharp:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::ObjectiveC:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Scala:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::TypeScript:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Dart:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::PHP:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::R:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Lua:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::MATLAB:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::VBA:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Julia:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::PowerShell:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::VisualBasic:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Dlang:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Haskell:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Erlang:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Clojure:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::StandardML:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Elm:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::VHDLVerilog:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Fortran:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::COBOL:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Pascal:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Ada:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Perl:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::AWK:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            //TODO: Add support for AWK
            break;
        case LanguageTypes::TCL:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Shell:
            throw std::runtime_error("Unary minus not supported in Shell");
        case LanguageTypes::LISPScheme:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Racket:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Prolog:
            throw std::runtime_error("Unary minus not supported in this context in Prolog");
        case LanguageTypes::Smalltalk:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::HTMLCSS:
           evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::SQL:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::LabVIEW:
            throw std::runtime_error("Unary minus not applicable in this context");
        case LanguageTypes::Eiffel:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            break;
        case LanguageTypes::Custom:
            evaluateBinaryTokens(currentLanguage, expr, left, right);
            // TODO: This needs to be redone
            // This should be defined as a struct using templates for the objects to add flexibility 
            break;
        default:
            throw std::runtime_error("Operand must be a number.");           
    }
    // Unreachable.
    return NULL;
}
/* ---------------------------------------------------------------------------------------------------------
 * isTruthy Description: 
    Is a method that will return an concrete type if the language the user specifies supports truthy/falsy
 * Arguments:
    * Type: Is a generic type that must have a concrete type during run time
 * Returns:
    True if the object was successfully casted into a c++ supported type 
    Otherwise, return false 
 * ---------------------------------------------------------------------------------------------------------
*/
bool interpreter::isTruthy(const Type& object) {
    switch(currentLanguage) {
        case LanguageTypes::Python:
            if (std::any_cast<LanguageTypes::Python::None>(&object) != nullptr) return false;
            if (auto b = std::any_cast<LanguageTypes::Python::Bool>(&object)) return *b;
            break;
        case LanguageTypes::JavaScript:
            if (std::any_cast<LanguageTypes::JavaScript::Null>(&object) != nullptr) return false;
            if (std::any_cast<LanguageTypes::JavaScript::Undefined>(&object) != nullptr) return false;
            if (auto b = std::any_cast<LanguageTypes::JavaScript::Boolean>(&object)) return *b;
            break;
        //TODO: handle other languages here
    }
    return true;
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
bool interpreter::isEqual(Visitor& a, Visitor& b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL) return false;
    return a.equals(b);
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------
 * checkNumberOperand Description: 
    Is a method that calls in isNumeric, the helper function
 * Arguments:
    * Visitor expr: It is an object that represents the abstraction syntax, (ast) that is currently being used. In this case, it would be the Unary ast
    * Visitor right: Is a generic type that must have a concrete type during run time, and will visit the unary abstract syntax tree right side (rh)
 * Returns:
    True if a and b are equal
    Otherwise, return false 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------
*/
void interpreter::checkNumberOperand(Visitor& expr, Visitor& right) {
    if (isNumeric(right) == true) return;
    throw new RuntimeError(expr.op, "Operand must be numeric.");

}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------
 * checkNumberOperands Description: 
    Is a method that calls in isNumeric, the helper function
 * Arguments:
    * Visitor expr: It is an object that represents the abstraction syntax, (ast) that is currently being used. In this case, it would be the Binary ast
    * Visitor left: Is a generic type that must have a concrete type during run time, and will visit the binary abstract syntax tree left side (lh)
    * Visitor right: Is a generic type that must have a concrete type during run time, and will visit the binary abstract syntax tree right side (rh)
 * Returns:
    True if a and b are equal
    Otherwise, return false 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------
*/
void interpreter::checkNumberOperands(Visitor& expr, Vistor& left, Visitor& right) {
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
bool interpreter::isNumeric(const Type& value) override {
    // TODO: Need to add more supported types here. refer to languages_types.h 
    return value.type() == typeid(int) ||
           value.type() == typeid(int64_t) ||
           value.type() == typeid(float) ||
           value.type() == typeid(double);
}
/* ----------------------------
 *
 *
 *
 * ---------------------------
*/
Type interpreter::toNumeric(const Type& value) override {
    if (value.type() == typeid(int)) return std::any_cast<int>(value);
    if (value.type() == typeid(int64_t)) return std::any_cast<int64_t>(value);
    if (value.type() == typeid(float)) return std::any_cast<float>(value);
    if (value.type() == typeid(double)) return std::any_cast<double>(value);
    throw std::runtime_error("Invalid numeric type");
}
/* ---------------------------
 *
 *
 * ---------------------------
*/
auto interpreter::evaluateBinaryTokens(LanguageTypes& currentLanguage, Visitor* expr, Visitor& left, Visitor& right) -> Any {
    switch (expr->op->getType()) {
        case TokenType::PLUS:
            try {
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) + toNumeric(right); }
                if ((isString(left) == true) && (isString(right) == true)) { return (std::string)left + (std::string)right; }
            } 
            catch() {}
            break;
        case TokenType::MINUS:
            try {if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) - toNumeric(right); }} 
            catch() {}
            break;
        case TokenType::SLASH:
            try {if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) / toNumeric(right); }}
            catch() {}
            break;
        case TokenType::STAR:
            try { if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) * toNumeric(right); }}
            catch() {}
            break;
        case TokenType::GREATER:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) > toNumeric(right); }
            } 
            catch() {}
            break;
        case TokenType::GREATER_EQUAL:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) >= toNumeric(right); }
            } catch() {}
        case TokenType::LESS:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) < toNumeric(right); }
            } catch() {}
            break;
        case TokenType::LESS_EQUAL:
            try {
                checkNumberOperands(expr->op, left, right);
                if ((isNumeric(left) == true) && (isNumeric(right) == true)) { return toNumeric(left) <= toNumeric(right); }
            }
            catch() {}
            break;
        case TokenType::BANG_EQUAL: return !isEqual(left, right);
        case TokenType::EQUAL_EQUAL: return isEqual(left, right);
        default: throw std::runtime_error("Operand must be a number."); 
    }
}
