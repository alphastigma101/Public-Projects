#ifndef INTERFACE_H
#define INTERFACE_H

class interface {
    // This class is used to declare all the method signatures 
    // It will be inherited from other classes which will define them 
    public:
        //
    private:
        virtual bool consume(const char* literal) = 0; // Must be defined outside the class
        virtual char peek() = 0;
        virtual bool isAtEnd() = 0;
        virtual char advance() = 0;
        virtual void string() = 0;
        virtual void number() = 0;
        virtual char peekNext() = 0;
        virtual bool isAlpha(char c) = 0;
        virtual  bool isAlphaNumeric(char c) = 0;
};

#endif 
