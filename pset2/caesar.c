#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Make argument count accessible if need to complicate cipher or change functionality
#define ARGCOUNT 2

bool checkArgs(int n, int length);
bool checkPositive(int n);
int reduceKey(int k);
int encrypt(char l, int k);

int main(int argc, string argv[]){
    // make sure argv[1] exists
    if(argv[1] == NULL){
        printf("argv[1] must exist\n");
        return 1;
    }
    
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
    
    // Reduces down to < 26 shift no matter what positive number
    shift = reduceKey(shift);
    
    string input = GetString();
    
    if (input != NULL){
        for (int i = 0, n = strlen(input); i < n; i++){
            input[i] = encrypt(input[i], shift);
        }
    }
    
    printf("%s\n", input);
    
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
    if(n <= 0){
        return false;
    } else {
        return true;
    }
}

// Allows shift to be 2^31 - 26
int reduceKey(int key){
    while(key > 26){
        key = key % 26;
    }
    return key;
}

int encrypt(char letter, int shift){
    int encrypted = (int) letter;
    
    if(encrypted > 64 && encrypted < 91){
        if(encrypted + shift > 90){
            encrypted = encrypted + shift - 26;
        } else {
            encrypted += shift;
        }
    } else if(encrypted > 96 && encrypted < 123){
        if(encrypted + shift > 122){
            encrypted = encrypted + shift -26;
        } else {
            encrypted += shift;
        }
    }
    
    return encrypted;
}