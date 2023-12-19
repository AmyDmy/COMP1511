//z5495891 Minyu Deng

#include <stdio.h>

int main(void){

    int students = 0;
    int tutors = 0;
    int sum = 0;

    printf("Please enter the number of students and tutors:");
    scanf("%d %d", &students, &tutors);

    sum = students + tutors;
    printf("%d + %d = %d\n", students, tutors, sum);

    return 0;
}