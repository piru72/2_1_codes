#include <iostream>
using namespace std;

int main ()
{
    int k,n;
    int score[10000];
    int key=0 ;
   
  
    cin >> n>> k;

        for (int i = 1; i <= n ; i++) cin >> score[i];
    
        for (int i = 1; i <= n ; i++)
        {
            if (score[i]>= score[k] && score[i]>0 )
                key++;   
        }

        
        cout << key;

}