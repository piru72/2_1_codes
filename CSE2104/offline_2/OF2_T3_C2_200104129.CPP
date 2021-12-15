// Write a code to implement Insertion sort

#include <iostream>

using namespace std;

int main ()
{
    int array[] = {1,2,3,11,5,23,7,8,9,12}; // given array
    int n = sizeof(array)/sizeof(array[0]); // size of array
    int i,j,temp; // loop variables
    

    cout << "The unsorted array is: "; // printing the unsorted array
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout<<endl;

    
   
    for ( i = 1; i < n; i++)//loop to sort the array
    {
        temp = array[i];
        j = i - 1;
        while ( j >= 0 && array[j] > temp)//comparing the elements
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }

    cout << "The sorted array is: "; // printing the sorted array
    for ( i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
//