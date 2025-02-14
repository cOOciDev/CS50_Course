#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int t;

    do
    {
        t = get_int("height :  ");
    }
    while (t < 1 || t > 8);

    int line_space = t;

    for (int i = 0; i <= t; i++)
    {
        for (int p = line_space; p > 0; p--)
        {
            if (i != 0)
            {
                printf(" ");
            }
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        line_space--;

        printf("\n");
    }
}