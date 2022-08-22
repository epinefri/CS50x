#include <stdio.h>
#include <cs50.h>

float discount(float price, int percent);
int main(void)
{
    float regular = get_float("Regular price ");
    int percent = get_int("Percentage off ");
    float sale = discount(regular, percent);
    printf("Discounted %.2f \n", sale);
}

float discount(float price, int percent)
{
    return price * (100 - percent) / 100;
}