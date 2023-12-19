//z5495891 Minyu Deng
#include<stdio.h>

int main(void){

    char words;
    printf("Enter a sequence of characters:");
    scanf("%c", &words);
    
    int num1 = 0;
    int num2 = 0;
    while (words != '\n') {
        if (words == 'A' || words == 'E'|| words == 'I'
        || words == 'O'|| words == 'U'||words == 'a' || words == 'e'||
        words == 'i'|| words == 'o'|| words == 'u')
        num1++;
        else if((words >= 'a'&&words <= 'z')||(words >= 'A'&&words <= 'Z'))
            num2++;
        scanf("%c", &words);
    }
    printf(" Number of vowels: %d\n", num1);
    printf("Number of consonants: %d\n", num2);


















    /*
words == 'a' || words == 'e'|| words == 'i'|| words == 'o'||
     words == 'u'|| words == 'A' || words == 'E'|| words == 'I'|| words == 'O'||
     words == 'U'

    printf("Number of vowels:");
    scanf("%d", num1);

    int num2;
    printf("Number of consonants:");
    scanf("%d", num2);*/




    return 0;
}