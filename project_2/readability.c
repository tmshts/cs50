#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main(void)
{
    string s = get_string("Text: ");
    printf("%s\n", s);

    int countl = 0; //counter for letters
    int i = 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (islower(s[i]) || isupper(s[i])) //characters contain lower or upper letter
        {
            countl++;
            //printf("Yes letter %c\n", s[i]); just for checking
        }
    }
    //printf("%i letter(s)\n", countl);

    int countw = 0; //counter for words
    int j = 0;

    for (j = 0; j <= strlen(s); j++)
    {
        if (s[j] == '\0' || isspace(s[j])) //characters contain \0 or space
        {
            countw++;
            //printf("Yes space  %c\n", s[j]); just for checking
        }
    }
    //printf("%i word(s)\n", countw);

    int counts = 0; //counter for sentences
    int k = 0;

    for (k = 0; k <= strlen(s); k++)
    {
        if (s[k] == '.' || s[k] == '!' || s[k] == '?') //characters contain . ! ?
        {
            counts++;
            //printf("Yes %c\n", s[k]); just for checking
        }
    }
    //printf("%i sentence(s)\n", counts);

    float L = ((float) countl / (float) countw) * 100;
    //printf("%.2f\n", L);

    float S = ((float) counts / (float) countw) * 100;
    //printf("%.2f\n", S);



    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("Index is %f\n", index);

    int grade = round(index);


    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}