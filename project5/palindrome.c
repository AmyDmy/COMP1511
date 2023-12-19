// palindrome.c
//
// Given a string, this program calculates whether it is palindromic or not and 
// prints out the result.
//
// Written by Minyu Deng z5495891
// on TODAYS DATE

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

int is_palindrome(char my_string[MAX_STRING_LENGTH]);

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
int main (void) {
    // You don't need to understand this code to complete the exercise.

    // Scans in a string from the user.
    char my_string[MAX_STRING_LENGTH];
    fgets(my_string, MAX_STRING_LENGTH, stdin);

    // removing the newline character from the end of the string
    int length = strlen(my_string);
    if (length != 0 && my_string[length - 1] == '\n') {
        my_string[length - 1] = '\0';
    }
    
    // Runs your function and prints results
    if (is_palindrome(my_string)) {
        printf("%s is a palindrome!\n", my_string);
    } else {
        printf("%s is not a palindrome!\n", my_string);
    }
    
    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// Determines if the given `my_string` is a palindrome or not.
// Returns `1` if it is, otherwise `0`
int is_palindrome(char my_string[MAX_STRING_LENGTH]) {
    // TODO: Write is_palindrome function here
    int num = strlen(my_string);
    //printf("%d", num);
    char new_string[num + 1];
    // int a = 0;
    // for (int i = num - 1; i >= 0; i--) {
        
    //     new_string[a] = my_string[i];
    //     a++;
    // }

    int j = 0;
    for (int i = num - 1; i >=0; i--){
        if (my_string[i] != my_string[j]) {
            return 0;
        }
        j++;
    }
    return 1;

    //new_string[a] = '\0';
    printf("%s %s\n", new_string, my_string);
    if (new_string == my_string) {
        printf("Test");
        return 1;
    } else
    return 0;
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
