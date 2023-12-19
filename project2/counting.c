#include <stdio.h>

int main(void){
    int i = 0;
    int max;
    printf("Enter the max: ");
    scanf("%d", &max);

    while(i < max){
        printf("%d\n", i);
        i = i + 1;
    }
    return 0;   
}