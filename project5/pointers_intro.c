#include <stdio.h>

int main(void) {
    //create an int, store it in memory
    //assign it the value 7
    int jakes_int = 7;

    printf("value of jakes_int is: %d\n", jakes_int);

    //get the memory address of jakes_int
    //&jakes_int;
    printf("address of jakes_int is: %p\n", &jakes_int);

    //create an int pointer
    // assign it the address of jakes_int
    int *pointer_to_jakes_int = &jakes_int;
    printf("address of pointer_to_jakes_int is: %p\n", &pointer_to_jakes_int);
    printf("pointer_to_jakes_int is: %p\n", pointer_to_jakes_int);

    

    return 0;
}