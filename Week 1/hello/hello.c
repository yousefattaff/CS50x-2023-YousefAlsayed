#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prombting the user for his name
    string name = get_string("What's your name? ");
    //printing his name 
    printf("Hello, %s\n", name);
}