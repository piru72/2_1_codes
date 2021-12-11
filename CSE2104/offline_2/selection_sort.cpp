//write a code that will sort an array using selection sort

#include<iostream>

using namespace std;

int main ()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int i, j, min, temp; 
    for (i = 0; i < 10; i++)
    {
        min = i;
        for (j = i + 1; j < 10; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    cout << "Sorted array: ";
    for (i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}