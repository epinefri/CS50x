#include <stdio.h>
#include <cs50.h>

int main(void)
{
//name input
    string name = get_string("What's your name? ");
//print result
    printf("hello, %s\n", name);
}