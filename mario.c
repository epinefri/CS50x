#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int row, col, spc, height;

// input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

// print loops
    for (row = 0; row < height; row++)

    {
// print spaces
        for (spc = 0; spc < height - row - 1; spc++)
        {
            printf(" ");
        }

// print #
        for (col = 0; col <= row; col++)
        {
            printf("#");
        }
        printf("\n");
    }
}
