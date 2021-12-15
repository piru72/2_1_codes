//write a code that will sort an array using bubble sort

#include<iostream>
using namespace std;
int main ()
{
    int array[10] = {1,2,3,11,5,23,7,8,9,12}; // given array
    int temp;
    int i,j;
    bool swapped = true;
    int number_of_swaps = 0;
    int number_comparisons = 0;

    for(i=0;i<10;i++)
    {
      
            swapped=false;
            for(j=0;j<10 ;j++)
            {
                if(array[i]<array[j])
                {
                    temp=array[i];
                    array[i]=array[j];
                    array[j]=temp;
                    swapped=true;
                    number_of_swaps++;
                }
                number_comparisons++;
            }

            if(swapped==false)
            {
                break;
            }
        
    }
    cout<<"The sorted array is: ";
    for(i=0;i<10;i++)
    {
        cout<<array[i]<<" ";
    }

    // cout<<"\nvalue of swapped\n"<<swapped<<"\nNumber of swaps\n"<<number_of_swaps<<"\n number of comparison\t"<< number_comparisons<<endl;
    return 0;
}