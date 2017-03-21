CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes -g
OBJS = main.o bst.o
PROG = bst

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: bst.h
bst.o: bst.h

clean:
	rm -f *~ *.o $(PROG) core a.out
