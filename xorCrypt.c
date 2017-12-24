#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

char* signature = "\xDE\xAD\xBE\xEF"; //The signature

int main(int argc, char **argv)
{
    if(argc<5)
        printf("usage: %s encrypt/decrypt file1 file2/output xor_key\n", argv[0]);
    else if(strcmp(argv[1], "encrypt") == 0)
        encrypt(argv[2], argv[3], argv[4], signature);
    else if(strcmp(argv[1], "decrypt") == 0)
        decrypt(argv[2], argv[3], argv[4], signature);
    else
        printf("usage: %s encrypt/decrypt file1 file2/output xor_key\n", argv[0]);
    return 0;
}
