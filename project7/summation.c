#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int num = argc - 1;
    int num1[argc];
    for (int i = 1; i <= num; i++) {
        num1[i-1] = atoi(argv[i]);
    }
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum = sum + num1[i];
    }
    printf("Sum: %d\n",sum);
    return 0;
}