#include <stdio.h>

int main(void)
{
    int pw = 1234, pwGuess;
    
    do
    {
    printf("Enter a 4-digit password: ");
    scanf("%d", &pwGuess);
    }
    while(pwGuess != pw);
    
    printf("Correct Guess!\n");

}