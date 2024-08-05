#include <interpreter.h>
#include <stdexcept> // runtime_error can be used 

auto interpreter::visitUnaryExpr(VisitorType* expr) -> Any {
    Any right = evaluate(expr->right);
    switch (expr->op->getType()) {
        case TokenType::BANG:
            return !isTruthy(right);
        case TokenType::MINUS:
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

auto interpreter::visitBinaryExpr(VisitorType* expr) -> Any {
    // In go, := makes a object. It must be represented in c++ as = 
    auto left = evaluate(expr->left);
    auto right = evaluate(expr->right);

    switch (expr->op->getType()) {
        case TokenType::PLUS:
            if (left instanceof Double && right instanceof Double) {
                return (double)left + (double)right;
            }
            if (left instanceof String && right instanceof String) {
                return (String)left + (String)right;
            }
            break;
        case TokenType::MINUS:
            return (double)left - (double)right;
        case TokenType::SLASH:
            return (double)left / (double)right;
        case TokenType::STAR:
            return (double)left * (double)right;
        case TokenType::GREATER:
            return (double)left > (double)right;
        case TokenType::GREATER_EQUAL:
            return (double)left >= (double)right;
        case TokenType::LESS:
            return (double)left < (double)right;
        case TokenType::LESS_EQUAL:
            return (double)left <= (double)right;
        case TokenType::BANG_EQUAL: return !isEqual(left, right);
        case TokenType::EQUAL_EQUAL: return isEqual(left, right);

    }
    // Unreachable.
    return NULL;
}

bool interpreter::isTruthy(const Any& object) {
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
        // ... handle other languages ...
    }
    return true;
}

template<class Type>
bool interpreter::isEqual(Type& a, Type& b) {
    if (a == null && b == NULL) return true;
    if (a == NULL) return false;
    return a.equals(b);
}
