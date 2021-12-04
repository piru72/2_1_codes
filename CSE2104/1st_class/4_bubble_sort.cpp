// write a code that will sort an array of integers using bubble sort

#include<iostream>
using namespace std;

int main()
{
    int array[10];
    int temp;
    int i, j;

    for (i = 0; i < 10; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> array[i];
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10 - i - 1; j++)
        {
            if (array[j] == array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "The sorted array is: ";
    for (i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
// bubble sort is a simple sorting algorithm that repeatedly steps through the list to be sorted,
// this algorithm is not stable and may not preserve the order of equal elements. 
// The algorithm is named for the way smaller elements "bubble" to the top of the list.
// The algorithm is O(n^2)
// The algorithm is not suitable for sorting large arrays.
// The algorithm is not suitable for sorting arrays with duplicate elements,negative numbers,floating point numbers,strings,characters,booleans and null values.
