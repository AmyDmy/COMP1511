#include <stdio.h>

int main(void) {
    //int x;
    //printf("An int is %d bytes\n", sizeof(x))
    int grid[4][3];
    //loop over the outer dimension first
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            grid[row][col] = 0;
        }
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    return 0;
}