CC=gcc
CFLAGS = -Wall -g


my_program: main.o foo.o
	$(CC) $^ -o $@

%.o: %.c foo.h
	$(CC) $(CFLAGS) -c $< -o $@
main.o foo.o:foo.h

clean:
	rm -f *.o my_program
