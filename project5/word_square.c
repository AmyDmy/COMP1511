//z5495891 Minyu Deng
#include <stdio.h>
#include <string.h>
#define N 1024

int main(void) {

    printf("Input word: ");
    char input[N];
    fgets(input, N, stdin);
    printf("\n");


    int n = strlen(input);
    printf("Word square is: \n");
    for (int i=0; i < n-1; i++) {
        printf("%s", input);
    }

    return 0;
}