#include <stdio.h>

void double_int(int *int_to_double) {

}


int main(void) {

    int data[5] = {1,2,3,4,5};

    printf("%p\n", data);
    printf("%d\n", *data);

    printf("%p\n", &data[1]);
    printf("%d\n", data[1]);
    printf("%d\n", *data[1]);


    return 0;
}