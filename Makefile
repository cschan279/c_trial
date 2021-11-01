CC=gcc
#CFLAGS=-L/lib/x86_64-linux-gnu/
#CFLAGS+=-lmariadb -lz

all: main
#main_objects = version.o
#main: $(main_objects)
#	$(CC) -o main $(main_objects) $(CFLAGS)
#	./main





main_objects = can_io.o
main: $(main_objects)
	$(CC) main.c $(main_objects) -o main.o

testcan: $(main_objects)
	$(CC) testcan.c $(main_objects) -o testcan.o