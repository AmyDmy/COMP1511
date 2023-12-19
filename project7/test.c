#include <stdio.h>
#include <string.h>
// int cipher(int stop, char *like);

// int main(int argc, char* argv[]) {
//     int stop = 0;
//     char *like = argv[1];
//     printf("Enter text: \n");
//     while (stop == 0) {
//         stop = cipher(stop, like);
//     }
//     return 0;
// }

// int cipher(int stop, char *like) {
//     char input[100] = { 0 };
//     int i = 0;
//     fgets(input, 100, stdin);
//     int len = strlen(input);
//     //printf("%d\n", len);
//     while (i < len) {
//         //printf("check\n");
//         if (input[i] >= 'a' && input[i] <= 'z') {
//             int num = (input[i] - 'a') % 26;
//             input[i] = like[num];
//         }
//         else if (input[i] >= 'A' && input[i] <= 'Z') {
//             int num = (input[i] + 32 - 'a') % 26;
//             input[i] = like[num] - 32;
//         }
//         i++;
//     }
//     if (input[0] == '\0') {
//         return -1;
//     }
//     fputs(input, stdout);
//     return 0;
//}

int main(void) {
    printf("%d\n", 3/2);
}