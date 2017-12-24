#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"

int readBytes(char **buffer, char *file)
{
    FILE *fileptr;
    long filelen;
    fileptr = fopen(file, "rb");
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    rewind(fileptr);
    *buffer = (char *)malloc((filelen+1)*sizeof(char));
    fread(*buffer, filelen, 1, fileptr);
    fclose(fileptr);
    return filelen;
}
void encrypt(char *file, char *file2, char *key, char *signature)
{
    FILE *fileptr;
    char *buffer;
    long filelen;
    filelen = readBytes(&buffer, file);
    int i;
    for(i = 0;i < filelen;i++)
        *(buffer+i) = *(buffer+i) ^ *(key + (i%strlen(key)));
    int finalLength = strlen(signature) + strlen(buffer);
    char *final_ = malloc(finalLength + 1);
    memset(final_, '\0', finalLength);
    strcat(final_, signature);
    strcat(final_, buffer);
    fileptr = fopen(file2, "ab+");
    fwrite(final_, strlen(final_), 1, fileptr);
    fclose(fileptr);

}

void decrypt(char* file, char* output, char* key, char *signature)
{
    FILE *fileptr;
    char *buffer;
    long filelen;
    int signatureLen = strlen(signature);
    int i, x;
    filelen = readBytes(&buffer, file);
    *(buffer + filelen) = 0;
    for (i=0;i+signatureLen<filelen;i++)
        if(strncmp(buffer+i, signature, signatureLen) == 0)
            break;
    if (i+signatureLen == filelen)
    {
        printf("signature not found, can't find a file to decrypt!\n");
        return;
    }
    x = i;
    char *newBuffer = buffer+i+signatureLen;
    for(i=0;i+x+signatureLen < filelen;i++)
        *(newBuffer+i) = *(newBuffer+i) ^ *(key + (i%strlen(key)));
    fileptr = fopen(output, "wb");
    fwrite(newBuffer, strlen(newBuffer), 1, fileptr);
    fclose(fileptr);
    *(buffer+x) = 0;
    fileptr = fopen(file, "wb");
    fwrite(buffer, strlen(buffer), 1, fileptr);
    fclose(fileptr);

}