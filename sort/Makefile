CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = insertion_sort.o
PROG = insertion_sort

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

insertion_sort.o: insertion_sort.c

clean:
	rm -f *~ *.o $(PROG) core a.out
