#include <stdio.h>
#include <string.h>
int remove_duplicates(int length, int source[length], int destination[length]) {
    int a = 0;
    for (int i = 0; i < length; i++) {
        destination[a] = source[i];
        a++;
        for (int j = a - 2; j >= 0; j--){
            if (destination[a-1] != destination[j]){
                continue;
            } else if (destination[a-1] == destination[j]) {
                destination[a-1] = 0;
                a--;
                break;
            }
        }
    } 
    return a   ;
}

int main(void) {




    return 0;
}