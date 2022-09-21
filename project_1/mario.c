#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("What height is your pyramid? ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {

        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }


}