CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

TARGET = src/tinyprintf.o

all: $(TARGET)

$(TARGET): src/tinyprintf.c src/display.c src/convert.c src/utils.c
	$(CC) $(CFLAGS) -c src/tinyprintf.c -o src/tinyprintf.o
	$(CC) $(CFLAGS) -c src/display.c -o src/display.o
	$(CC) $(CFLAGS) -c src/convert.c -o src/convert.o
	$(CC) $(CFLAGS) -c src/utils.c -o src/utils.o

check: $(TARGET)
	$(CC) $(CFLAGS) tests/tests.c src/*.o -o tests/tests -lcriterion
	./tests/tests

clean:
	$(RM) src/*.o tests/tests
