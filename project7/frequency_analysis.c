#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
int main(void) {
    char text[100] = {0};
    char letter[ALPHABET_SIZE + 1] = {0};
    int count[ALPHABET_SIZE] = {0};
    int total_num = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        letter[i] = 'a' + i;
    }
    letter[ALPHABET_SIZE] = '\0';
    while (fgets(text, 100, stdin) != NULL) {
        int len = strlen(text);
        for (int i = 0; i < len; i++) {
            if (isalpha(text[i]) != 0) {
                total_num++;

            }
            // if (text[i] <= 'Z' && text[i] >= 'A') {
            //     total_num++;
            // } else if (text[i] <= 'z' && text[i] >= 'a') {
            //     total_num++;
            // }
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            for (int j = 0; j < len; j++) {
                if (isupper(text[j])) {
                    text[j] = tolower(text[j]);
                }
                if (text[j] == letter[i]) {
                    count[i]++;
                }
            }
        }
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {

        double percent = count[i] / (double)total_num;
        printf("'%c' ", letter[i]);
        printf("%lf ", percent);
        printf("%d\n", count[i]);
    }
    return 0;
}