#ifndef INTERFACE_H
#define INTERFACE_H

class interface {
    // This class is used to declare all the method signatures 
    // It will be inherited from other classes which will define them 
    public:
        virtual bool consume(const char* literal) = 0; // Must be defined outside the class
}
