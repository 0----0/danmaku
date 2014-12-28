#include <exception>
#include <iostream>

#pragma once

class initError : public std::exception {
private:
        const std::string errString;
public:
        virtual const char* what() const noexcept override { return errString.c_str(); }
        initError(const std::string errString) :
                errString(errString) {
                std::cout << errString << std::endl;
        }
};
