#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>
#define MAX 9 // MAX Number of Candidates

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name);

void print_winner();

int main(int argc, string candidatesName[])
{
    int voters, k, i, n;
    
    if(argc <= 1 || argc > MAX)
    {
        printf("Invalid number of candidates!\n");
        return 1;
    }

    candidate_count = argc - 1;

    for(k = 0; k < candidate_count; k++)
    {
        candidates[k].name = candidatesName[k+1];
        candidates[k].votes = 0;
    }

    voters = get_int("Number of Voters: ");
    
    string voteName[voters];
    
    for(k = 0; k < voters; k++)
    {
        repeat:
        voteName[k] = get_string("Vote: ");
        
        int result = vote(voteName[k]);
        
        if(result == 0)
        {
            printf("Invalid Vote!\n");
            goto repeat;
        }
    }
    
    print_winner();
    
    return 0;
}

bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int i, k, n;
    string topVoted = candidates[0].name;
    string topVoted2[candidate_count];

    int topVotes = candidates[0].votes;

    for(k = 1; k < candidate_count; k++)
    {
        if(candidates[k].votes > topVotes)
        {
            topVoted = candidates[k].name;
            topVotes = candidates[k].votes;
        }
    }

    for(k = 0, i = 0; k < candidate_count; k++)
    {
        if(candidates[k].votes == topVotes)
        {
            if(strcmp(candidates[k].name, topVoted) != 0)
            {
                topVoted2[i] = candidates[k].name;
                i++;
            }
        }
    }

    printf("%s\n", topVoted);

    n = 0;

    if(i > 0)
    {
        while(n < i)
        {
            printf("%s\n", topVoted2[n]);
            n++;
        }
    }
}