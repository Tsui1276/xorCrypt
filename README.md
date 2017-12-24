# xorCrypt

## Description
xorCrypt is a small program I made in C for studying purposes.
It encrypts a file with the XOR operation, and appends the encrypted file to another file.
Between the two files you'll find a signature ("\xDE\xAD\xBE\xEF") that seperates the two files from each other.

## Usage
xorCrypt encrypt/decrypt file1 file2/output xor_key
