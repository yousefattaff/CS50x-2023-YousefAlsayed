#include <ctype.h> // Include ctype.h for the toupper and tolower functions
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h" // Include your header file

bool dictionary_is_loaded = false;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 26;
node *table[N];

bool check(const char *word)
{
    node *checker = table[hash(word)];
    while (checker != NULL)
    {
        if (strcasecmp(word, checker->word) == 0)
        {
            return true;
        }
        checker = checker->next;
    }

    return false;
}

unsigned int hash(const char *word)
{
    const unsigned int PRIME = 31;
    unsigned int hashValue = 0;
    while (*word)
    {
        char lowercaseChar = tolower(*word);
        hashValue = (hashValue * PRIME + lowercaseChar) % N;
        word++;
    }
    return hashValue;
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char string[LENGTH + 1];

    while (fscanf(file, "%s", string) != EOF)
    {
        if (strlen(string) > LENGTH) // Check for word length
        {
            fclose(file);
            return false;
        }

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(new_node->word, string);
        new_node->next = table[hash(string)];
        table[hash(string)] = new_node;
    }

    fclose(file);
    dictionary_is_loaded = true;
    return true;
}

unsigned int size(void)
{
    if (dictionary_is_loaded == 1)
    {
        unsigned int word_count = 0;
        for (int i = 0; i < N; i++)
        {
            node *cursor = table[i];
            while (cursor != NULL)
            {
                word_count++;
                cursor = cursor->next;
            }
        }
        return word_count;
    }
    else
    {
        return 0;
    }
}

bool unload(void)
{
    if (dictionary_is_loaded == 1)
    {
        for (int i = 0; i < N; i++)
        {
            node *cursor = table[i];
            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);
            }
        }
        dictionary_is_loaded = false;
        return true;
    }
    else
    {
        return false;
    }
}
