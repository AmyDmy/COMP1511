
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
        int b = shift + a +1;
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
char substract(char base_letter, int shift) {
    if (shift > 26 || shift < -26) {
        shift = shift % 26;
    }
    if ( base_letter < 'a' ) {
        if (base_letter - shift > 'Z') {
            int a = 'Z' - base_letter;
            int b = shift + a +1;
            return 'A' - b;
        } else if (base_letter - shift < 'A') {
        int a = base_letter - 'A';
        int b = shift - a;
        return  'Z' + b;}
    }
    else if ( base_letter > 'a') {
        if (base_letter - shift > 'z') {
            int a = 'z' - base_letter;
            int b = shift + a +1;
        return 'a' - b ;
        } else if (base_letter - shift< 'a') {
            int a = base_letter - 'a';
            int b = shift - a;
        return  'z' - b;
    }    
    }
    return base_letter - shift;
}
int main(void) {
    // Have a think about how we might implement this with a `struct message`
    // once we've covered structs in the Thursday lecture!
    char letter =0;
    char letter1=0;
    char letter2=0;
    char letter3=0;
    char letter4=0;
    char ed =0;
    int num1;
    int num2;
    int num3;
    int num4;
    // Scan message into the four characters
    int i=1;
    printf("Message: ");
    scanf("%c", &letter);
    while(i<=5){
        
    if (i==1){
        letter1=letter;
    } else if(i==2){
        letter2=letter;
    } else if (i==3){
        letter3=letter;
    } else if(i==4){
        letter4 = letter;
    } else if(i==5) {
        printf("Would you like to encipher or decipher this message (e/d)? ");
        ed=letter;
    }
        scanf("%c", &letter);
        i++;
    }
    ed = letter;
    if (ed == 'e') {
    printf("Enter numbers to encipher by: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    char output1 = add(letter1,num1);
    char output2 = add(letter2,num2);
    char output3 = add(letter3,num3);
    char output4 = add(letter4,num4);
    printf("%c%c%c%c\n", output1, output2, output3, output4);

    }else if(ed=='d') {
    printf("Enter numbers to decipher by: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
    char output1 = substract(letter1,num1);
    char output2 = substract(letter2,num2);
    char output3 = substract(letter3,num3);
    char output4 = substract(letter4,num4);
    printf("%c%c%c%c\n", output1, output2, output3, output4);
    }
    return 0;
}
