#include <cs50.h>
#include <stdio.h>

int count(long card);
int first_dig(long card);
int do_sum(long card);
int do_sum2(long card);
int main(void)
{
    //get input
    long card = get_long("Card number input: ");

    // count digits
    int digits = count(card);

    // find first 2 digits
    int first = first_dig(card);

//check if valid
    long sum = do_sum(card);
    long sum2 = do_sum2(card * 10);
    if ((sum + sum2) % 10 == 0)
    {
        //check type of card
        if ((digits == 15) && ((first == 34) || (first == 37)))
        {
            printf("AMEX\n");
        }
        else if (((digits == 13) || (digits == 16)) && (first / 10 == 4))
        {
            printf("VISA\n");
        }
        else if ((digits == 16) && ((first == 51) || (first == 52) || (first == 53) || (first == 54) || (first == 55)))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

//count digits
int count(long card)
{
    int digits = 0;
    do
    {
        card = (card / 10);
        digits++;
    }
    while (card != 0);
    return digits;
}

//find first 2 digits
int first_dig(long card)
{
    do
    {
        card = (card / 10);
    }
    while (card > 100);
    return card;
}


//double sum
int do_sum(long card)
{
    long digit = 0;
    long sum = 0;
    do
    {
        card = (card / 10);
        digit = (card % 10);
        card = (card / 10);
        if (digit < 5)
        {
            sum = sum + (digit * 2);
        }
        else
        {
            sum = sum + ((digit * 2 / 10) + (digit * 2 % 10));
        }
    }
    while (card > 10);
    return sum;
}

//single sum
int do_sum2(long card)
{
    long digit = 0;
    long sum = 0;
    do
    {
        card = (card / 10);
        digit = (card % 10);
        card = (card / 10);
        sum = sum + digit;
    }
    while (card > 10);
    return sum;
}