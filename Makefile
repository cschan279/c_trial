CC=gcc
#CFLAGS=-L/lib/x86_64-linux-gnu/
#CFLAGS+=-lmariadb -lz

all: io
#main_objects = version.o
#main: $(main_objects)
#	$(CC) -o main $(main_objects) $(CFLAGS)
#	./main

io:
	$(CC) can_io.c -o can_io.o