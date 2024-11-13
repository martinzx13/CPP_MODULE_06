#include "ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &_other) {
  if (this != &_other)
    return;
}

ScalarConverter::~ScalarConverter() {}

bool stringToInt(const std::string &_value, int &_int, double &_double,
                 float &_float, char &_char) {
  bool longint = false;

  std::stringstream oss(_value);
  long long temp;
  oss >> temp;
  if (oss.fail() || !oss.eof())
    return (false);

  if (temp > std::numeric_limits<int>::max() ||
      temp < std::numeric_limits<int>::min()) {
    _int = '\0';
    longint = true;
  }
  if (!longint)
    _int = static_cast<int>(temp);
  _double = static_cast<double>(temp);
  _float = static_cast<float>(temp);
  if (temp >= 0 && temp <= 127)
    _char = static_cast<char>(_int);
  return (true);
}

bool stringToChar(const std::string &_value, char &_char, int &_int) {

  if (_value.size() == 1) {
    _char = _value[0];
    _int = (int)_value[0];
    return (true);
  }
  if (_value.size() == 2) {
    if (_value[0] == '\\') {
      switch (_value[1]) {
      case 'n':
        _char = '\n';
        _int = static_cast<int>(_char);
        return (true);
      case 't':
        _char = '\t';
        _int = static_cast<int>(_char);
        return (true);
      case 'r':
        _char = '\r';
        _int = static_cast<int>(_char);
        return (true);
      case 'b':
        _char = '\b';
        _int = static_cast<int>(_char);
        return (true);
      case 'f':
        _char = '\f';
        _int = static_cast<int>(_char);
        return (true);
      case 'v':
        _char = '\v';
        _int = static_cast<int>(_char);
        return (true);
      case 'a':
        _char = '\a';
        _int = static_cast<int>(_char);
        return (true);
      default:
        return (false);
      }
    }
  }
  return false;
}
bool stringToFloat(const std::string &_value, float &_float, double &_double,
                   int &_int, char &_char) {
  if (_value.find('.') == std::string::npos ||
      _value.find('f') != _value.size() - 1) {
    return false;
  }

  std::string newFloat = _value.substr(0, _value.size() - 1);
  std::stringstream oss(newFloat);
  oss >> _float;
  if (_value.find('.') == std::string::npos)
    return false;
  if (oss.fail() || !oss.eof()) {
    return false;
  }
  _double = _float;
  _int = static_cast<int>(_double);
  if (_int >= 0 && _int <= 127)
    _char = static_cast<char>(_int);
  return (true);
}

bool stringToDouble(const std::string &_value, double &_double, float &_float,
                    int &_int, char &_char) {

  std::stringstream oss(_value);

  if ((_value.size() - 1) == _value.find('.'))
    return false;
  oss >> _double;

  if (oss.fail() || !oss.eof())
    return (false);

  _float = _double;
  _int = _double;
  if (_int >= 0 && _int <= 127)
    _char = static_cast<char>(_int);
  return (true);
}
void ScalarConverter::convert(const std::string &_value) {
  // bool find = false;
  int _int = 0;
  char _char = '\0';
  float _float;
  double _double;

  if (stringToInt(_value, _int, _double, _float, _char)) {
    stringToIntPrint(_char, _int, _double, _float);
  }
  else if (stringToChar(_value, _char, _int)) {
    stringToCharPrint(_int, _float, _double, _char);
  } else if (stringToFloat(_value, _float, _double, _int, _char)) {
    stringToFloatPrint(_value, _int, _float, _double, _char);
  } else if (stringToDouble(_value, _double, _float, _int, _char)) {

    stringToDoublePrint(_int, _float, _double, _char);

  } else {
    defaultCase();
  }
}
