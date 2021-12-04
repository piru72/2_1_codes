#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, vowels = 0;
    char str[100];

    scanf("%s", str);

    for (j = 0; j < strlen(str); j++)
        {
            if (str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U')
            {
                vowels++;
            }
        }

    printf("%d\n", vowels);


    for (j = 0; j < strlen(str); j++)
        {   
            if ((str[j] + vowels) > 90  )
            {
                int temp = 64 + ((str[j] + vowels) -90);
                str[j] = temp;
            }
            else
            {
                 str[j] = str[j] + vowels;
            }
            
        }
        printf("CASE # %s",str);


         return 0;
}