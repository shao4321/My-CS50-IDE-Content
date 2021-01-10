// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int numberOfWords;

// Number of buckets in hash table
const unsigned int N = 20000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashVal;
    hashVal = hash(word);

    node* cursor = table[hashVal];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        return true;

        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long int value = 0;
    unsigned int i;
    unsigned int word_len = strlen(word);

    // do several rounds of multiplication
    for (i = 0; i < word_len; i++) 
        value = value * 37 + tolower(word[i]);

    // make sure value is 0 <= value < TABLE_SIZE
    value = value % N;

    return value;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for(int j = 0; j < N; j++)
    {
        table[j] = NULL;
    }
    //Open dictionary file
    FILE* fileptr = fopen(dictionary, "r");

    if(fileptr == NULL)
    {
        printf("Error opening dictionary file.\n");
        return false;
    }

    //Read strings from file
    char* dict = malloc(LENGTH + 1);
    int hashNum;
    
    if(dict == NULL)
    {
        printf("Error storing dict.\n");
        return false;
    }
    
    numberOfWords = 0;
    
    while(fscanf(fileptr, "%s", dict) != EOF)
    {
        node* n1 = (node*)malloc(sizeof(node));
        if(n1 == NULL)
        {
            printf("Error storing node.\n");
            return false;
        }
        strcpy(n1->word, dict);

        hashNum = hash(n1->word);

        n1->next = table[hashNum];
        table[hashNum] = n1;
    
        numberOfWords++;
    }
    
    free(dict);
    fclose(fileptr);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int i;

    for(i = 0; i < N; i++)
    {
        node* cursor = table[i];
        node* tmp = table[i];
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
