#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print both scores
    printf("Player 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);

    // Determine the winner and print the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        // Convert the character to uppercase to simplify the point lookup
        char scrabble = toupper(word[i]);

        if (scrabble >= 'A' && scrabble <= 'Z')
        {
            // Get the index in POINTS array corresponding to the letter
            int index = scrabble - 'A';
            // Increment the score by the points assigned to the letter
            score += POINTS[index];
        }
        else if (ispunct(word[i]))
        {
            continue;
        }
    }
    return score;
}
