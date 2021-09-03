CC=g++
CFLAGS=-pthread
CFLAGS+=-lcrypto
CFLAGS+=-lssl


all: trial

trial:
	$(CC) http_server_async_ssl.cpp  -o http_server_async_ssl.bin $(CFLAGS)





check:
	-ls -alI *.o *.bin
	./http_server_async_ssl.bin 0.0.0.0 5000 . 1



clean:
	-rm *.o *.bin
