#include "Base.hpp"
#include <exception>
// #include <cstdlib>
// #include <time.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    srand(time(NULL));
    Base *tmp ;
    int a = rand() % 3;

    switch (a)
    {
    case 0:
        tmp = new A();
        std::cout << "A" << std::endl;
        return(tmp);
    case 1:
         tmp = new B();
         std::cout << "B" << std::endl;
        return(tmp);
    case 2:
        tmp = new C();
        std::cout << "C" << std::endl;
        return(tmp);
    default:
        std::cout << "error" << std::endl;
        break;

   }
return(NULL);
}

void identify(Base* p)
{
    A * tmpA = dynamic_cast<A*>(p);
    B * tmpB = dynamic_cast<B*>(p);
    C * tmpC = dynamic_cast<C*>(p);
    if (tmpA != NULL)
    {
        std::cout << "Base* caste to A* successfully" << std::endl;
        return;
    }
    if (tmpB != NULL)
    {
        std::cout << "Base* caste to B* successfully" << std::endl;
        return;
    }
    if (tmpC != NULL)
    {
        std::cout << "Base* caste to C* successfully" << std::endl;
        return;
    }
    else
    {
        std::cout << "error" << std::endl;
    }
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Base* caste to A& successfully" << std::endl;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Base* caste to B& successfully" << std::endl;
        return;
    }
    catch(const std::exception& e){};
    try
    {
        (void)dynamic_cast<C&>(p);
         std::cout << "Base* caste to C& successfully" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    
}

int main()
{
    Base * data;
     data = generate();
     identify(data);
     identify(*data);
    return 0;
}