#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include "dencrypt.h"

int main (int argc, unsigned char **argv[])
{
    /*
     * Set up the key and iv. Do I need to say to not hard code these in a
     * real application? :-)
     */

    /* A 256 bit key */
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

    /* A 128 bit IV */
    unsigned char *iv = (unsigned char *)"0123456789012345";

    /* Message to be encrypted */
    //unsigned char *plaintext =
    //    (unsigned char *)"The quick brown fox jumps over the lazy dog";
    unsigned char *plaintext;
    if (argc <= 1) {
        printf("No text input!\n");
        return 1;
    } else 
    {
        plaintext = (unsigned char *)argv[1];
    }
    //printf("%s\n", plaintext);
    /*
     * Buffer for ciphertext. Ensure the buffer is long enough for the
     * ciphertext which may be longer than the plaintext, depending on the
     * algorithm and mode.
     */
    unsigned char ciphertext[128];

    int ciphertext_len;

    /* Encrypt the plaintext */
    ciphertext_len = encrypt (plaintext, strlen ((char *)plaintext), key, iv,
                              ciphertext);

    /* Do something useful with the ciphertext here */
    //printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len;i++)
    {
    	printf("%02x", ciphertext[i]);
    }
    printf("\n");
    //BIO_dump_fp (stdout, (const char *)ciphertext, ciphertext_len);

    


    return 0;
}
