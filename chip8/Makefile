CC=gcc
CFLAG=-g -Wall

chip8:main.o font.o
	$(CC) $(CFLAG) $^ -o $@

%.o:%.c font.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f *.o chip8

