# ScalarConverter

## Overview

`ScalarConverter` is a C++ program that converts a string representation of a C++ literal into its corresponding scalar types: `char`, `int`, `float`, and `double`. The program handles various forms of literals, including special cases like non-displayable characters and pseudo literals (`nan`, `+inf`, `-inf`, `nanf`, `+inff`, `-inff`).

## Features

- Converts string representations of literals to `char`, `int`, `float`, and `double`.
- Handles special cases for non-displayable characters.
- Supports pseudo literals for `float` and `double`.
- Provides informative messages for impossible conversions.

## Usage

To use the `ScalarConverter`, simply call the static `convert` method with a string representation of a literal.

### Example

```cpp
#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("42");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("a");
    ScalarConverter::convert("\\n");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");

    return 0;
}
```
