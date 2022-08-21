#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //get input
    string text = get_string("Enter text: ");

    //count letters, words, sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //coleman-liau index index = 0.0588 * L - 0.296 * S - 15.8
    int grade = round(0.0588 * (letters * 100.0 / words) - 0.296 * (sentences * 100.0 / words) - 15.8);

    // print
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (((text[i] > 64) && (text[i] < 91)) || ((text[i] > 96) && (text[i] < 123)))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            words += 1;
        }
        else
        {
            words += 0;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == 46) || (text[i] == 63) || (text[i] == 33))
        {
            sentences += 1;
        }
        else
        {
            sentences += 0;
        }
    }
    return sentences;
}