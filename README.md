# Tinyprintf

[![CI](https://github.com/cyril-huet/Tinyprintf/actions/workflows/ci.yml/badge.svg)](https://github.com/cyril-huet/Tinyprintf/actions/workflows/ci.yml)
![C](https://img.shields.io/badge/C-C99-blue)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

Tinyprintf is a small implementation of `printf` written in C99.

The goal of this project is to understand how formatted output works internally,
using variadic functions, format parsing and manual number conversions.

This project does not try to replace the real `printf`. It is mainly an
educational project with a small and readable implementation.

## Supported formats

| Format | Description |
| ------ | ----------- |
| `%c` | Character |
| `%s` | String |
| `%d` | Signed decimal number |
| `%u` | Unsigned decimal number |
| `%o` | Octal number |
| `%x` | Lowercase hexadecimal number |
| `%%` | Percent character |

Example:

```c
tinyprintf("Name: %s, age: %d\n", "Cyril", 21);
```

Output:

```text
Name: Cyril, age: 21
```

## How it works

The format string is read character by character.

Normal characters are printed directly. When a `%` character is found,
Tinyprintf checks the next character and calls the corresponding conversion
function.

```text
format string
      |
      v
format parser
      |
      +--> character
      +--> string
      +--> decimal number
      +--> hexadecimal number
      +--> octal number
```

The project uses:

- `stdarg.h` for variadic arguments;
- small functions for each conversion;
- manual number conversion;
- `putchar` for output.

## Requirements

- A C99 compiler such as GCC or Clang;
- GNU Make;
- Criterion for the tests;
- `clang-format` for formatting checks.

## Build

Compile the source files with:

```sh
make
```

Clean the generated files:

```sh
make clean
```

Remove all generated files, including the test executable:

```sh
make fclean
```

## Using Tinyprintf

Tinyprintf is a function library and does not contain a `main` function.

A small example program can be compiled with:

```sh
gcc -std=c99 -Wall -Wextra -Werror example.c src/*.c -o example
```

Example source file:

```c
#include "tinyprintf.h"

int main(void)
{
    tinyprintf("Hello %s!\n", "world");
    tinyprintf("Number: %d\n", 42);
    return 0;
}
```

## Tests

The project contains a Criterion test suite.

Run all tests with:

```sh
make check
```

The tests cover:

- characters;
- strings;
- signed numbers;
- unsigned numbers;
- hexadecimal numbers;
- octal numbers;
- percent characters;
- mixed format strings;
- `NULL` strings;
- negative values.

## Formatting

Format the source files:

```sh
make format
```

Check the formatting without modifying the files:

```sh
make check-format
```

## Project structure

```text
.
├── .clang-format
├── .gitignore
├── .github/
│   └── workflows/
│       └── ci.yml
├── LICENSE
├── Makefile
├── README.md
├── src/
│   ├── convert.c
│   ├── convert.h
│   ├── display.c
│   ├── display.h
│   ├── tinyprintf.c
│   ├── tinyprintf.h
│   ├── utils.c
│   └── utils.h
└── tests/
    └── tests.c
```

Each source file has a simple responsibility:

- `tinyprintf.c`: parses the format string;
- `display.c`: prints the different values;
- `convert.c`: converts numbers into strings;
- `utils.c`: contains small helper functions;
- `tests.c`: contains the test suite.

## Limitations

Tinyprintf is intentionally small.

It does not currently support:

- floating-point numbers;
- field width;
- precision;
- flags such as `+`, `-` or `0`;
- length modifiers;
- advanced formatting options.

## License

This project is distributed under the MIT License.

See the [LICENSE](LICENSE) file for more information.