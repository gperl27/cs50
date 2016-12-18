#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Make argument count accessible if need to complicate cipher or change functionality
#define ARGCOUNT 2

bool checkArgs(int n, int l);
int keyAssign(int k);
int encrypt(char l, int k);

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
            return 1;
        }
    }
    
    string input = GetString();
    int keyLength = strlen(key);
    int skipCount = 0;
    
    if (input != NULL){
        for (int i = 0, n = strlen(input); i < n; i++){
            if(isalpha(input[i])){
                input[i] = encrypt(input[i], keyAssign((int) key[( i - skipCount) % keyLength]));
            } else {
                skipCount++;
            }
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

// Allows shift to be 2^31 - 26
int keyAssign(int keyLetter){
    if(keyLetter > 64 && keyLetter < 91){
        keyLetter %= 65;
    } else if(keyLetter > 96 && keyLetter < 123){
        keyLetter %= 97;
    }
    
    return keyLetter;
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