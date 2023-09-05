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
    // setting the number of iteration
    for (int i = 1; i <= height; i++)
    {
        // doing spaces on left
        for (int j = 0; j < height - i; j++)
        {

            printf(" ");
        }
        // printing the hash line after spaces on left
        for (int x = 0; x < i; ++x)
        {
            printf("#");
        }
        // printing two plank spaces after the first pyramid
        for (int v = 0; v < 2; v++)
        {
            printf(" ");
        }
        // printing the other pyramid on the right
        for (int y = 0; y < i; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}