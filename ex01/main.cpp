#include "Serializer.hpp"

int main()
{
    Data data;
    data.data = 42;

    Data data1;
    data1.data = 24;

    uintptr_t serialized1 = Serializer::serialize(&data1);
    uintptr_t serialized = Serializer::serialize(&data);
    uintptr_t serialized2 = uintptr_t(&data);

    Data *deserialized = Serializer::deserialize(serialized);
    Data *deserialized1 = Serializer::deserialize(serialized1);

    if (deserialized == &data && serialized == serialized2)
    {
        std::cout << GREEN  << "Success" << std::endl;
        std::cout << YELLOW << "Data: Original  : " << &data << std::endl;
        std::cout << BLUE   << "Data Serialized : " << deserialized << RESET << std::endl;
    }

    if (deserialized1 == &data1 && serialized1 == serialized2)
    {
        std::cout << GREEN  << "Success" << std::endl;
        std::cout << YELLOW << "Data: Original  : " << &data << std::endl;
        std::cout << BLUE   << "Data Serialized : " << deserialized << RESET << std::endl;
    }
    else {
        std::cout << RED << "Error data are not the same is different" << std::endl;
        std::cout << YELLOW << "Data: Original  : " << &data << std::endl;
        std::cout << BLUE   << "Data Serialized : " << deserialized1 << RESET << std::endl;
    }
    return 1;
}