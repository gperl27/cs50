#include <cs50.h>
#include <stdio.h>

int createPyramid(int x);

int main(void){
    printf("Let's create Mario's pyramid!\n");
    printf("Please enter a number between 0 and 23 for the height of the pyramid:\n");

    int pyramidHeight = GetInt();
    
    while(pyramidHeight < 0 || pyramidHeight > 23){
       printf("Retry: ");
       pyramidHeight = GetInt();
    }
    
    createPyramid(pyramidHeight);
    
    return 0;
}


int createPyramid(int height){
    int whitespace;
    
    //i is 1 for the double blocks at the top
    //i <= height to compensate for i = 1
    for(int i = 1; i <= height; i++){
        //whitespace comes before blocks
        whitespace = height - i;
        for(int w = 0; w < whitespace; w++){
            printf(" ");
        }
        for(int j = 0; j <= i; j++){
            printf("#");
        }
        //newline
        printf("\n");
    }
    
    return 0;
}

