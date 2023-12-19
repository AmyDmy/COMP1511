#include <stdio.h>

// make a function which asks the user's age
// and prints some messages
// accept the total cost
// accept the user's age
// return the discounted cost
double caclculate_discounted_cost(int age; double cost;){
    if (age <= 18){
        return cost*0.9;
    } else if (age >= 65){
        return cost*0.85;
    }
    return cost;
}

int main (void){

    int age;
    double cost;

    printf("What's the customer's age? ");
    scanf("%d", &age);

    printf("What's the customer's age? ");
    scanf("%d", &cost);

    printf("%lf\n", caclculate_discounted_cost(age,cost));

    return 0;
}