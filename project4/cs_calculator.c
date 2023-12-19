#include <stdio.h>

int main(void) {
    char sp;
    int num1;
    int num2 = 0;
    printf("Enter instruction: ");
    while (scanf("%c", &sp) == 1) {
        
        if (sp == 's') {
            scanf("%d", &num1);
            int output = num1 * num1;
            printf("%d\n", output);
            printf("Enter instruction: ");
        } else if (sp == 'p') {
    
            int output2 = 1;
            scanf("%d %d", &num1, &num2);
            for(int i=0; i<num2; i++) {
                output2 *= num1;
            }
            
            printf("%d\n", output2);
            printf("Enter instruction: ");

        }
        
    }


    return 0;
}