/**
 * Implements a dictionary's functionality.
 */

// much help from davidventuri
// https://github.com/davidventuri/harvard-cs50/blob/master/pset5/dictionary.c

#include <stdlib.h> 
#include <stdbool.h>

#include "dictionary.h"

// hashing function prototype
int hash_word(char *word);

// initialize hash table
node *hash_table[HT_SIZE];

// set size counter to zero
unsigned int word_count = 0;

// standardize length of words
char word[LENGTH + 1] ;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // copy current word
    char current_word[LENGTH + 1];
    
    int length = strlen(word);
    
    // make it lowercase
    for(int i = 0; i < length; i++){
        current_word[i] = tolower(word[i]);
    }
    
    // add null terminator to end of array
    current_word[length] = '\0';
    
    // get hash value
    int hash = hash_word(current_word);
    
    // point to the cursor node of the bucket
    node* cursor = hash_table[hash];
    
    while(cursor != NULL){
        if(strcmp(cursor->word, current_word) == 0){
            // word is found
            return true;
        } else {
            // point to the next node
            cursor = cursor->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int hash_value;
    
    // make hash indecies null
    for(int i = 0; i < HT_SIZE; i++){
        hash_table[i] = NULL;
    }
    
    // open dictionary
    FILE* file = fopen(dictionary, "r");
    // cant open dictionary
    if(file == NULL){
        return false;
    }
    
    while(fscanf(file, "%s\n", word) != EOF){
        node* new_node = malloc(sizeof(node));
        if(new_node == NULL){
            // printf("out of memory\n");
            // unload();
            return false;
        }
        strcpy(new_node->word, word);
        hash_value = hash_word(word);
        
        word_count++;
        
        if(hash_table[hash_value] == NULL){
            hash_table[hash_value] = new_node;
            new_node->next = NULL;
        } else {
            new_node->next = hash_table[hash_value];
            hash_table[hash_value] = new_node;
        }
        
    }
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HT_SIZE; i++)
    {
        node* cursor = hash_table[i];
        while (cursor != NULL)
        {
            // maintain connection to linked list using temp
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}


/**
 * A case-insensitive implementation of the djb2 hash function.
 * Change NUM_BUCKETS to whatever your number of buckets is.
 *
 * Adapted by Neel Mehta from
 * http://stackoverflow.com/questions/2571683/djb2-hash-function.
 */
int hash_word(char *word)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(word); i<n; i++) {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HT_SIZE;
}