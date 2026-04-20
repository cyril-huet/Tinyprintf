# Tinyprintf

Tinyprintf is a simplified implementation of the standard `printf` function, written in C.  
The goal of this project is to understand how formatted output works internally, using variadic
arguments and manual format parsing.

The function writes directly to standard output and returns the number of characters printed.

## Overview

This project focuses on low-level C programming concepts such as:
- variadic functions (`stdarg`)
- parsing format strings
- integer to string conversions
- character-by-character output

The implementation is intentionally minimal and restricted, in order to emphasize correctness,
clarity, and understanding of how `printf`-like functions work under the hood.

## Features

The following format directives are supported:

- `%%` — print a literal `%`
- `%d` — signed decimal integer
- `%u` — unsigned decimal integer
- `%o` — unsigned octal integer
- `%x` — unsigned hexadecimal integer (lowercase)
- `%s` — string (prints `(null)` if the pointer is NULL)
- `%c` — single character

Any unknown directive is printed as-is.

## Constraints

- Only `putchar(3)` is used for output
- No global variables
- No `printf`, `puts`, or similar helpers
- Code follows the C99 standard
- Function bodies are intentionally kept small
- No `main` function is provided

## Build

Build the project using `make`:

```sh
make
```

## The resulting binary will be located at

```text
src/tinyprintf.o
```


## Usage
### Include the header and link the object file in your project:
```c
#include "tinyprintf.h"

tinyprintf("Hello %s [%d]\n", "world", 42);
```
### Example output
```text
Hello world [42]
```

# Tests

## The project includes a Criterion testsuite.

### Run the tests with:
```sh
make check
```
