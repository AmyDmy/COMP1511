#include <stdio.h>
#include <string.h>

int main (void) {
    char term1[128];
    char term2[128];
    int count = 0;
    int i = 0;
    printf("Enter the search term: ");
    fgets(term1, sizeof(term1), stdin);
    printf("Enter the list of strings: \n");
    for ( i = 0; i < 128; i++) {
        //printf("term1[i]=%d\n", term1[i]);
        if (term1[i] == '\n') {
            term1[i] = '\0';
            i = 128;
        }
    }
    //fgets(term2, sizeof(term2), stdin);
    while (fgets(term2, sizeof(term2), stdin) != NULL) {
        
        for (i = 0; i < 128; i++) {
            //printf("term2[i]=%d\n", term2[i]);
            if (term2[i] == '\n') {
                term2[i] = '\0';
                i = 128;
            }
        }
        //printf("i = %d\n",i);
        int result = strcmp(term1,term2);
        if (result == 0) {
            count++;
        } 
        for (int j = 0; j < 128; j++) {
            term2[j] = 0;
        }
        //fgets(term2, sizeof(term2), stdin);
    }
    
    printf("There was %d occurrence(s) of the search term in the input.\n", count);
    return 0;
}