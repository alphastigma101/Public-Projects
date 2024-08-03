#ifndef _INTERFACE_H_
#define _INTERFACE_H_
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
};

class Parsable {
    public:
        virtual ~Parsable() = default;
        virtual void String() = 0;
        virtual void number() = 0;
};

class Check {
    public:
        virtual ~Check() = default;
        virtual bool isAlpha(char c) = 0;
        virtual bool isAlphaNumeric(char c) = 0;
        virtual bool isDigit(char c) = 0;
    };

class Match {
    public:
        virtual bool match(char expected) = 0;

};

class Conversion {
    public:
        virtual ~Conversion() = default;
        virtual char* toString();
};
#endif 
