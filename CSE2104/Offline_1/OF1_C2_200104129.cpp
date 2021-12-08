//Write a code to search an element from a given sorted array using binary search
#include <iostream>
using namespace std;

 int main()
 {
        int key; // for storing the key to be searched
        int lowest_index,highest_index,mid_index; // for storing the low,high and mid values needed for binary search

        int array[100] = {1,2,3,4,5,6,7,8,9,10,11,12,13}; // the given array
        
        cout<<"Enter the key for finding: ";// taking the key to be searched from the user
        cin>>key;

        lowest_index=0; // setting the value of first and last index of the array
        highest_index=12;

        while(lowest_index<=highest_index) // doing binary search to find the key assuming that the key is here
        {
            mid_index=(lowest_index+highest_index)/2;//finding the mid value

            if(key==array[mid_index])
            {
                cout<<"The key is found at index "<<mid_index<<endl;
                break;
            }
            else if(key<array[mid_index])
            {
                highest_index=mid_index-1;
            }
            else
            {
                lowest_index=mid_index+1;
            }
        }

        //if the key is not found
        if(lowest_index>highest_index)
        {
            cout<<"The key is not found"<<endl;
        }
        return 0;
    }