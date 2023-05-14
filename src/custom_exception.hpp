#ifndef EXCEPTION_HEADERFILE
#define EXCEPTION_HEADERFILE

#include <exception>
#include <string>

class CustomException : public std::exception {
private:
    std::string err_message;
public:
    CustomException(std::string msg) {
        err_message = msg;
    }
    const char* what() const throw() {
        return err_message.c_str();
    }
};

#endif