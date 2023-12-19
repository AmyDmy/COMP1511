//Minyu Deng z5495891
#include<stdio.h>

int main(void){

    char letter1;
    char letter2;
    char letter3;
    char letter4=0;


    printf("How do you want to build a face?: ");
    scanf("%c%c%c%c", &letter1,&letter2,&letter3,&letter4);


    if (letter1 == 'a') {
        printf("_");
        
    } else if (letter1 == 'b') {
        printf("~");
       
    } else if (letter1 == 'c') {
        printf("\\");
        
    } else if (letter1 == 'd') {
        printf("/");
        
    }

    
    if (letter2 != 'a' && letter2!= 'b' && letter2!= 'c' && letter2!= 'd')
    {

         if (letter1 == 'a') {
        printf(" _\n");
        
    } else if (letter1 == 'b') {
        printf(" ~\n");
       
    } else if (letter1 == 'c') {
        printf(" \\\n");
        
    } else if (letter1 == 'd') {
        printf(" /\n");
    }
    
    printf("O O\n");

    if (letter2 == 'e') {
        printf(" ^\n");
    } else if (letter2 == 'f') {
        printf(" ~\n");
    }

    if (letter3 == 'g') {
        printf("\\_/\n");
    } else if (letter3 == 'h') {
        printf("/-\\\n");
    } else if (letter3 == 'i') {
        printf(" o\n");
    } 
    
    } 

    else if (letter2 == 'a') {
        printf(" -\n");
        printf("O O\n");
       
    } else if (letter2 == 'b') {
        printf(" ~\n");
        printf("O O\n");
        
    } else if (letter2 == 'c') {
        printf(" \\\n");
        printf("O O\n");
        
    } else if (letter2 == 'd') {
        printf(" /\n");  
        printf("O O\n");
    }
    


    if (letter3 == 'e') {
        printf(" ^\n");
    } else if (letter3 == 'f') {
        printf(" ~\n");
    }

    if (letter4 == 'g') {
        printf("\\_/\n");
    } else if (letter4 == 'h') {
        printf("/-\\\n");
    } else if (letter4 == 'i') {
        printf(" o\n");
    } 

    return 0;
}