#include<stdio.h>
int main(void){
    //we create a 7 element int array, assigning it
    int ice_cream_per_day[7] = {3, 2, 1, 2, 1, 3, 5};
    int i = 0;
    
    while (i < 7) {
        printf("%d\n", ice_cream_per_day[i]);
        i++; // i = i + 1;
    }
    return 0;
}
