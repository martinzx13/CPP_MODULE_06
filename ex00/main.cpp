#include "ScalarConverter.hpp"
#include <exception>

int main(int argc, char *argv[]) {
  if (argc == 1)
    return (1);

  try {

    std::cout << GREEN << "_____TEST  42__________\n" << RESET << std::endl;
    ScalarConverter::convert("42");
    std::cout << GREEN << "_____TEST 42.0f __________\n" << RESET << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << GREEN << "_____TEST 42.0 __________\n" << RESET << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << GREEN << "_____TEST nan __________\n" << RESET << std::endl;
    ScalarConverter::convert("nan");
    std::cout << GREEN << "_____TEST +inf__________\n" << RESET << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << GREEN << "_____TEST -inf__________\n" << RESET << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << GREEN << "_____TEST " << argv[1] << " __________" << RESET
              << std::endl;
    ScalarConverter::convert(argv[1]);
  } catch (std::exception &e) {
    std::cerr << "Error : " << e.what() << std::endl;
  }
}