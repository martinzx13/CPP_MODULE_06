#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>

void defaultCase() {
  std::cout << RED << ICON << RESET << std::endl;
  std::cout << RED << ICONI << RESET << std::endl;
  std::cout << RED << ICONF << RESET << std::endl;
  std::cout << RED << ICOND << RESET << std::endl;
}

bool hasZeroAfterDecimal(float value) {
  std::ostringstream oss;
  oss << value;
  std::string valueStr = oss.str();
  size_t decimalPointPos = valueStr.find('.');
  if (decimalPointPos != std::string::npos) {
    return true;
  }
  return false;
}

void specialCases(std::string const &_value) {
  if (_value == "nanf" || _value == "nan") {
    std::cout << RED << ICON << std::endl;
    std::cout << RED << ICONI << std::endl;
    std::cout << YELLOW << FLOAT << "nanf" << std::endl;
    std::cout << BLUE << DOUBLE << "nan" << std::endl;
  } else if (_value == "+inf" || _value == "-inf") {
    std::cout << RED << ICON << std::endl;
    std::cout << RED << ICONI << std::endl;
    std::cout << YELLOW << FLOAT << _value[0] << "inf" << std::endl;
    std::cout << BLUE << DOUBLE << _value[0] << "inf" << std::endl;
  }
}

void stringToIntPrint(char _char, int _int, double _double, float _float) {
  if (!_char && !_int)
    std::cout << RED << ICON << std::endl;
  else if (std::isprint(_char) == false)
    std::cout << CYAN << NCHAR << std::endl;
  else
    std::cout << CHAR(_char) << std::endl;
  (_int == '\0') ? std::cout << RED << ICON << std::endl
                 : std::cout << INT << _int << std::endl;
  std::cout << YELLOW << FLOAT << _float << ".0f" << std::endl;
  std::cout << BLUE << DOUBLE << _double << ".0" << std::endl;
}
void stringToCharPrint(int _int, float _float, double _double, char _char) {
  if (std::isprint(_char) == false)
    std::cout << CYAN << NCHAR << std::endl;
  else
    std::cout << CHAR(_char) << std::endl;
  std::cout << INT << _int << std::endl;
  _float = static_cast<float>(_int);
  _double = static_cast<double>(_int);
  std::cout << YELLOW << FLOAT << _float << "f" << std::endl;
  std::cout << BLUE << DOUBLE << _double << std::endl;
}

void stringToDoublePrint(int _int, float _float, double _double, char _char) {
  if (std::isprint(_char) == false)
    std::cout << RED << NCHAR << RESET << std::endl;
  else if (!_char)
    std::cout << RED << ICON << RESET << std::endl;
  else
    std::cout << GREEN << CHAR(_char) << RESET << std::endl;
  std::cout << RED << INT << RESET << _int << std::endl;
  hasZeroAfterDecimal(_float)
      ? std::cout << YELLOW << FLOAT << RESET << _float << "f" << std::endl
      : std::cout << YELLOW << FLOAT << RESET << _float << ".0f" << std::endl;
  std::cout << BLUE << DOUBLE << RESET << _double << std::endl;
}

void stringToFloatPrint(std::string _value, int _int, char _char,
                        double _double, float _float) {
  int pres = _value.size() - _value.find('.') - 2;
  std::cout << std::fixed << std::setprecision(pres);
  if (std::isprint(_char) == false)
    std::cout << NCHAR << std::endl;
  else if (!_char)
    std::cout << ICON << std::endl;
  else
    std::cout << CHAR(_char) << std::endl;
  std::cout << INT << _int << std::endl;
  if (pres == 0)
    std::cout << FLOAT << _float << ".0f" << std::endl;
  else
    std::cout << YELLOW << FLOAT << _float << "f" << std::endl;
  std::cout << BLUE << DOUBLE << _double << std::endl;
}