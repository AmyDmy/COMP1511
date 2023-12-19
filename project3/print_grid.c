//z5495891 Minyu
#include <stdio.h>



int main(void) {
    int num1;
    printf("Enter size:");
    scanf("%d", &num1);
    
    int row = 0;
    int col = 0;
    while (row < num1) {
        while (col < num1) {
            printf("(%d, %d)", row, col);
            col++;
           
        }
        row++;
        col = 0;
        printf("\n");
        while ((col < num1) && (row < num1)) {
            
            printf("(%d, %d)", row, col);
            col++;
        }
    }

    return 0;
}