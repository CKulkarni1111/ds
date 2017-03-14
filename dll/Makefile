CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = main.o dll.o
PROG = dll

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: dll.h
dll.o: dll.h

clean:
	rm -f *~ *.o $(PROG) core a.out
