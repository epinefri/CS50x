/* prompts the user for a positive integer between 1 and 8, inclusive, and prints a mirrored pyramid pattern of hashes */
#include <stdio.h>

int main(void)
{
    int height, line, left, right, spc;

// prompt the user for height, re-prompt if input is not between 1 and 8
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    }
    while (height < 1 || height > 8);

// for each row
    for (line = 0; line < height; line++)
    {
    // print spaces
        for (spc = 0; spc < height - line - 1; spc++)
        {
            printf(" ");
        }

    //left hashes
        for (left = 0; left <= line; left++)
        {
            printf("#");
        }
    // two middle spaces
        printf("  ");
        
    //right hashes + new line
        for (right = 0; right <= line; right++)
        {
            printf("#");
        }
        printf("\n");
    }
}