#include <stdio.h>

void cal_years(int days);

int main(void)
{
    int days;

    printf("Number of Days: ");
    scanf("%d", &days);

    cal_years(days);
}

void cal_years(int days)
{
    int y, w, d;
    y = days / 365;
    w = (days - y*365) / 7;
    d = days - y*365 - w*7;
    printf("Years: %i\nWeeks: %i\nDays: %i\n", y, w, d);
}