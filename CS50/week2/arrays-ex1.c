#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int n=5;
    int x,y;
    // Scores
    int scores[n];
    
    for(x=1; x<=n; x++)
    {
    scores[x] = get_int("Enter a score: ");
    }
    
    for(x=1; x<=n; x++)
    {
    printf("scores[%i] = %i\n", x , scores[x]);
    }
    
    // Print average
    //printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / 3);
}