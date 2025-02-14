#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int t;
    int f = 1 ;
    int s = 0 ;

    do
    {
         t =get_int("height :  ");
    }
    while ( t < 1 || t > 8);

      for(int h = 0 ; h < t ; h++ )
        {
            for(int p = 7 ; p > s  ; p-- )
            {
               printf(" ");
            }

            for(int w = 0 ; w < f  ; w++ )
            {
                  printf("#");

            }

            printf("   ");

            for(int w = 0 ; w < f  ; w++ )
            {
                  printf("#");

            }


          f++;
          s++;
          printf("\n");
        }

}