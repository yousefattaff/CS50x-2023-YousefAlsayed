#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}cd

int convert(string input)
{
   int length = strlen(input);
   int last = input[length - 1] - '0';
   char new[length];  // Use 'char' instead of 'string' and fix size

   strncpy(new, input, length - 1);  // Copy all characters except the last one
   new[length - 1] = '\0';  // Add null terminator manually
   if (length == 1) return last;  // Base case: if length is 1, return the last digit

   return 10 * convert(new) + last;

}
