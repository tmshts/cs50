#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates - global variable
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) //creating a structure
//Alice Bob Charlie - candidate_count 3
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0; //related to the vote function
    }

    int voter_count = get_int("Number of voters: "); //voter_count 3

    // Loop over all voters
    for (int i = 0; i < voter_count; i++) //Alice Bob Charlie
    {
        string name = get_string("Vote: ");//1.vote Alice

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) //iterate from Alice to Charlie
    {
        if (strcmp(candidates[i].name, name) == 0)
//vote for Alice -> +1 but vote for Bob -> nothing because no match Alice is not equal to Bob
        {
            candidates[i].votes++; //Alice is equal to Alice
            //printf("For candidate %s voted\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int leader = 0; // set fix leader in order to compare with iteration

    for (int l = 0; l < candidate_count; l++) //iterate from votes for Alice to votes for Charlie in order to find the biggest number
    {
        if (leader < candidates[l].votes)//compare votes for base leader with votes for 1st candidate

//if Alice has more than Bob, Alice stay leader
//if Alice has less than Charlie -> the leader swap from Alice to Charlie -> leader = candidate[2].votes - biggest number of votes
        {
            leader = candidates[l].votes;//swap
        }
        /*else
        {
            return;
        }*/
        //printf("With %i votes won %s\n", candidates[l].votes, candidates[l].name);
    }
    //printf("%i\n", leader);

    //printf("With %i votes won %s\n", candidates[l].votes, candidates[l].name);
    //printf("%i votes for %s\n", leader, candidates[l].name);


    for (int w = 0; w < candidate_count; w++) //interate from votes for Alice to votes for Charlie
    {
        if (candidates[w].votes == leader) //leader is 4...
        {
            printf("%s\n", candidates[w].name);
        }
        /*else
        {
            return;
        }*/
    }
    //printf("%s", candidates[w].name);

    return;
}