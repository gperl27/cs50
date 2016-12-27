/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <ctype.h>
#include "helpers.h"
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n < 0){
        return false;
    }
    
    for(int i = 0; i < n; i++){
        if(value == values[i]){
            return true;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    bool stillSwapping = true;

    while(stillSwapping){
        int swapped = 0;
        for(int i = 0; i < n - 1; i++){
            if(values[i] > values[i + 1]){
                int leftDigit  = values[i];
                int rightDigit = values[i + 1];
                values[i] = rightDigit;
                values[i + 1] = leftDigit;
                swapped++;
            }
        }
        if(swapped == 0){
            stillSwapping = false;
        }
    }
    
    return;
}