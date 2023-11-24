#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *key) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < plaintextLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0;
        }
        if (isupper(plaintext[i])) {
            plaintext[i] = ((plaintext[i] + key[j]) % 26) + 'A';
        }
        else if (islower(plaintext[i])) {
            plaintext[i] = ((plaintext[i] + key[j]) % 26) + 'a';
        }
    }
}
int main() {
    char plaintext[100];
    char key[100];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    strtok(plaintext, "\n");
    strtok(key, "\n");
    vigenereEncrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}
