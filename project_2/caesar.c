#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{

    if (argc == 2) // check whether an user types just one argument after ./caesar
    {
        int count = 0;

        for (int i = 0; i < strlen(argv[1]); i++) //iterate through each character in order to find out whether a character is digit
        {
            if (isdigit(argv[1][i]) /*&& argv[1][1] != 0*/) //yes, a character is digit
            {
                //printf("%c\n", argv[1][i]);
            }
            else // if the argv[1] contains at least one character which is not digit -> count it
            {
                count++;
            }

        }
        if (count >= 1) //if there was at least one character which was not digit
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else //all characters in argv[1] were digit
        {
            int k = atoi(argv[1]); //convert from string to integer
            //printf("%i + 20 = %i\n", atoi(argv[1]), atoi(argv[1]) + 20); just checking

            string s = get_string("plaintext: ");

            printf("ciphertext: ");

            for (int d = 0; d < strlen(s); d++) //iterate through the lenght of the plaintext
            {
                if (isalpha(s[d]) && isupper(s[d])) //choose just upper letter
                {
                    int u = s[d];

                    int j = (((u + k) - 65) % 26) + 65; //algorithms for upper case - wrap
                    printf("%c", j);
                }

                else if (isalpha(s[d]) && islower(s[d])) //choose just lower letter
                {
                    int l = s[d];

                    int m = (((l + k) - 97) % 26) + 97; //algorithms for lower case - wrap
                    printf("%c", m);

                    //printf(" lower number %i", m); just checking
                    //printf(" lower letter %c", m); just checking
                }
                else //in case of some other characters
                {
                    printf("%c", s[d]);
                }
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}