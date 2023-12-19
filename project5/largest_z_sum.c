// Find the largest sum of numbers in a z shape.

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 100

int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter 2D array side length: ");
    scanf("%d", &size);
    assert(size >= 3);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            assert(scanf("%d", &array[i][j]) == 1);
            j++;
        }
        i++;
    }

    printf("The largest z sum is %d.\n", largest_z_sum(size, array));

    return 0;
}

// Return the largest sum of numbers in a z shape.
int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]) {
    // Put your code here.
    int sum = 0;
   

    for (int i = 3; i <= size; i++) {
        for (int count_row = 0; (count_row + i) <= size; count_row++) {
            for (int count_col = 0; (count_col + i) <= size; count_col++) {
                int sum1 = 0;
                int sum2 = 0;
                for (int row = count_row; row < (i + count_row); row++) {
                    for (int col = count_col; col < (i + count_col); col++) {                
                        if ((row - count_row) % (i) == 0 ||
                         (row - count_row) % (i ) == (i - 1)) {
                            sum1 = sum1 + array[row][col];
                            
                        } else {
                            sum2 = sum2 + array[row][i - 1 + count_col + count_row - row];
                            break;
                        }
                    }
                } 
                if (sum1 + sum2 > sum) {
                    sum = sum1 + sum2;
                }
                //printf("%d\n", sum);
            }
        }
    }
    return sum;
}