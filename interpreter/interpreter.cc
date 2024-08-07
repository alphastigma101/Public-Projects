#include <interpreter.h>
#include <stdexcept> // runtime_error can be used 
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
                    if (auto val = std::any_cast<LanguageTypes::Python::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Python::Float>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::JavaScript:
                    if (austo val = std::any_cast<LanguageTypes::JavaScript::Number>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Ruby:
                    if (auto val = std::any_cast<LanguageTypes::Ruby::Integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Ruby::Float>(&right))
                        return -(*val);
                     break;
                case LanguageTypes::C:
                case LanguageTypes::CPP:
                    if (auto val = std::any_cast<LanguageTypes::CPP::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CPP::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Java:
                    if (auto val = std::any_cast<LanguageTypes::Java::Integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Java::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Go:
                    if (auto val = std::any_cast<LanguageTypes::Go::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Go::Float64>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Kotlin:
                    if (auto val = std::any_cast<LanguageTypes::Kotlin::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Kotlin::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Kotlin::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Swift:
                    if (auto val = std::any_cast<LanguageTypes::Swift::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Kotlin::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Rust:
                    if (auto val = std::any_cast<LanguageTypes::Rust::i8>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Rust::i16)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::i32>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::i64>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::u8>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::u16>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::u32>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::u64>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::f32>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Rust::f64>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::CSharp:
                    if (auto val = std::any_cast<LanguageTypes::CSharp::byte>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::CSharp::sbyte)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CSharp::short_>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CSharp::ushort>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::CSharp::int_)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CSharp::uint>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CSharp::long_>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::CSharp::ulong)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CSharp::float_>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::CSharp::double_>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::CSharp::decimal)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::FSharp:
                    if (auto val = std::any_cast<LanguageTypes::FSharp::int_>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::FSharp::float_)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::FSharp::double_>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::ObjectiveC:
                    if (auto val = std::any_cast<LanguageTypes::ObjectiveC::NSInteger>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::ObjectiveC::NSUInteger)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::ObjectiveC::CGFloat>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Scala:
                    if (auto val = std::any_cast<LanguageTypes::Scala::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Scala::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Scala::Float>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Scala::Double)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::TypeScript:
                    // Need to add more support for typescript
                    if (auto val = std::any_cast<LanguageTypes::TypeScript::number>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Dart:
                    if (auto val = std::any_cast<LanguageTypes::Dart::int_>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Dart::double_)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::PHP:
                    if (auto val = std::any_cast<LanguageTypes::PHP::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::PHP::Float)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::R:
                    if (auto val = std::any_cast<LanguageTypes::R::Integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::R::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Lua:
                    if (auto val = std::any_cast<LanguageTypes::Lua::Number>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::MATLAB:
                   // TODO: Add more support  
                    if (auto val = std::any_cast<LanguageTypes::MATLAB::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::VBA:
                    if (auto val = std::any_cast<LanguageTypes::VBA::Byte>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::VBA::Integer)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::VBA::Long>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::VBA::Single>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::VBA::Double)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::Groovy: 
                    if (auto val = std::any_cast<LanguageTypes::Groovy::Integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Groovy::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Groovy::Double>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Groovy::Float>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Julia:
                    if (auto val = std::any_cast<LanguageTypes::Julia::Int64>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Julia::Float64)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::PowerShell:
                    if (auto val = std::any_cast<LanguageTypes::PowerShell::Int>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::VisualBasic:
                    // TODO: This needs to be redone
                    if (auto val = std::any_cast<LanguageTypes::VisualBasic::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::VisualBasic::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::VisualBasic::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Dlang:
                    if (auto val = std::any_cast<double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Haskell:
                    if (auto val = std::any_cast<LanguageTypes::Haskell::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Haskell::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Erlang:
                    if (auto val = std::any_cast<LanguageTypes::Erlang::Number>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Clojure:
                    if (auto val = std::any_cast<LanguageTypes::Clojure::Number>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::StandardML:
                    // TODO: This needs to be redone
                    if (auto val = std::any_cast<LanguageTypes::StandardML::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::StandardML::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::StandardML::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Elm:
                    if (auto val = std::any_cast<double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::VHDLVerilog:
                    // TODO: This needs to be redone
                    if (auto val = std::any_cast<LanguageTypes::VHDLVerilog::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::VHDLVerilog::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::VHDLVerilog::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Fortran:
                    if (auto val = std::any_cast<LanguageTypes::Fortran::interger>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Fortran::real)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::COBOL:
                    if (auto val = std::any_cast<LanguageTypes::COBOL::numeric>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Pascal:
                    if (auto val = std::any_cast<LanguageTypes::Pascal::integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Pascal::real)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::Ada:
                    if (auto val = std::any_cast<LanguageTypes::Ada::integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Ada::Float)((&right))
                        return -(*val);
                    break;
                case LanguageTypes::Perl:
                    // TODO: This needs to be redone
                    if (auto val = std::any_cast<LanguageTypes::Perl::Int>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::Perl::Long)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::Perl::Double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::AWK:
                    //TODO: Add support for AWK
                case LanguageTypes::TCL:
                    if (auto val = std::any_cast<double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Shell:
                    throw std::runtime_error("Unary minus not supported in Shell");
                case LanguageTypes::LISPScheme:
                    if (auto val = std::any_cast<LanguageTypes::LISPScheme::Double>(&right))
                        return -(*val);
                case LanguageTypes::Racket:
                    if (auto val = std::any_cast<double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Prolog:
                    throw std::runtime_error("Unary minus not supported in this context in Prolog");
                case LanguageTypes::Smalltalk:
                    if (auto val = std::any_cast<double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::HTMLCSS:
                    if (auto val = std::any_cast<LanguageTypes::HTMLCSS::Number>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::SQL:
                    if (auto val = std::any_cast<LanguageTypes::SQL::Integer>(&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguagesTypes::SQL::Decimal)((&right))
                        return -(*val);
                    if (auto val = std::any_cast<LanguageTypes::SQL::Float>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::LabVIEW:
                    throw std::runtime_error("Unary minus not applicable in this context");
                case LanguageTypes::Eiffel:
                    if (auto val = std::any_cast<double>(&right))
                        return -(*val);
                    break;
                case LanguageTypes::Custom:
                    // TODO: This needs to be redone
                    // This should be defined as a struct using templates for the objects to add flexibility 
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
