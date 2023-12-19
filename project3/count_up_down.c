//z5495891 Minyu Deng
#include <stdio.h>

int main(void) {

    int i;
    printf("Enter number: ");
    scanf("%d", &i);

    int number = 0;
    while (number != i) {
        if (i > 0) {
            printf("%d\n", number);
            number++;
        }
        else if (i < 0) {
            printf("%d\n", number);
            number--;
        }
    }
    printf("%d\n", i);
    return 0;
}