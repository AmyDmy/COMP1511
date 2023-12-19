
// Program which prints a letter depending on the user's request.
// by ...
//Minyu Deng z5495891
#include <stdio.h>

int main(void) {

    char is_uppercase;
    printf("Uppercase: ");
    scanf("%c", &is_uppercase);

    
    char lowercase;
    // TODO: scan is_uppercase
    char uppercase;
    int index;
    printf("Index: ");
    scanf("%d", &index);
    // TODO: finish the program
    if (is_uppercase == 'y') {
        uppercase = (char) index + 'A';
        printf("The letter is %c\n", uppercase); 
    } else {
        lowercase = (char) index + 'a';
        printf("The letter is %c\n", lowercase);
    }



    return 0;
}