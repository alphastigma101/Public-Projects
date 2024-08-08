#include <language_specific_truthy_operations.h>



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
bool truthyOperations::isTruthy(const Type& object) {
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

