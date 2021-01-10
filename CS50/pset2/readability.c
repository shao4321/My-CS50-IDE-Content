#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int count, i, grade;
    float count_letters = 0, count_words = 1, count_sentences = 0;
    float L, S, index;

    string text = get_string("Text: ");

    count = strlen(text);

    for(i = 0; i < count; i++)
    {
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        count_letters++;
    }

    for(i = 0; i < count; i++)
    {
        if(text[i] == ' ')
        count_words++;
    }

    for(i = 0; i < count; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        count_sentences++;
    }

    L = (count_letters / count_words) * 100;

    S = (count_sentences / count_words) * 100;

    index = (0.0588 * L) - (0.296 * S) - 15.8;

    grade = round(index);

    if(grade < 1)
    printf("Before Grade 1\n");

    else if(grade >= 16)
    printf("Grade 16+\n");

    else
    printf("Grade %d\n", grade);
}