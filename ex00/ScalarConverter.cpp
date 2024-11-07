#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &_other){}

ScalarConverter::~ScalarConverter(){}

void stringToInt(const std::string &_value, int &_int)
{

}
void ScalarConverter::convert(const std::string &_value)
{
    int numb;

    stringToInt(_value, numb);
    _int = numb;
}