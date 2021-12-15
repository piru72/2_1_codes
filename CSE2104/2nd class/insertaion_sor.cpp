//write a code that will sort an array using insertion sort

#include <iostream>

using namespace std;

int main ()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int temp;
    int i,j;
    for (i = 1; i < 10; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
    for (i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}