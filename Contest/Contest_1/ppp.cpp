

#include<iostream>

#include <string>

using namespace std;

int main()
{
    int n, i, j, vowels = 0;

    
    string str[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", str);
        for (j = 0; j < strlen(str); j++)
        {
            if (str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U')
            {
                vowels++;
            }
        }

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

       printf("Case #%d: %s\n",i+1,str);
        vowels = 0;
    }
    return 0;
}
