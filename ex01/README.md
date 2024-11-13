# Serializer

## Overview

`Serializer` is a C++ class that provides static methods to serialize and deserialize pointers to a `Data` structure. The class is designed to be non-instantiable by the user. The `serialize` method converts a pointer to an unsigned integer type `uintptr_t`, and the `deserialize` method converts an unsigned integer back to a pointer to `Data`.

## Features

- Serialize a pointer to an unsigned integer type `uintptr_t`.
- Deserialize an unsigned integer back to a pointer to `Data`.
- Ensure the deserialized pointer compares equal to the original pointer.

## Usage

To use the `Serializer` class, simply call the static `serialize` and `deserialize` methods with the appropriate parameters.

### Example

```cpp
#include "Serializer.hpp"
#include <iostream>

struct Data {
    int value;
    std::string text;
};

int main() {
    Data data = {42, "Hello, World!"};
    Data* dataPtr = &data;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(dataPtr);

    // Deserialize the raw value back to a pointer
    Data* deserializedPtr = Serializer::deserialize(raw);

    // Ensure the deserialized pointer compares equal to the original pointer
    if (dataPtr == deserializedPtr) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data value: " << deserializedPtr->value << std::endl;
        std::cout << "Data text: " << deserializedPtr->text << std::endl;
    } else {
        std::cerr << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}
```


## .gitignore

The `.gitignore` file includes:

**.nfs***


## License

This project is licensed under the MIT License - see the [LICENSE](vscode-file://vscode-app/app/extra/vscode/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html) file for details.

## Contributing

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Create a new Pull Request.
