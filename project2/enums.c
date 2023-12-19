#include<stdio.h>

enum manufacturer{Apple, Asus, Acer, Dell, MSI, HP};    

int main(void){

    enum manufacturer brand = Apple;

    if(brand == 0)
    {
        printf("I have a macbook");
    }
    printf("brand %d\n", brand);

    return 0;
}