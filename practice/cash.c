#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float t ;
    int calculate(float t);

    do
    {
         t = get_float("how much you want change :  ");
    }
    while ( t < 0.001 );

    int money = calculate( t * 100 );

    printf("you have  %i coins now \n" , money);
}

int calculate(float t)
{
    int money = 0 ;
    float c25 = 25 ;
    float c10 = 10 ;
    float c5 = 5 ;
    float c1 = 1 ;


       while( t >= c25 )
       {
          money++ ;
          t -= c25 ;
       }

       while( t >= c10 )
       {
          money++ ;
          t -= c10 ;
       }

       while(  t >= c5 )
       {
          money++ ;
          t -= c5 ;
       }
       while( t >= c1 )
       {
          money++ ;
          t -= c1 ;
       }

    return money;
}
