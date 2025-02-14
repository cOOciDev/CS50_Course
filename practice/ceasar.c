#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string check = argv[1];
    for (int i = 0; i < strlen(check); i++)
    {
        if (isalpha(check[i]))
        {
            printf("Usage : ./ceasar key \n");
            return 1;
        }
    }

    if (argc != 2)
    {
       printf("Usage : ./ceasar key \n");
        return 1;
    }
    else
    {
        char c;
        int key = atoi(argv[1]);

        string text = get_string("plaintext : ");

        printf("ciphertext : ");
        for (int i = 0; i < strlen(text); i++)
        {
            if (isupper(text[i]))
            {
                int a = text[i] - 65 ;
                int b = (a + key) % 26 ;
                c = b + 65 ;
                printf("%c", c);
            }
            else if (islower(text[i]))
            {
                int a = text[i] - 97 ;
                int b = (a + key) % 26 ;
                c = b + 97 ;
                printf("%c", c);
            }
            else
            {
                printf("%c",text[i]);
            }
        }
        printf("\n");
        return 0;
    }
}