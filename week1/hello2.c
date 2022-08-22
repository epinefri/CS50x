/* prompts the user for their name and then prints "hello, so-and-so" */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char *p = malloc(20);

//name input
    printf("What's your name? ");
    scanf("%s", p);

//print result
    printf("Hello, %s! :)\n", p);

// free memory
    free(p);
}