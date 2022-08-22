/* prompts the user for a positive integer between 1 and 8, inclusive, and prints a pyramid pattern of hashes */

#include <stdio.h>

int main(void)
{
    int row, spc, hsh, height;

// prompt the user for height, re-prompt if input is not between 1 and 8
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    }
    while (height < 1 || height > 8);

// for each row
    for (row = 0; row < height; row++)

    {
        // print spaces
        for (spc = 0; spc < height - row - 1; spc++)
        {
            printf(" ");
        }

        // print hashes
        for (hsh = 0; hsh <= row; hsh++)
        {
            printf("#");
        }
        printf("\n");
    }
}


/* example for height = 3
row 0; < 3
	spc 0 < 3-0-1	----		prints 1 space                      
	spc 1 < 3-0-1	----		prints 2nd space
	
	hsh 0 <= 0   	----		prints 1 hash                   _ _ #
	

row 1; < 3
	spc 0 < 3 - 1 - 1	----	prints 1 space                   _ # #
	
	hsh 0 <= 1 		- ---       prints 1 hash
	hsh 1 <= 1 		-----       prints 2nd hash

row 2; < 3
	spc 0 < 3 - 2 - 1 false no space 
	hsh 0 <= 2
		1
		2       ---              prints 3 hashes                # # #
*/