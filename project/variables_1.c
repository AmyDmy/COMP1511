#include<stdio.h>
int main(void){
    //request an int named nm_bees
    //32 bits of memory allocated to our program!
    int num_bees = 14;

    char initial = 'j';

    //double pi = 3.1415;

    //%c for char
    //%d for decimal int
    //%ls for double

    //"j has 14 bees"
    printf("%c has %d bees\n", initial, num_bees);

    return 0;
}