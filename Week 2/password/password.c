// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number, and symbol\n");
    }
}

bool valid(string password)
{
    bool uppercase = false;
    bool lowercase = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            lowercase = true;
        }
        else if (isupper(password[i]))
        {
            uppercase = true;
        }
        else if (isdigit(password[i]))
        {
            number = true;
        }
        else if (ispunct(password[i]))
        {
            symbol = true;
        }

        // If all requirements are met, we can stop the loop early
        if (lowercase && uppercase && number && symbol)
        {
            break;
        }
    }

    // Return true if all requirements are met, false otherwise
    return lowercase && uppercase && number && symbol;
}
