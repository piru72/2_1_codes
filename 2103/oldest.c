#include <stdio.h>

int main ()
{

    int num1,num2,num3;
    

    scanf("%d%d%d",&num1,&num2,&num3);

    if (num1 > num2 && num1 > num3)
    {
        printf("The 1st person is the oldest and the");
        
        if (num2 < num3)
        {
            printf("the 2nd person is the youngest one");
        }
        else
        {
            printf("the 3rd person is the youngest one");
        }
    }

     if (num2 > num1 && num2 > num3)
    {
        printf("The 2nd person is the oldest and the");
        
        if (num1 < num3)
        {
            printf("the 1st person is the youngest one");
        }
        else
        {
            printf("the 3rd person is the youngest one");
        }
    }

    if (num3 > num2 && num3 > num1)
    {
        printf("The 3rd person is the oldest and the");
        
        if (num2 < num1)
        {
            printf("the 2nd person is the youngest one");
        }
        else
        {
            printf("the 1st person is the youngest one");
        }
    }


    return 0;
}