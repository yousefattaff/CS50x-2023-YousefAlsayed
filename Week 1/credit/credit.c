#include <cs50.h>
#include <stdio.h>

// Function to calculate the checksum using Luhn's algorithm
bool is_valid_checksum(long cardnum)
{
    int sum = 0;
    bool alternate = false;

    while (cardnum > 0)
    {
        int digit = cardnum % 10;
        cardnum /= 10;

        if (alternate)
        {
            int double_digit = digit * 2;
            sum += (double_digit / 10) + (double_digit % 10);
        }
        else
        {
            sum += digit;
        }

        alternate = !alternate;
    }

    return sum % 10 == 0;
}

int main(void)
{
    long cardnum = get_long("Number: ");

    // Determine the length of the credit card number
    int length = 0;
    long temp = cardnum;
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // Determine the starting digits of the credit card number
    int first_two_digits = cardnum / 100000000000000; // For 15 and 16-digit cards
    int first_digit = cardnum / 1000000000000000;    // For 16-digit cards
    int first_one_digit = cardnum / 1000000000000;    // For 13-digit cards

    // Check the card type and validity based on the rules
    if (is_valid_checksum(cardnum))
    {
        if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 13 || length == 16) && (first_one_digit == 4))
        {
            printf("VISA\n");
        }
        else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
