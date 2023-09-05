#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    text = get_string("Text: ");
    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int sentences_count = count_sentences(text);
    float L = ((float) letters_count / words_count) * 100.0;
    float S = ((float) sentences_count / words_count) * 100.0;
    int index;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int length = strlen(text);
    int letters_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) && !ispunct(text[i]))
        {
            letters_count++;
        }
    }
    return letters_count;
}
int count_words(string text)
{
    int length = strlen(text);
    int words_count = 0;
    char hyphen = '-';
    int i;
    for (i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            words_count++;
        }
    }
    words_count++;
    return words_count;
}
int count_sentences(string text)
{
    int length = strlen(text);
    int sentences_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences_count++;
        }
    }
    return sentences_count;
}
