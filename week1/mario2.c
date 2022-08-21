#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, line, coll, colr, spc;
// input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

//print
    for (line = 0; line < height; line++)
    {
//spaces
        for (spc = 0; spc < height - line - 1; spc++)
        {
    printf(" ");
        }
//left hashes + 2 middle spaces
        for (coll = 0; coll <= line; coll++)
        {
            printf("#");
        }
        printf("  ");
//right hashes + new line
        for (colr = 0; colr <= line; colr++)
        {
            printf("#");
        }
        printf("\n");
    }
}