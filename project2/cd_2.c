#include<stdio.h>

int main(void){

    double wam;
    printf("What is your wam?: ");
    scanf("%lf", &wam);

    //handle invlaid cases
    if (wam < 0 || wam > 100){
        printf("Invalid..\n");
        return -1;
    }
    else if(wam >= 0 && wam <= 25.0){
        printf("You got a 1.0,.. wrecked\n");
    }
    else if(wam >= 25.0 && wam <= 50.0){
        printf("You got a 2.0,.. \n");}
    else if(wam >= 50.0 && wam <= 75.0){
        printf("You got a 3.0,.. \n");}
    else{
        printf("You got a 4.0,.. \n");
    }

    //if 0-25, 1.0
    //

    return 0;
}