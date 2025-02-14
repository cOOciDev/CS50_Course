#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float t ;
    float c25 = 25 ;
    float c10 = 10 ;
    float c5 = 5 ;
    float c1 = 1 ;
    do
    {
         t = get_float("how much you want change :  ");
    }
    while ( t <= 0);

    int money = round ( t * 100);
     money = 0 ;

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
    printf("you have  %i coins now \n" , money);
}