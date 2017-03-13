CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = main.o sll.o
PROG = sll

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

server.o: rio.h
rio.o: rio.h

clean:
	rm -f *~ *.o $(PROG) core a.out
