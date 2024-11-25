#ifndef BASE_HPP
#define BASE_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"

#include <stdint.h>
#include <iostream>
#include <cstdlib>

class Base {
    public :
    virtual ~Base();
};

#endif