#include "ScalarConverter.hpp"
#include <exception>

int main(int argc, char *argv[]) {
  if (argc == 1)
    return (1);

  try {

    ScalarConverter::convert(argv[1]);

  } catch (std::exception &e) {
    std::cerr << "Error : " << e.what() << std::endl;
  }
}