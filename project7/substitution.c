#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cipher (char text[100], char encipher[27]);

int main (int argc, char *argv[]) {
    char encipher[27];
    char text[100];
    printf("Enter text: \n");
    char *letter = argv[1];
    for (int i = 0; i < 26; i++) {
        encipher[i] = letter[i];
    }
    encipher[26] = '\0';
    for (int i = 0; i < 100; i++) {
        text[i] = 0;
    }
    while (fgets(text, 100, stdin) != NULL) {
        cipher(text, encipher);
        printf("%s", text);
    }
    return 0;
    
}

void cipher (char text[100], char encipher[27]) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if(text[0] == '\0') {
            i = len;
        }
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int real = text[i] - 'A';
            text[i] = encipher[real] - 'a' + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            int real = text[i] - 'a';
            text[i] = encipher[real];
        } else {

        }
        
    }
}