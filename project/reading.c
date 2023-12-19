#include <stdio.h>

int main (void){
    double avg_height;
    printf("Enter the average height of your students:");
    scanf("%lf", &avg_height);

    printf("The avg height is %.2lf\n", avg_height);
    return 0;
}
