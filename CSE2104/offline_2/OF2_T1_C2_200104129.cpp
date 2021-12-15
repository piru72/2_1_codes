//Write a code to implement Bubble Sort

#include<iostream>
using namespace std;
int main ()
{
    int array[] = {1,2,3,11,5,23,7,8,9,12}; // given array
    int n = sizeof(array)/sizeof(array[0]); // size of array
    int temp;

    cout<<"The unsorted array is: ";//printing the unsorted array
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    
    cout<<endl;
  
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n-1 ;j++)
            {
                if(array[i]<array[j])// swapping the variables
                {
                    temp=array[i];
                    array[i]=array[j];
                    array[j]=temp;    
                }   
            }
    }

    cout<<"The sorted array is: ";//printing the sorted array
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }

    return 0;
}