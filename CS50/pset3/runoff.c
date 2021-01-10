#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CANDIDATES 9
#define MAX_VOTERS 18

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count, candidate_count;
int ranks = 3;

int preferences[MAX_VOTERS][MAX_CANDIDATES];

bool vote(int voter, int rank, string name);

void tabulate();

bool print_winner();

int find_min();

bool is_tie(int min);

void eliminate(int min);

int main(int argc, string candidatesName[])
{
    int k, i, result;

    if(argc <= 1 || argc > MAX_CANDIDATES)
    {
        printf("Invalid number of candidates!\n");
        return 1;
    }

    candidate_count = argc - 1;

    for(k = 0; k < candidate_count; k++)
    {
        candidates[k].name = candidatesName[k+1];
        candidates[k].votes = 0;
        candidates[k].eliminated = false;
    }

    voter_count = get_int("Number of Voters: ");

    string voteName[voter_count][ranks];

    for(k = 0; k < voter_count; k++)
    {
        for(i = 0; i < ranks; i++)
        {
            repeat:
            voteName[k][i] = get_string("Rank %d: ", i + 1);

            result = vote(k, i, voteName[k][i]);

            if(result == 0)
            {
                printf("Invalid Vote!\n");
                goto repeat;
            }
        }
    }

    tabulate();
    
    while(print_winner() == false)
    {
        int minVotes = find_min();
        
        if(is_tie(minVotes) == true)
        {
            printf("Tied!\n");
            break;
        }
        else
        {
            eliminate(minVotes);
        
            for(k = 0; k < candidate_count; k++)
            {
                candidates[k].votes = 0;
            }
            
            tabulate();
        }
    }
    
    /*for(i = 0; i < candidate_count; i++)
    printf("Candidate %s vote: %d\n", candidates[i].name, candidates[i].votes);*/
}

bool vote(int voter, int rank, string name)
{
    for(int k = 0; k < candidate_count; k++)
    {
        for(int i = voter; i < voter_count; i++)
        {
            for(int j = rank; j < ranks; j++)
            {
                if(strcmp(name, candidates[k].name) == 0)
                {
                    preferences[i][j] = k;
                    return true;
                }
            }
        }
    }
    return false;
}

void tabulate()
{
    int i, j = 0, k = 0;

    for(i = 0; i < voter_count; i++)
    {
        while(k < candidate_count)
        {   
            if(k == preferences[i][j])
            {
                if(candidates[k].eliminated == false)
                {
                    candidates[k].votes++;
                    j = 0;
                    break;
                }
                else
                {
                    j++;
                    k = 0;
                    continue;
                }
            }
            else
            k++;
        }
    }
}

bool print_winner()
{
    int halfVoterCount;

    halfVoterCount = (voter_count / 2) + 1;

    for(int k = 0; k < candidate_count; k++)
    {
        if(candidates[k].votes >= halfVoterCount)
        {
            printf("%s\n", candidates[k].name);
            return true;
        }
    }
    return false;
}

int find_min()
{
    int minVote = voter_count;

    for(int k = 0; k < candidate_count; k++)
    {
        if(candidates[k].eliminated != true)
        {
            if(candidates[k].votes < minVote)
            {
                minVote = candidates[k].votes;
            }
        }
    }
    return minVote;
}

bool is_tie(int min)
{
    int count = 0;

    for(int k = 0; k < candidate_count; k++)
    {
        if(candidates[k].eliminated != true)
        {
            if(candidates[k].votes == min)
            count++;
        }
    }
    if(count > 1)
    return true;
    else if(count == 1 || count < candidate_count)
    return false;
    else
    return false;
}

void eliminate(int min)
{
    for(int k = 0; k < candidate_count; k++)
    {
        if(candidates[k].eliminated != true)
        {
            if(candidates[k].votes == min)
            candidates[k].eliminated = true;
        }
    }
}