#include <stdio.h>

    

int main(void) {
    char character;
    
    while(
    scanf("%c", &character) == 1){
    if (character != 'a' && character != 'e'&& character != 'i'&&
    character != 'o'&&character != 'u') {

        printf("%c", character);
    }
    }

    return 0;
}