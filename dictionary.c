// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of words in dictionary
int wordcnt = 0;


// Number of buckets in hash table
const unsigned int N = 4;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // This is where I got the hash function and modified it
    // http://homepage.divms.uiowa.edu/~ghosh/2116.10.pdf
    unsigned int hash = 0;
    for (int i = 0 ; word[i] != '\0' ; i++)
    {
        hash = 31*hash + word[i];
    }
    printf("hash: %i of input word: %s\n", hash % 4, word);
    return hash % 4;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO: load the dictionary
    // a word is a char array of LENGTH
    // (probably 45) + 1
    char *word[LENGTH + 1];
    // open the dictionary input file
	FILE* fip = fopen(dictionary,"r");
	if (fip==NULL)
	{
		printf("no such file.");
		return false;
	}
    // alloc memory for a word and
    // pointer to the next node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Memory not allocated.\n");
        return 0;
    }
    // init head, previous node, & last
    node *head = NULL;
    node *pn = NULL;
    
    // init table array
    for (int i = 0; i < N; i++)
    {
        table[i] = head;
    }

    // read the dictionary file into memory
    while (fscanf(fip, "%s", *word) != EOF)
    {
        int b = hash(*word);
        wordcnt++;
        // init head, store word & pointer,
        // & init previous node
        if (table[b] == NULL)
        {
            table[b] = n;
            strcpy(table[b]->word, *word);
            table[b]->next = NULL;
            printf(".....array bucket: %i word is %s\n", b, table[b]->word);
            //pn = n;

        }
        else  // store word & set current pointer
              // to list head & then set head to
              // current pointer
        {
        strcpy(n->word, *word);
        n->next = table[b];
        table[b] = n;
        printf("pt1: %s\n", table[b]->word);    
        //pn = n;
        }
        node *nn = malloc(sizeof(node));
        // make new node the current node
        n = nn;
        
        
        // traverse to the last node
        // while (last->next != NULL)
        // {
        //     last = last->next;
        // }
        // change the next of last node
        //last->next = n;

        // while (last->next != NULL)
        // {
        //     last = last->next;
        // }
        //last->next = n;
        //printf("???  %s\n", table[b]->word);
        // alloc memory for a word and
        // pointer to the next node
        

    }
    // Print list using a loop, by using a temporary variable, tmp, to point
    // to list, the first node. Then, every time we go over the loop, we use
    // tmp = tmp->next to update our temporary pointer to the next node. We
    // keep going as long as tmp points to somewhere, stopping when we get to
    // the last node and tmp->next is null.
    int numwords = 0;
    int bucketnumber = 0;
    for (int b = 0; b < N; b++)
    {
        bucketnumber++;
        for (node *tmp = table[b]; tmp != NULL; tmp = tmp->next)
        {
            numwords++;
            printf("bucketnumber: %i...numwords %i ...list %s\n", 
            bucketnumber, numwords, tmp->word);
        }
        printf("\n");
    }
    // print linked list
    // for (int i = 0; i < N; i++)
    // {
    //     printf("...head of array %i word is %s \n", i, table[i]->word);
    //     if (table[i] != NULL)
    //     {
    //         printf("...table[i]->next word is %s\n", table[i]->next->word);
    //     }

    // }
    // n = head;
    // while (n != NULL)
    // {
    //     printf("linked list: %s\n", n->word);
    //     n = n->next;
    // }



// 	char buf[100];
// 	while (fscanf(fip,"%s", buf) ==1)
// 		printf("%s\n", buf);
//return 0;
    return true;
}




// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    printf("Number of words in dictionary: %i\n", wordcnt);
    return wordcnt;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
