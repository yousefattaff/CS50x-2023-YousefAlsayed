// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace (string);

int main(int argc, string argv[])
{

    if (argc == 1 || argc != 2 )
    {
        printf ("Usage: ./no-vowels word \n");
        return 1;
    }
    if (argc == 2)
    {
        replace(argv[1]);
        printf ("%s\n", argv[1]);
    }
}

string replace (string word)
{
    for (int i = 0; i < strlen(word); i++)
    {

        switch (word[i])
        {
            case'a':
            word[i] = '6';
            break;
            case'e':
            word[i] = '3';
            break;
            case'i':
            word[i] = '1';
            break;
            case'o':
            word[i] = '0';
            break;
            case'A':
            word[i] = '6';
            break;
            case'E':
            word[i] = '3';
            break;
            case'I':
            word[i] = '1';
            break;
            case'O':
            word[i] = '0';
            break;

        }

    }
    return word;

}