// write a program that will take an array input and find a value in the array using binary search

#include<iostream>

using namespace std;

int main ()
{
    int array[10];
    int temp;
    int i, j;
    int key = 0 ;
    for (i = 0; i < 10; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> array[i];
    }

    cout << " Enter a value to find"<< endl;
    cin >> key ; 


    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10 - i - 1; j++)
        {
            if (array[j] > array[j + 1])
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

    //mandatory variables for binary search

    int mid =0 ;
    int lower_bound =0;
    int upper_bound = sizeof(array)/sizeof(array[0]) -1;

    //optional variable to find out the position 
    int position = 0;
    bool is_value_found = false;

   // cout << "upper Bound is " <<upper_bound<< endl;
   // cout << "Lower Bound is " <<lower_bound<< endl;

    while (lower_bound <= upper_bound)
    {
        mid = (lower_bound+ upper_bound) / 2;
        if (array[mid] == key)
        {
            is_value_found = true;
            position = mid;
            break;
        }
        else if (array[mid] < key)
        {
            lower_bound = mid +1;
        }
        else if (array[mid] > key)
        {
            upper_bound = mid-1;
        }

    }

    if (is_value_found)
    {
        cout << " Value found at position "<< position << endl;
    }
    else 
    {
        cout << " Value not found " << endl;
    }

    cout << endl;
    return 0;
}

// this program will take a array input and later on sort it using bubble sort and then find a value in the array using binary search