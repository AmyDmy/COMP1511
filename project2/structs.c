#include<stdio.h>

struct computer{
    double price;
    int num_cpu_cores;
    double screen_size;
} ;

int main(void){
    //just like saying
    //int x
    //type name
    //asking the OS for memory
    struct computer macbook_pro;

    macbook_pro.price = 2000.00;
    macbook_pro.num_cpu_cores = 8;
    macbook_pro.screen_size = 14.0;

    printf("Price: %lf\n", macbook_pro.price);

    return 0;
}