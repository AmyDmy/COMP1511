//z5495891 Minyu Deng
#include <stdio.h>

int main(void){
    int num1;

    scanf("%d", &num1);

    if (num1 > 0) {
        printf("You have entered a positive number.\n");
    } else if (num1 < 0) {
        printf("Don't be so negative!\n");
    } else if (num1 == 0) {
        printf("You have entered zero.\n");
    }
    

    return 0;
}