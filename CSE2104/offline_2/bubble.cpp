//write a code that will sort an array using bubble sort

#include<iostream>

using namespace std;
int main ()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int temp;
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(array[i]<array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    cout<<"The sorted array is: ";
    for(i=0;i<10;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}