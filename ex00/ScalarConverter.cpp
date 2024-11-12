#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>
#include <limits.h>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &_other) {
  if (this != &_other)
    return;
}

ScalarConverter::~ScalarConverter() {}

bool stringToInt(const std::string &_value, int &_int) {

  if (_value.size() == 1) {
    _int = static_cast<char>(_value[0]);
    throw(_value[0]);
  }
  std::stringstream oss(_value);

  oss >> _int;

  if (oss.fail() || !oss.eof())
    return (false);
  return (true);
}

bool stringToChar(const int &_value, char &_char) {

  _char = static_cast<char>(_value);
  if (_char)
    return true;
  return false;
}
void ScalarConverter::convert(const std::string &_value) {
  int _int;
  //   char _char;
  //   float _float;
  //   double _double;

  try {

    if (stringToInt(_value, _int))
      std::cout << "int : " << _int << std::endl;
    // : std::cout << "int : " << "Impossible Conversion 🗿" << std::endl;
  } catch (int value) {
    std::cerr << "Error ::: " << value << std::endl;
  } catch (char const *err) {
    std::cerr << "Error ::" << err << std::endl;
  } catch (char const err) {
    std::cerr << "Err : : : " << err << std::endl;
  }
}