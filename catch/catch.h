#ifndef _CATCH_H_
#define _CATCH_H_
#include <exception>

class catcher: public std::exception {
    public:
        catcher(const *char message): messge(this->message) {}; // Do not allow implicit conversions or copying 
        ~catcher() {};
        inline char * what () { return message; };
    private:
        const *char message;
};

#endif
