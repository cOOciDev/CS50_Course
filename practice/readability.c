#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int counting_index(int letters, int words, int sentences);

int main(void)
{

    int letter_Num = 0;
    int word_Num = 1;
    int sentence_Num = 0;
    string message;

    // get string text from user

    string text = get_string("please write your text here ...");


    // counting letters , words , sentences

    while (text[letter_Num] != '\0')
    {
       if (text[letter_Num] == ' ')
       {
           word_Num++;
       }
       if(text[letter_Num] == '.' || text[letter_Num] == '!' || text[letter_Num] == '?')
       {
          sentence_Num++;
       }

       letter_Num++;
    }
    int index = counting_index(letter_Num, word_Num, sentence_Num);


    if (index < 1)
    {
        index = 1;
        printf("Before Grade %i    \n ", index);
    }
    else if (index >= 16)
    {
        index = 16;
        printf("Grade  %i+   \n ", index);
    }
    else
    {
        printf("Grade %i    \n ", index);
    }
}

// counting index function

int counting_index(int letters, int words, int sentences)
{
    string message ;
    float L = (float) letters / (float) words * 100 ;
    float S = (float) sentences / (float) words * 100 ;
    int index = round(0.0588 *  L - 0.296  * S - 15.8);

    return index;
}
