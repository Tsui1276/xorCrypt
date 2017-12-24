int readBytes(char **buffer, char *file);
void encrypt(char *file, char *file2, char *key, char *signature);
void decrypt(char* file, char* output, char* key, char *signature);