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

test_objects = can_pack
test:
	-rm $(test_objects).o
	$(CC) -c $(test_objects).c -o $(test_objects).o
	$(CC) test.c $(test_objects).o -o test.o
	./test.o

clean:
	rm *.o