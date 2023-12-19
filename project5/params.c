#include <stdio.h>

void double_int(int *int_to_double) {
    *int_to_double = *int_to_double * 2;
}

int main(void) {

    int x = 50;
    double_int(&x);

    printf("%d\n", x);

    return 0;
}