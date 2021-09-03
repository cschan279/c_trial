CC=gcc
CFLAGS=-lcrypto

all: trial encrypt_msg decrypt_msg

objects = dencrypt.o
trial: $(objects)
	$(CC) trial.c $(objects) -o trial.bin $(CFLAGS)


en_objects = dencrypt.o hex_conv.o
encrypt_msg: $(en_objects)
	$(CC) msg_encrypt.c $(en_objects) -o msg_encrypt.bin $(CFLAGS)


de_objects = dencrypt.o
decrypt_msg: $(de_objects)
	$(CC) msg_decrypt.c $(en_objects) -o msg_decrypt.bin $(CFLAGS)


check:
	ls *.o *.bin
	./trial.bin
#	./createDB.o

#h_objects = hex_conv.o
#hextest: $(h_objects)
#	$(CC) hextest2.c $(h_objects) -o hextest2.bin


clean:
	-rm *.o
	-rm *.bin
