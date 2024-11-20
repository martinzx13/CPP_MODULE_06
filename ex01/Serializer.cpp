#include "Serializer.hpp"

//_____________ COnstructor _______________

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

//_____________ Copy _______________
Serializer::Serializer(const Serializer &_oter)
{
    *this = _oter;
}

//_____________ Operator _______________

Serializer &Serializer::operator=(const Serializer &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

//_____________ Methods _______________

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}