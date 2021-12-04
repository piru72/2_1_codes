#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned long long int n;
    unsigned long long int candy=0;
    scanf("%d",&n);
    
    if      (n == 0)
    {
        printf("%lld",candy);
    } 
    else if      (n %2 == 0  && n >0 )  
    {
            //candy = n * (n/2) + (n/2);
            candy = ((n*n) /2 ) + (n/2);

            printf("%lld",candy);
    }      

    else if (n%2 == 1 && n >0   ) 
    {
       // candy = n * ceil(n/2.0); 
       candy = ((n*n) /2 ) + (n/2) +1;
        printf("%lld",candy);
    }     

    

    return 0;
}