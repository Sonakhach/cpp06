#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
typedef struct Data
{
    int member;
    int a;

}  Data;

class Serializer
{
public:
    static Data* deserialize(uintptr_t raw);
    static uintptr_t serialize(Data* ptr);
    
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer&operator=(const Serializer&);
    ~Serializer();

};




#endif