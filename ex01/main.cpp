#include "Serializer.hpp"

int main()
{
    Data data;
    data.data = 42;
    uintptr_t serialized = Serializer::serialize(&data);
    Data *deserialized = Serializer::deserialize(serialized);
    if (deserialized == &data)
    {
        return 0;
    }
    return 1;
}