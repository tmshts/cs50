// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
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

// Number of buckets in hash table
const unsigned int N = 10000;

int words = 0;//for counting

// Hash table
node *table[N];//array of linkedlist
//[node1, node2, node3] -> each node represents the head

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    int hash_index = hash(word);//hash the word to get hash index

    node *trav = table[hash_index];

    //int i = 0;
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true; //word is in the dictionary
        }
        else
        {
            trav = trav->next;//does not match -> goes to next node
        }
        //i++;
    }

    return false;//word is not in the dictionary
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //Math using all the letters...for loop
    int count_letters = 0; //ASCI value starting from 0
    for(int h = 0; h < strlen(word); h++ )//iterate through each character of words
    {
        int c = tolower(word[h]);//case-insensitive
        count_letters = count_letters + c; //counting ASCI value till end of the string(strlen(word))
    }

    return (count_letters % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    //open the dictionary
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)//nothing in the dictionary
    {
        //printf("The file could not be opened.\n");
        fclose(file);
        return false;
    }

    //Read strings from file one at a time
    char word[LENGTH + 1];//initialize the word in the dictionary, which is a buffer

    while(fscanf(file, "%s", word) != EOF)//generating words until end of dictionary
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)//no words in the node
        {
            free(n);//n contains NULL -> not necessary to store -> free
            return false;// return error
        }
        strcpy(n->word, word);//copy each word in dictionary
        n->next = NULL;

        //has word to obtain a hash value
        int hash_index = hash(word);//hash each word from the text and get the hash index

        //node *head = table[hash_index];//initialize the head of each hash_index in the hash table

        //insert each word from dictionary(node) into hash table
        if (table[hash_index] == NULL) //good point table[index] instead of head
        {
            table[hash_index] = n;
        }
        else
        {
            n->next = table[hash_index];//connect the new node with the head of linkedlist inside of hash table
            table[hash_index] = n;//good point table[index] instead of head
        }
        words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    /*int count_words = 0;
    for(int s = 0; s < table[N]; s++)
    {
        count_words = count_words + s;
    }*/

    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    for (int u = 0; u < N; u++)//iterate through each head of the hash table
    {
        node *trav = table[u];

    	while(trav != NULL)
    	{
    	    node *temp = trav;//another variable to keep track where we are in the linkedlist
    	    trav = trav->next;//go to the next node
    	    free(temp);//free memory for temp -> trav is safe in the next node
    	}
    }
    return true;
}