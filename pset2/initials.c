#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    
    string name = GetString();
    //print first character no matter what
    printf("%c", toupper(name[0]));
    
    // look for spaces, print next char if true
    for(int i = 0, n = strlen(name); i < n; i++){
        if(isblank(name[i])){
            printf("%c", toupper(name[i + 1]));
        }
    }
    
    // new line for aesthetic and to pass spec
    printf("\n");
}