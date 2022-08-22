/* determines which of two Scrabble words is worth more */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);

int main(void)
{
    // Get input words from both players
    char* word1 = malloc(sizeof(char) * 20);
    char* word2 = malloc(sizeof(char) * 20); 
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);
    
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    free(word1);
    free(word2);
}
int compute_score(char* word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
        if (islower(word[i]))
        {
            score += POINTS[word[i] - 97];
        }
        else if (isupper(word[i]))
        {
            score += POINTS[word[i] - 65];
        }
    return score;

}
