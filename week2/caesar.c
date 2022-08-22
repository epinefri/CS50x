/* encrypts messages using Caesar’s cipher*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// get key
int is_valid(char argv[1]);

int main(int argc, char* argv[])
{
// if argv[1] is a digit
// get plaintext (the text to be "rotated")
    char* plaintext = malloc(sizeof(char) * 255);
    int key, valid;
    if ((argv[1] != 0) && (argc == 2))
    {
        printf("plaintext:  ");
        scanf("%s", plaintext);
        //convert argument (key) to integer (atoi included in stdlib.h)
        key = atoi(argv[1]);
    }

//display Usage: ./caesar key if invalid and return 1 from main
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//encipher by the formula: ciphertext[i] = (plaintext[i] + key) % 26

    char ciphertext[strlen(plaintext)];
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        //if alphabetic, shift by key + formula
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 65;
                ciphertext[i] = (index + key) % 26;
                printf("%c", (ciphertext[i] + 65));
            }
            else if (islower(plaintext[i]))
            {
                int index = plaintext[i] - 97;
                ciphertext[i] = (index + key) % 26;
                printf("%c", (ciphertext[i] + 97));
            }
        }
        //if not alphabetic, leave as is
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
    free(plaintext);
}


