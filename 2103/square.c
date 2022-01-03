#include <stdio.h>

int main ()
{
    int num1,num2;

    scanf("%d%d",&num1,&num2);

    if (num1 == num2)
    {
        printf("It is a square");
    }
    else
    {
        printf("It is not a square");
    }

    return 0;
}