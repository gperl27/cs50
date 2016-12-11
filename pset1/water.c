#include <cs50.h>
#include <stdio.h>

int main(void){
    printf("Please enter your average shower time: (postive integer)\n");
    
    int showerMinutes = GetInt();
    
    int bottles = (showerMinutes * 192)/16;
    
    printf("minutes: %i\n", showerMinutes);
    printf("bottles: %i\n", bottles);
    
    return 0;
}