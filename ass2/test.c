#include <stdio.h>

int main (void) {
    int num;
    int array[100] = {0};
    int i = 0;
    printf("Enter numbers forwards:\n");
    while (scanf(" %d", &num) == 1) {
        array[i] = num;
        i++;
    }
    int j = i - 5;
    for (; j < i; j++) {
        printf("%d\n", array[j]);
    }
    return 0;
}

