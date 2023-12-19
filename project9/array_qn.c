#include <stdio.h>

// let's have a function which accepts an array of integers
// it should be an array of pairs of ints
// they are 1 or 0

// input -> 1,-1,-1,1,1,-1,-1,-1,-1,1
// task is to go through each pair (two ints at a time) and figure out which
// quadrant it maps to

// 1.1 -> NE
// 1,-1 -> SE
// -1, -1 -> SW
// -1, 1 -> nw

// if they are a non-even amount of ints, print nothing
// Otherwise, print the quadrant as above for each pair with a newline

// example:
// 1,1
// NE\n

// 1, 1, -1, 1, 1, 1
// NE\n
// NW\n
// NE\n

void print_quadrants(int data[],int length) {
    if (length % 2 != 0) {
        printf("nothing\n");
    } else {
        for (int i = 0; i < length; i = i + 2) {
            if (data[i] == 1 && data[i + 1] == 1) {
                printf("NE\n");
            } else if (data[i] == 1 && data[i + 1] == -1) {
                printf("SE\n");
            } else if (data[i] == -1 && data[i + 1] == -1) {
                printf("SW\n");
            } else if (data[i] == -1 && data[i + 1] == 1) {
                printf("NW\n");
            }
        }
    }
}

int main(void) {

    return 0;
}