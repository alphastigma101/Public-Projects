#ifndef _INTERFACE_H_
#define _INTERFACE_H_

/*
 * Keeping this code around, because it might be useful for the compiler or later on
 class Peek {
    public:
        virtual ~Peek() = default;
        virtual char peek() = 0;
        virtual char peekNext() = 0;
};

class End {
    public:
        virtual ~End() = default;
        virtual bool isAtEnd() = 0;
};

class Advance {
    public:
        virtual ~Advancable() = default;
        virtual char advance() = 0;
};*/

class NonMemberConv {
    // An abstract class used for converting object types that are not a member object of the class 
    public:
        virtual ~Convert() = default;
        template<class Type>
        virtual Type toNumeric(const Type& value) = 0;
        virtual char* toString(const Type& left, const Type& right) = 0;
};

class Check {
    public:
        template<class Type>
        virtual ~Check() = default;
        virtual bool isNumeric(const Type& value) = 0; 
        virtual bool isString(const Type& value) = 0;
};
/*
 * Same with this abstract class
class Match {
    public:
        virtual bool match(char expected) = 0;

};*/

class MemberConv {
    // An abstract class is used to convert member types of a class object into a string 
    public:
        virtual ~MemberConv() = default;
        virtual char* toString() = 0;
};
#endif 
