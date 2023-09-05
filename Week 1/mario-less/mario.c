#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompting the user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height <= 0);
    // printing the space before the hash line
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {

            printf(" ");
        }
        // printing the hash line
        for (int x = 0; x < i; ++x)
        {
            printf("#");
        }
        printf("\n");
    }
}