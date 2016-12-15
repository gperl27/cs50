#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Make argcount accessible if need to complicate cipher or change functionality
#define ARGCOUNT 2

bool checkArgs(int n, int length);
bool checkPositive(int n);

int main(int argc, string argv[]){
    //make argv[1] an int from string
    int shift = atoi(argv[1]);
    
    if(!checkArgs(argc, ARGCOUNT)){
        printf("Can't have more or less than 1 argument (including argv[0])\n");
        return 1;
    }
    
    if(!checkPositive(shift)){
        printf("Shift must be a non-negative int\n");
        return 1;
    }
    
    printf("Made it, our shift is: %i\n", shift);
    
    printf("Let's encrypt a message: \n");
    string input = GetString();
    
    printf("Your input: %s", input);
    
    return 0;
}

//giving option of length in case more arguments arise
bool checkArgs(int n, int length){
    if(n == length){
        return true;
    } else {
        return false;
    }
}

// Make sure n is a non-negative integer
bool checkPositive(int n){
    if(n < 0){
        return false;
    } else {
        return true;
    }
}