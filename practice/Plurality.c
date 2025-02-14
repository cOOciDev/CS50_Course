#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAX 8


typedef struct
{
    string name;
    int vote;
}
canditate;


bool vote(string name);
void print_winner();

int canditate_num;

canditate person[MAX];

int main(int argc, string argv[])
{

   canditate_num = argc - 1;

   if (argc < 3)
   {
       printf("its not possible ! please write canditates like inferior line  \n");
       printf(" ./ Plurality name_1 name_2   ... \n");
       return 1;
   }
   else if (argc > 6)
   {
       printf("maximum canditates is 5 persons ! please try again .  \n");
       return 2;
   }
   else
   {
       for (int i = 0; i < canditate_num; i++)
      {
          person[i].name = argv[i+1];
          person[i].vote = 0;

      }

      int voters_num = get_int("Number of voters : ");

      for(int n = 0; n < voters_num; n++)
      {
         string vote_name = get_string("vote : ");
         vote( vote_name);
      }

      print_winner();

      return 0;
   }

}

bool vote(string name)
{
    for(int i =0; i < canditate_num; i++)
    {
       if (strcmp(name, person[i].name) == 0)
       {
          person[i].vote++ ;
          return true;
       }
    }
    return false;
}

void print_winner(void)
{
    int max_votes =0;

    for(int i = 0; i < canditate_num; i++)
    {
        if(person[i].vote > max_votes)
        {
            max_votes = person[i].vote;
        }
    }

    for(int i = 0; i < canditate_num; i++)
    {
        if(person[i].vote == max_votes)
        {
           printf("%s \n",person[i].name);
        }
    }

    return;
}