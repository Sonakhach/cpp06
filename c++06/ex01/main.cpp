#include "Serializer.hpp"

int main()
{
   Data data;
   data.member = 30;
   data.a = 10;

   uintptr_t  ptr = Serializer::serialize(&data);
   Data *dataPtr = Serializer::deserialize(ptr);
   std::cout << &data << std::endl;
    std::cout << &(dataPtr->member ) << std::endl;
    std::cout << ptr << std::endl;
    std::cout << dataPtr << std::endl;
   std::cout << &dataPtr << std::endl;
   std::cout << dataPtr->member << std::endl;
    std::cout << dataPtr->a << std::endl;
    std::cout << &dataPtr->a << std::endl;
    std::cout <<  dataPtr->a + 1 << std::endl;
    return 0;
}