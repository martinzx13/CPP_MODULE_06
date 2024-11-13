#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iomanip>

// Define RGB color values
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define CHAR(c) ("char   : " + std::string(1, c))
#define NCHAR "char   : Non printable"
#define ICON "char   : Impossible conversion"
#define ICONI "int    : Impossible conversion"
#define ICONF "float  : Impossible conversion"
#define ICOND "double : Impossible conversion"

#define INT "Int    : "
#define FLOAT "Float  : "
#define DOUBLE "Double : "

#include <iostream>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &_other);
  ScalarConverter &operator=(const ScalarConverter &_other);
  ~ScalarConverter();

public:
  static void convert(const std::string &_value);
};
void specialCases(std::string const &_value);
void defaultCase();
void stringToDoublePrint(int _int, float _float, double _double, char _char);
void stringToFloatPrint(std::string _value, int _int, char _char,
                        double _double, float _float);
void stringToIntPrint(char _char, int _int, double _double, float _float);
void stringToCharPrint(int _int, float _float, double _double, char _char);
#endif
