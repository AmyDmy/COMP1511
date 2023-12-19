#include<stdio.h>
int main(void) {
    int num1 = 0;
    printf("Enter size: ");
    scanf("%d", &num1);
    
    int row = 0;
    int i = 0;
    while (row < num1 / 2 + 1) {
        int col = 0;
        while  (col <= num1 / 2 ) {
            if (col == row  ) {
                printf("*");
            } else if ( (row - col) % 4 == 0 ) {
                printf("*");
            }
            else {
                printf("-");
            }
            col++; 
        } 
        int right_side_begin = num1 / 2 + 1;
        while(right_side_begin < num1) {
            if (right_side_begin == num1 - i -1) {
                printf("*");
            } else if((num1 - i -1 - right_side_begin) % 4 == 0) {
                printf("*");    
            } else {
                printf("-");
            }
            right_side_begin++;
        }
        printf("\n");
        row++;
        i++;
    //printf("%d\n",col);
    }
    row = row-2;
    i = i -2;
    //printf("%d\n",row);
    while (row >= 0){
        int col = 0;
        
        while  (col <= num1 / 2) {
            
            
            if (col == row  ) {
                printf("*");
            } else if ( (row - col) % 4 == 0 ) {
                printf("*");
            }
            else {
                printf("-");
            }
            col++; 
        }
        int right_side_begin = num1 / 2 + 1;
        while(right_side_begin < num1) {
            if (right_side_begin == num1 - i -1) {
                printf("*");
            } else if((num1 - i -1 - right_side_begin) % 4 == 0) {
                printf("*");    
            } else {
                printf("-");
            }
            right_side_begin++;
        }
        printf("\n");
        row--;
        i--;
        
    } 
    return 0;
}