CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes -g
OBJS = main.o sll.o
PROG = sll

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: sll.h
sll.o: sll.h

clean:
	rm -f *~ *.o $(PROG) core a.out
