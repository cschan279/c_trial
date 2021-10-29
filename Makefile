CC=gcc
#CFLAGS=-L/lib/x86_64-linux-gnu/
#CFLAGS+=-lmariadb -lz

all: can_tran
#main_objects = version.o
#main: $(main_objects)
#	$(CC) -o main $(main_objects) $(CFLAGS)
#	./main

can_tran:
	$(CC) can_tran.c -o can_tran.o