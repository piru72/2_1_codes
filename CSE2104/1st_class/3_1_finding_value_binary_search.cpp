// write a program that uses binary search to find the value of a number

// This code follow the conditions below
// 1. An array is given in asscending order 
// 2. User will input the key
// 3. Will follow binary search method
// 4. The output will show found and position or not found

#include<iostream>
using namespace std;

int main ()
{
    int array[] = {1,2,3,4,5,6,7,8};
    int key ;


    cout << " Enter a value to find"<< endl;
    cin >> key ; 

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

    return 0;

}


// We basically ignore half of the elements just after one comparison.

// 1. Compare x with the middle element.
// 2. If x matches with the middle element, we return the mid index.
// 3. Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
// 4. Else (x is smaller) recur for the left half.
