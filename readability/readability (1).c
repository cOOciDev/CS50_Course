#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count(string text);

int letter_Num = 0;
int word_Num = 1;
int sentence_Num = 0;

int main(void)
{



    // get string text from user

    string text = get_string("please write your text here ...");

    // counting letters , words , sentences

    count(text);

    float av_L = letter_Num * 100.0 /  word_Num;
    float av_S = sentence_Num * 100.0 /  word_Num;
    float grade = 0.0588 * av_L - 0.296 * av_S - 15.8;
    printf("float grade %f", grade);
    int index = round(grade);
    printf("int index %i", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count(string text)
{


    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word_Num++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_Num++;
        }
        if (isalpha(text[i]))
        {
            letter_Num++;
        }

    }
    return word_Num;
    return sentence_Num;
    return letter_Num;
}
