// Does some calculations to make souffle pancakes
// Solution by Paula Tennent (2023)
// Solution fixed by [student] [zid]

#include <stdio.h>

#define COOKING_TIME 15
#define PANCAKES_PER_PAN 4

// TODO: Write function prototypes





// TODO: Write divide function
double divide (double a, double b) {
    return  a / (b);
}

// TODO: Write ceiling function
int ceiling(double num1) { 
    int int_value = (int)num1;
    if(num1 - int_value == 0) {
        return num1;
    } else
        return num1 * 10 / 10 + 1;
}

// TODO: Write print_time function
void print_time(int minutes) {
    
    if (minutes > 60) {
        int hours = minutes / 60;
        int time = minutes % 60;
        printf("%d hours and %d minutes", hours, time);
    } else {
        printf("0 hours and %d minutes", minutes);
    }
}

//////////////// vvv DO NOT EDIT MAIN vvv //////////////////

int main(void) {

    printf("How many souffle pancakes do you want to make? ");
    int pancakes;
    scanf("%d", &pancakes);
  
    // for 3 pancakes, we need 2 eggs!
    double eggs_decimal = pancakes * divide(2, 3);
    // but we can't have part of an egg, so lets use ceiling
    int eggs = ceiling(eggs_decimal);

    int sugar_grams = pancakes * 10;
    int flour_grams = pancakes * 8;

    printf("You will need:\n");
    printf("- %d eggs\n", eggs);
    printf("- %dg sugar\n", sugar_grams);
    printf("- %dg flour\n", flour_grams);

    // also using ceiling for frying sessions as if we have 1 pancake left
    // it still needs the same time as full pan of pancakes.
    int frying_sessions = ceiling(divide(pancakes, PANCAKES_PER_PAN));
    int minutes = frying_sessions * COOKING_TIME;

    printf("Frying will take you ");
    print_time(minutes);
    printf(".\n");

    return 0;
}

//////////////// ^^^ DO NOT EDIT MAIN ^^^ //////////////////
