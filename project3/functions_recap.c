#include <stdio.h>

//forward declare

// function that returns a double
// accepts a single char as input
double price_of_item(char item) {

    if (item == 'p') {
        return 10.0;;
    } else if (item == 'c') {
        return 3.5;
    } else {
        return 0.00;
    }
}

int main (void) {

    // call price_of_item with the input (argument) 'p'
    double cost = price_of_item('p')
    printf("cost: %lf\n", cost);
    return 0;
}