CC=gcc
CFLAGS=-L/lib/x86_64-linux-gnu/
CFLAGS+=-lmariadb -lz

all: version createDB selectDB check
#main_objects = version.o
#main: $(main_objects)
#	$(CC) -o main $(main_objects) $(CFLAGS)
#	./main

version:
	$(CC) version.c -o version.o $(CFLAGS)
	
createDB:
	$(CC) createDB.c -o createDB.o $(CFLAGS)

selectDB:
	$(CC) selectDB.c -o selectDB.o $(CFLAGS)

check:
	ls *.o
	./version.o
#	./createDB.o

clean:
	-rm *.o
#	-rm main
