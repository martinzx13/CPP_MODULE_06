#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>
#include <string>
#include <unistd.h>
#include <typeinfo>

Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3;
    std::cout << GREEN << "Generating a Random Number : 🎲🎲🎲🎲" << RESET << std::endl;
    if (random == 0)
    {
        return new A();
    }
    else if (random == 1)
    {
        return new B();
    }
    else
    {
        return new C();
    }
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << YELLOW << "Result : A" << RESET << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << RED << "Result : B" << RESET << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << MAGENTA << "Result : C" << RESET << std::endl;
    }
}
void identify(Base &p)
{
    try{
        (void) dynamic_cast<A &>(p);
        std::cout << YELLOW << "Result : A" << RESET << std::endl;
    }catch(const std::bad_cast&)
    {
    }
    try{
        (void) dynamic_cast<B &>(p);
        std::cout << RED << "Result : B" << RESET << std::endl;
    }catch(const std::bad_cast&)
    {
    }
    try{
       (void)  dynamic_cast<C &>(p);
        std::cout << MAGENTA << "Result : C" << RESET << std::endl;
    }catch(const std::bad_cast&)
    {
    }
}
int main()
{
    A a;
    B b;
    C c;
    std::cout << "Hello please guess the type of the object" << std::endl;
    std::cout << "A, B, C" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    Base *base = generate();
    if (base)
    {
        std::cout << BLUE << "___________Your guess is : ________________\n"
                  << RESET << std::endl;
        if (input == "A")
        {
            identify(&a);
        }
        else if (input == "B")
        {
            identify(&b);
        }
        else if (input == "C")
        {
            identify(&c);
        }
        std::cout << GREEN << "___________The random object Pointer :__________\n"
                  << RESET << std::endl;
        identify(base);

        std::cout << GREEN << "___________The random object Reference :__________\n" << RESET << std::endl;
        identify(*base);

        delete (base);
    }
    return 0;
}