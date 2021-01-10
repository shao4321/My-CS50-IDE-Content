#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    double changeAmt = get_double("Change owed: ");

    while(changeAmt < 0)
    {
        printf("Change owed: ");
        changeAmt = get_double(0);
    }

    int y=0; //y is the number of 0.25cents coins
    int x=0; //x is the number of 0.10cents coins
    int m=0; //m is the number of 0.05cents coins
    int n=0; //n is the number of 0.01cents coins

    int totalCoins;

    int changeAmtFormatted = (double)changeAmt * 100;

    while(changeAmtFormatted >= 25)
    {
        changeAmtFormatted = changeAmtFormatted - 25;
        y++;
    }

    while(changeAmtFormatted >= 10)
    {
        changeAmtFormatted = changeAmtFormatted - 10;
        x++;
    }

    while(changeAmtFormatted >= 5)
    {
        changeAmtFormatted = changeAmtFormatted - 5;
        m++;
    }

    while(changeAmtFormatted >= 1)
    {
        changeAmtFormatted = changeAmtFormatted - 1;
        n++;
    }

    totalCoins = y + x + m + n;

    printf("%i\n", totalCoins);

}
