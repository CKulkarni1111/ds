CC= gcc
CFLAGS= -Wall -g -Werror
SRC = rightmost.c
BIN = $(patsubst %.c,%,$(SRC))

all: $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
