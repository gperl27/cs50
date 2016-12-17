#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Make argument count accessible if need to complicate cipher or change functionality
#define ARGCOUNT 2

bool checkArgs(int n, int l);

int main(int argc, string argv[]){
    // make sure argv[1] exists
    if(argv[1] == NULL){
        printf("argv[1] must exist\n");
        return 1;
    }
    
    if(!checkArgs(argc, ARGCOUNT)){
        printf("Can't have more or less than 1 argument (including argv[0])\n");
        return 1;
    }
    
    // assign to var to make more readable
    string key = argv[1];
    
    // loop through arg[v] to see if all are chars
    for(int i = 0, n = strlen(key); i < n; i++){
        if(!isalpha(key[i])){
            printf("No numeric values allowed\n");
            return 0;
        }
    }
    
    printf("no errors yet!");
    
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