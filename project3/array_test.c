#include <stdio.h>

int main(void) {

    int x;
    int count[10];
    scanf("%d", &x);
    while( x!=0) {
        if( x>=0 && x<=9) {
            count[x]++;
        }
        scanf("%d", &x);
    }
    for (i=0; i<10;i++){
        printf("")
    }
    return 0;
}