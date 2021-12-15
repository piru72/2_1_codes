//Write a code to implement Selection Sort

#include<iostream>

using namespace std;

int main ()
{
    int array[] = {1,2,3,11,5,23,7,8,9,12}; // given array
    int n = sizeof(array)/sizeof(array[0]); // size of array
    int  min, temp; 

    cout << "The unsorted array is: "; // printing the unsorted array
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout<<endl;

    for (int i = 0; i < 10; i++)//iterating through the array
    {
        min = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (array[j] < array[min])//finding the minimum element
            {
                min = j;
            }
        }
        //swapping the minimum element with the first element
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}