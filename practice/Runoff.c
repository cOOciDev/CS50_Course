#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_candidates 5
#define MAX_voters 50

typedef struct
{
    string name;
    int vote;
    bool eliminated;
}
canditate;

int prefrences[MAX_voters][MAX_candidates];

bool vote(int voter, int rank, string name);
bool print_winner(void);
void tabulate(void);
void eliminate(int min);
bool is_tie(int min);
int find_min(void);

int canditate_num;
int voters_num ;

canditate person[MAX_candidates];

int main(int argc, string argv[])
{

   canditate_num = argc - 1;


   if (argc < 3)
   {
       printf("its not possible ! please write canditates like inferior line  \n");
       printf(" ./ Plurality name_1 name_2   ... \n");
       return 1;
   }
   else if ((argc - 1) > MAX_candidates)
   {
       printf("maximum canditates is %i persons ! please try again .  \n", MAX_candidates);
       return 2;
   }
   else
   {
       for (int i = 0; i < canditate_num; i++)
      {
          person[i].name = argv[i+1];
          person[i].vote = 0;
          person[i].eliminated = false;

      }

            //   get votes from voters ..................................

       voters_num = get_int("Number of voters : ");
       if (voters_num > MAX_voters)
       {
          printf("maximum voters is %i persons ! please try again .  \n", MAX_voters);
          return 3;
       }

       for(int v = 0; v < voters_num; v++)
       {
          for(int c = 0; c < canditate_num; c++)
          {
            string vote_name = get_string("Rank %i : ", c+1);
            if(vote(v , c, vote_name) == false)
             {
                 printf("Invalid vote. \n");
                 return 4;
             }
          }

          printf("\n");
       }




     while(true)
     {
        tabulate();

        bool winner = print_winner();
        if (winner)
        {
            break;
        }

        int min = find_min();

        bool tie = is_tie(min);
        if (tie)
        {
            for(int i = 0; i < canditate_num; i++)
            {
                if(person[i].eliminated == false)
                {
                    printf("%s \n",person[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for(int i = 0; i < canditate_num; i++)
        {
            person[i].vote = 0;
        }


     }
     return 0;
   }

}

         //    bool vote method for count votes .................................

bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < voters_num; i++)
    {
        if(strcmp(person[i].name, name ))
        {
           prefrences[voter][rank] = i;
           return true;
        }
    }
    return false;
}



             //    void print for show the winner .................................

bool print_winner()
{
   int point = voters_num / 2 ;

   for(int i = 0; i < canditate_num; i++)
   {
       if(person[i].vote > point)
       {
           printf("%s \n",person[i].name);
           return true;
       }
   }

    return false;
}

         //    void find_min for  .................................

int find_min()
{
    int smallest_vote = voters_num;
   for(int i = 0; i < canditate_num; i++)
   {
       if(person[i].eliminated == false)
       {
           if(person[i].vote < smallest_vote)
           {
               smallest_vote = person[i].vote;
           }
       }
   }
   return smallest_vote;
}

        //    void is_tie for  .................................

bool is_tie(int min)
{
   for(int i = 0; i < canditate_num; i++)
   {
       if(person[i].vote > min )
       {
           return false;
       }
   }
   return true;
}

        //    void eliminate for  .................................

void eliminate(int min)
{
   for(int i = 0; i < canditate_num; i++)
   {
       if(person[i].vote == min )
       {
           person[i].eliminated = true;
       }
   }
   return;
}

        //    void tabulate for refreshing the vote each step .................................

void tabulate(void)
{
   for(int v = 0; v < voters_num; v++)
   {
       for(int c = 0; c < canditate_num; c++)
       {
           if((person[prefrences[v][c]].eliminated) == false)
           {
               person[prefrences[v][c]].vote++ ;
               break;
           }
       }
   }
   return;
}