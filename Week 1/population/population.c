#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;
    int year = 0;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < n);

    if (n == end_size)
    {
        printf("Years= %i", year);
    }
    else
    {
        do
        {
            n = n + (n / 3) - (n / 4);
            year++;
        }
        while (n < end_size);
    }
    printf("Years: %i", year);
}
