# Binary, Hexadecimal, and Decimal Converter

Menu-driven conversion between 16-bit binary, 32-bit hexadecimal, and unsigned decimal values.

An educational C++ example developed from coursework, organized as a standalone project.

## Build and run

Requires a C++17 compiler and Make. Smoke checks also require Python 3.

```sh
make
make run
make check
```

To choose a compiler: `make CXX=clang++` or `make CXX=g++`. Run `make clean` to remove build outputs.

## Example

Choose an operation from the menu, enter a value, then select option 4 to exit.

## Structure

- `src/`: source code and headers.
- `tests/smoke.py`: representative console checks with execution timeouts.
- `Makefile`: builds the source files together into `build/example`.

## Scope

Binary input must contain exactly 16 bits. Decimal values must fit in an unsigned 32-bit integer.

The source retains the original exercise logic and explanatory comments. Build outputs, submission documents, and course materials are not part of this repository.
