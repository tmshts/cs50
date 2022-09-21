#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
//global variables
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)//creating a structure where
//all the candidates start with 0 votes
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++) //5 candidates = 5 ranks
// it stores all of the votes
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// preferences[i][j] is jth preference for voter i
//int preferences[MAX_VOTERS][MAX_CANDIDATES];
//int preferences[voter_count][candidate_count]

// Record preference if vote is valid
bool vote(int voter, int rank, string name) //return true or false
{
    //int preferences[voter_count][candidate_count];
    //goal is to fill the preference multidimensial array

    for (int v = 0; v < candidate_count; v++) //iterate through number of candidates
    {
        if (strcmp(candidates[v].name, name) == 0) //same name
//candidates[j].votes++;
        {
            preferences[voter][rank] = v; //fill the matrix
            printf("%i in the row of candidates is %s and got a vote.\n", v + 1, candidates[v].name);
            return true;
        }
//printf("\n");
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void) //no return value
{
    //goal is update vote counts for all non-eliminated candidates

    for (int v = 0; v < voter_count; v++) //iterate through voters in matrix
    {
        for (int p = 0; p < candidate_count; p++) //iterate through preferences/ranks in matrix
        {
            if (candidates[preferences[v][p]].eliminated != true) //candidate is not eliminated - he gets vote
            {
                candidates[preferences[v][p]].votes++; //update
                //return;
                break; //IMPORTANT!
            }
        }
        //if (preferences[i][0] == (char) candidates[i].name)
        //candidates[i].votes++;
        //printf("another voter\n");
    }
    /*for (int j = 0; j < candidate_count; j++)
    {
        printf("candidate %s got %i votes.\n", candidates[j].name, candidates[j].votes);
    }*/
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void) //should give true or false
{
    int majority = (voter_count / 2) + 1;  //8 : 2 = 4 + 1...5 : 2 = 2 + 1

    //for (int w = 0; w < candidate_count; w++)
    for (int w = 0; w < candidate_count; w++)
    {
        if (candidates[w].votes >= majority)
        {
            printf("%s\n", candidates[w].name);
            return true;
        }
        /*else
        {
            printf("Nobody won");
            return false;
        }*/
    }
    //printf("Nobody won");
    return false;

}

// Return the minimum number of votes any remaining candidate has
int find_min(void) //return should give the min value
{
    int min = voter_count;//look for min number -> set min as the higher possible number and change accordingly
    //like in plurality but reverse solution

    for (int m = 0; m < candidate_count; m++) //iterate through the candidates
    {
    
        if (candidates[m].votes < voter_count && candidates[m].eliminated == false) //condition
        {
            min = candidates[m].votes; //swap
        }
//return min;
    }

    return min; //Bob 1

}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min) //result will be just true or false
{

    for (int t = 0; t < candidate_count; t++) //iterate through candidates
    {
        if (candidates[t].votes != min && candidates[t].eliminated == false)//Bob is 1 -> Alice 2 ist not equal to Bob 1 -> Alice stay false
        {
            //candidates[t].eliminated = true;
            //printf("Tied\n");//checking
            return false; //change from Bob 1 false -> Bob 1 true
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min) //from false to true
{

    for (int e = 0; e < candidate_count; e++)
    {
        if (candidates[e].eliminated == false && candidates[e].votes == min) //Bob ist still false here
        {
            candidates[e].eliminated = true; //Bob is changed from false to true
        }
    }

    return;
}
