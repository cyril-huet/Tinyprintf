# Compiler
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -Wvla

# Source and object files
SRC = src/tinyprintf.c src/display.c src/convert.c \
		src/utils.c

OBJ = $(SRC:.c=.o)

# Executable
TARGET = tests/tests

# Compile the project
all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the tests
check: $(TARGET)
	./$(TARGET)

$(TARGET): tests/tests.c $(OBJ)
	$(CC) $(CFLAGS) tests/tests.c $(OBJ) -o $(TARGET) -lcriterion

# Format the files
format:
	clang-format -i $(SRC) src/*.h tests/tests.c

check-format:
	clang-format --dry-run -Werror $(SRC) src/*.h tests/tests.c

# Clean generated files
clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all check format check-format clean fclean re