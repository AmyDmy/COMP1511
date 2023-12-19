// z5495891 Minyu Deng
#include <stdio.h>

char add(char base_letter, int shift) {
    if (shift > 26 || shift < -26) {
        shift = shift % 26;
    }
    if ( base_letter < 'a' ) {
        if (shift + base_letter > 'Z') {
            int a = base_letter - 'Z';
            int b = shift - a;
            return 'A' + b;
        } else if (shift + base_letter < 'A') {
        int a = base_letter - 'A';
        int b = shift + a + 1;
        return  'Z' + b;}
    }
    else if ( base_letter > 'a') {
        if (shift + base_letter > 'z') {
            int a = 'z' - base_letter;
            int b = shift - a;
        return 'a' + b ;
        } else if (shift + base_letter < 'a') {
            int a = base_letter - 'a';
            int b = shift + a + 1;
        return  'z' + b;
    }    
    }
    return base_letter + shift;
}
int main (void) {
    char message1;
    char message2;
    char message3;
    char message4;

    printf("Message:");
    scanf("%c%c%c%c", &message1, &message2, &message3, &message4);
    
    int num1;
    int num2;
    int num3;
    int num4;
    printf(" Enter numbers to encipher by: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    char output1 = add(message1,num1);
    char output2 = add(message2,num2);
    char output3 = add(message3,num3);
    char output4 = add(message4,num4);

    printf("%c%c%c%c\n", output1, output2, output3, output4);


    return 0;
}