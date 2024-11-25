#include "Serializer.hpp"

int main()
{
    Data data;
    data.data = 42;
    uintptr_t serialized = Serializer::serialize(&data);
    uintptr_t serialized2 = uintptr_t(&data);

    Data *deserialized = Serializer::deserialize(serialized);
    if (deserialized == &data && serialized == serialized2)
    {
        std::cout << GREEN  << "Success" << std::endl;
        std::cout << YELLOW << "Data: Original  : " << &data << std::endl;
        std::cout << BLUE   << "Data Serialized : " << deserialized << RESET << std::endl;
        return 0;
    }
    return 1;
}