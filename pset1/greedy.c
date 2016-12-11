#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    
    printf("Enter amount owed:\n");
    float change = GetFloat();
    
    while(change < 0){
        printf("Retry: ");
        change = GetFloat();
    }
    
    int cents = roundf(change * 100);
    int coinCounter = 0;
    
    while(cents > 0){
        if(cents-25 >= 0){
            cents -= 25;
            coinCounter++;
        } else if(cents - 10 >= 0){
            cents -= 10;
            coinCounter++;
        } else if(cents- 05 >= 0){
            cents -= 5;
            coinCounter++;
        } else if(cents-01 >= 0){
            cents -= 1;
            coinCounter++;
        } else if(cents < 0){
            printf("Retry: ");
            cents = GetFloat();
        }
    }
    
    printf("%i\n" , coinCounter);

    return 0;
}