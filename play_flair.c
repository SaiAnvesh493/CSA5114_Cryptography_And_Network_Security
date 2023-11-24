#include <stdio.h>
#include <string.h>
#define SIZE 5
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int i, j, k, len, flag = 0;
    len = strlen(key);
    for (i = 0; i < len; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (keyMatrix[j][k] == key[i] || (key[i] == 'I' && keyMatrix[j][k] == 'J') || (key[i] == 'J' && keyMatrix[j][k] == 'I')) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }
            keyMatrix[i / SIZE][i % SIZE] = key[i];
        }
    }
    for (i = len; i < SIZE * SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (keyMatrix[j][k] == alphabet[i - len] || (alphabet[i - len] == 'I' && keyMatrix[j][k] == 'J') || (alphabet[i - len] == 'J' && keyMatrix[j][k] == 'I')) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }
            keyMatrix[i / SIZE][i % SIZE] = alphabet[i - len];
        }
    }
}
void encrypt(char keyMatrix[SIZE][SIZE], char plaintext[]) {
    int i, j,k, row1, col1, row2, col2;
    char ciphertext[strlen(plaintext)];
    for (i = 0; i < strlen(plaintext); i += 2) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (keyMatrix[j][k] == plaintext[i] || (plaintext[i] == 'I' && keyMatrix[j][k] == 'J') || (plaintext[i] == 'J' && keyMatrix[j][k] == 'I')) {
                    row1 = j;
                    col1 = k;
                }
                if (keyMatrix[j][k] == plaintext[i + 1] || (plaintext[i + 1] == 'I' && keyMatrix[j][k] == 'J') || (plaintext[i + 1] == 'J' && keyMatrix[j][k] == 'I')) {
                    row2 = j;
                    col2 = k;
                }
            }
        }
        if (row1 == row2) {
            ciphertext[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = keyMatrix[row1][col2];
            ciphertext[i + 1] = keyMatrix[row2][col1];
        }
    }
    printf("Encrypted Text: %s\n", ciphertext);
}
int main() {
    char key[25], plaintext[100];
    char keyMatrix[SIZE][SIZE];
    printf("Enter the key (no spaces, all uppercase): ");
    scanf("%s", key);
    printf("Enter the plaintext (no spaces, all uppercase): ");
    scanf("%s", plaintext);
    prepareKeyMatrix(key, keyMatrix);
    encrypt(keyMatrix, plaintext);
    return 0;
}

