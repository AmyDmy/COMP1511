#include <stdio.h>

int main (void){
    int age = 28;
    int current_year = 2023;
    int year_born = current_year - age;
    //int year_born = current_year - (50-3);

    printf("You were born in %d", year_born);
    return 0;
}

