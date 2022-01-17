#include<iostream>
using namespace std;

int main ()
{
    int array [5] = {8,5,7,6,10};

    int max = array[0] ;

    int max_2 =array[0];
    for(int i = 0 ; i < 5 ; i ++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
       
    }

    for(int i = 0 ; i < 5 ; i ++)
    {
        if (max_2 < array[i] && array[i] < max)
        {
            max_2 = array[i];
        }
    }

    cout << max<< endl;
    cout << max_2 <<endl;
}