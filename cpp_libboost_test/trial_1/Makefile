CC=g++
CFLAGS=-pthread
CFLAGS+=-lcrypto
CFLAGS+=-lssl


all: main



objects = http_session.obj listener.obj shared_state.obj websocket_session.obj
main: $(objects)
	$(CC) main.cpp $(objects) -o main.bin $(CFLAGS)

http_session.obj:
	$(CC) -c http_session.cpp -o http_session.obj $(CFLAGS)

listener.obj:
	$(CC) -c listener.cpp -o listener.obj $(CFLAGS)

shared_state.obj:
	$(CC) -c shared_state.cpp -o shared_state.obj $(CFLAGS)

websocket_session.obj:
	$(CC) -c websocket_session.cpp -o websocket_session.obj $(CFLAGS)

check:
	-ls -alI *.o *.bin
	./main.bin 0.0.0.0 5000 . 1



clean:
	-rm *.obj *.bin
