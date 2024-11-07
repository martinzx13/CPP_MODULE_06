#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
private:
  int _int;
  float _float;
  double _double;

  ScalarConverter();
  ScalarConverter(const ScalarConverter &_other);
  ScalarConverter &operator=(const ScalarConverter &_other);
  ~ScalarConverter();

public:
  static void convert(const std::string &_value);
};
#endif

void stringToInt(const std::string &value, int &_int);