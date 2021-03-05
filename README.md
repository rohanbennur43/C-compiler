# Compiler Project

This project is a basic C++ compiler that includes a lexer, parser, and an abstract syntax tree (AST) for a simple programming language. The compiler can handle variable declarations, assignments, and `for` loops.

## Project Structure

The project is organized as follows:

- **`src/`**: Source code directory.
  - **`main.cpp`**: Main entry point for the compiler.
  - **`lexer/`**: Lexer-related files.
    - **`lexer.h`**: Header file for the lexer.
    - **`lexer.cpp`**: Implementation file for the lexer.
  - **`parser/`**: Parser-related files.
    - **`parser.h`**: Header file for the parser.
    - **`parser.cpp`**: Implementation file for the parser.
  - **`ast/`**: Abstract Syntax Tree (AST) related files.
    - **`ast.h`**: Header file for the AST.

- **`CMakeLists.txt`**: CMake build configuration.

- **`README.md`**: Project documentation.

## Building the Project

To build the project, make sure you have CMake installed. Then, follow these steps:

```bash
mkdir build
cd build
cmake ..
make

