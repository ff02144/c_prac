CC=gcc
CFLAGS= -g -wall $(shell sdl2-config --cflags)
LDFLAGS=$(shell sdl2-config --libs)

chip8:main.o font.o rom.o display.o
	$(CC) $(CFLAG) $^ -o $@ $(LDFLAGS)

%.o:%.c font.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f *.o chip8

