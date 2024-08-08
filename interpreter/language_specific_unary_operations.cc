#include <language_specific_unary_operations.h>

/*
 *
*/
Vistor unaryOperations::Python(LanguageTypes& lang, Vistor& right) {
    if (auto val = static_cast<LanguageTypes::Python::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Python::Float>(&right))
        return -(*val);
}
/*
 *
*/

Visitor unaryOperations::JavaScript(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::JavaScript::Number>(&right))
        return -(*val);
}
/*
 *
*/
VisitorunaryOperations::Ruby(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Ruby::Integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Ruby::Float>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::C(LanguageTypes& lang, Visitor& right) {

}
/*
 *
*/
Visitor unaryOperations::CPP(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::CPP::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CPP::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Java(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Java::Integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Java::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Go(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Go::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Go::Float64>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Kotlin(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Kotlin::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Kotlin::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Kotlin::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Swift(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Swift::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Kotlin::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Rust(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Rust::i8>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Rust::i16)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::i32>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::i64>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::u8>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::u16>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::u32>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::u64>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::f32>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Rust::f64>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::CSharp(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::CSharp::byte>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::sbyte)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::short_>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::ushort>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::CSharp::int_)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::uint>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::long_>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::CSharp::ulong)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::float_>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::CSharp::double_>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::CSharp::decimal)((&right))
        return -(*val);
}
/*
 *
*/
Visitor LanguageTypes::FSharp(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::FSharp::int_>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::FSharp::float_)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::FSharp::double_>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::ObjectiveC(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::ObjectiveC::NSInteger>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::ObjectiveC::NSUInteger)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::ObjectiveC::CGFloat>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Scala(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Scala::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Scala::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Scala::Float>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Scala::Double)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::TypeScript(LanguageTypes& lang, Visitor& right) {
    // Need to add more support for typescript
    if (auto val = static_cast<LanguageTypes::TypeScript::number>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Dart(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Dart::int_>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Dart::double_)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::PHP(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::PHP::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::PHP::Float)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::R(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::R::Integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::R::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Lua(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Lua::Number>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::MATLAB(LanguageTypes& lang, Visitor& right) {
    // TODO: Add more support  
    if (auto val = static_cast<LanguageTypes::MATLAB::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::VBA(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::VBA::Byte>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::VBA::Integer)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::VBA::Long>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::VBA::Single>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::VBA::Double)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Groovy(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Groovy::Integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Groovy::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Groovy::Double>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Groovy::Float>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Julia(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Julia::Int64>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Julia::Float64)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::PowerShell(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::PowerShell::Int>(&right))
        return -(*val);
}
/*
 *
*/
Visitor LanguageTypes::VisualBasic(LanguageTypes& lang, Visitor& right) {
    // TODO: This needs to be redone
    if (auto val = static_cast<LanguageTypes::VisualBasic::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::VisualBasic::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::VisualBasic::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Dlang(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Haskell(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Haskell::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Haskell::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Erlang(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Erlang::Number>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Clojure(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Clojure::Number>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::StandardML(LanguageTypes& lang, Visitor& right) {
    // TODO: This needs to be redone
    if (auto val = static_cast<LanguageTypes::StandardML::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::StandardML::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::StandardML::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Elm(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::VHDLVerilog(LanguageTypes& lang, Visitor& right) {
    // TODO: This needs to be redone
    if (auto val = static_cast<LanguageTypes::VHDLVerilog::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::VHDLVerilog::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::VHDLVerilog::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Fortran(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Fortran::interger>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Fortran::real)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::COBOL(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::COBOL::numeric>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Pascal(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Pascal::integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Pascal::real)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Ada(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::Ada::integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Ada::Float)((&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Perl(LanguageTypes& lang, Visitor& right) {
    // TODO: This needs to be redone
    if (auto val = static_cast<LanguageTypes::Perl::Int>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::Perl::Long)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::Perl::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::AWK(LanguageTypes& lang, Visitor& right) {
    //TODO: Add support for AWK
}
/*
 *
*/
Visitor unaryOperations::TCL(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Shell(LanguageTypes& lang, Visitor& right) {
    throw std::runtime_error("Unary minus not supported in Shell");
}
/*
 *
*/
Visitor unaryOperations::LISPScheme(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::LISPScheme::Double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Racket(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Prolog(LanguageTypes& lang, Visitor& right) {
    throw std::runtime_error("Unary minus not supported in this context in Prolog");
}
/*
 *
*/
Visitor unaryOperations::Smalltalk(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::HTMLCSS(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::HTMLCSS::Number>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::SQL(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<LanguageTypes::SQL::Integer>(&right))
        return -(*val);
    if (auto val = static_cast<LanguagesTypes::SQL::Decimal)((&right))
        return -(*val);
    if (auto val = static_cast<LanguageTypes::SQL::Float>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::LabVIEW(LanguageTypes& lang, Visitor& right) {
    throw std::runtime_error("Unary minus not applicable in this context");
}
/*
 *
*/
Visitor unaryOperations::Eiffel(LanguageTypes& lang, Visitor& right) {
    if (auto val = static_cast<double>(&right))
        return -(*val);
}
/*
 *
*/
Visitor unaryOperations::Custom(LanguageTypes& lang, Visitor& right) {
    // TODO: This needs to be redone
    // This should be defined as a struct using templates for the objects to add flexibility 
}
