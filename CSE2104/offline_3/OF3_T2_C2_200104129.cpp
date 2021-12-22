//Write a code to implement quick sort

#include<iostream>
using namespace std;

void quickSort(int arr[], int low, int high) 
{
    if (low < high)
    {

        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
 
        for (int j = low; j <= high- 1; j++)
        {
            if (arr[j] <= pivot) // If current element is smaller than or equal to pivot
            {
                i++;    // increment index of smaller element
                swap(arr[i],arr[j]);
            }
        }
        int pi = (i + 1); //pi = partitioning index

        swap(arr[pi],arr[high]);
        
        quickSort(arr, low, pi - 1); // Separately sorting elements beforepartition and after partition
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {1,2,8,3,11,5,23,7,9,12};//given array
    int n = sizeof(arr)/sizeof(arr[0]);//finding the size of array

    cout<<"The unsorted array is: "<<endl;
    for (int i=0; i < n; i++)
    {
         cout << arr[i] << " ";
    }
    cout<<endl;

    quickSort(arr, 0, n-1);//calling the recursive function sending the  given array , lowest index ,highest index

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i < n; i++)
    {
         cout << arr[i] << " ";
    }

    return 0;
}
