#include<iostream>
using namespace std;

int number_of_swap=0;
int number_of_comparion=0;

void bubble_sort(int *array,int size)
{
    int is_swapped ;
    for (int i = 0; i < size-1 && is_swapped > 0 ; i++) 
    {
        is_swapped = 0;
        for (int j = 0; j < size-i-1; j++)
        {
            number_of_comparion++;
            if (array[j] > array[j+1])
            {
                number_of_swap++; 
                swap(array[j],array[j+1]);
                is_swapped ++;
            }
        }
    }   
     
    cout<<"Bubble Sort Function worked"<<endl;

}















void selection_sort(int *array ,int size)
{
    int min;

     for (int i = 0; i < size-1; i++)//iterating through the array
    {
        min = i;
        
        for (int j = i + 1; j < size; j++)
        {
            number_of_comparion++;
            if (array[j] < array[min])//finding the minimum element
            {
                min = j;
            }
        }
        
        if (i != min )
        {
            number_of_swap++;
            //cout << "Swap happend between " << array[i]<< "&" << array[min]<<endl;
            swap(array[i],array[min]);
        }
       
        
    }
    cout<<"Selection Sort Function worked"<<endl;
}



















void insertion_sort(int* array ,int size)
{
    int temp;
    int j;
    for ( int i = 1; i < size; i++)//loop to sort the array
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

    cout<<"Insertion Sort Function worked"<<endl;

}









void merge(int arr[], int p, int q, int r) {
  
  
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void merge_sort(int arr[], int l, int r) {
  if (l < r) {
    // dividing point
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);//recursive call

    // Merge subarrays
    merge(arr, l, m, r);
  }
    cout<<"Merge Sort Function worked"<<endl;

}

void quick_sort(int arr[], int low, int high) 
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
        
        quick_sort(arr, low, pi - 1); // Separately sorting elements beforepartition and after partition
        quick_sort(arr, pi + 1, high);
    }
    cout<<"Quick Sort Function worked"<<endl;
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 
  
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
   
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
   
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
   
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

void radix_sort(int arr[], int n)
{
   
    int m = getMax(arr, n);
 
    
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);

    cout<<"Radix Sort Function worked"<<endl;


        
}
 

void array_print(int *array,int size)
{
    cout<<"The sorted array is: ";//printing the sorted array
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    

}


int main ()
{
    //int array[] = {1,2,3,7,5,23,7,8,9,12}; // given array



    //! Using bubble sort 

    //int array[] = {32,51,27,85,66,23,13,57};
    //! Number of swap is 16 && Number of comparison is 36

    //int array[] = {5,7,9,12,17,22,36,53,67};
    //! Number of swap is 0 && Number of comparison is 36

    //int array[] = {9,8,7,6,5,4,3,2,1};
    //! Number of swap is 36 && Number of comparison is 36

    //int array[] = {7,7,7,7,7,7,7,7,7};
    //! Number of swap is 0 && Number of comparison is 36

    

    //! Using selection sort 

    //int array[] = {32,51,27,85,66,23,13,57};
    //! Number of swap is 6 && Number of comparison is 28

    //int array[] = {5,7,9,12,17,22,36,53,67};
    //! Number of swap is 0 && Number of comparison is 36

    //int array[] = {9,8,7,6,5,4,3,2,1};
    //! Number of swap is 4 && Number of comparison is 36

    //int array[] = {7,7,7,7,7,7,7,7,7};
    //! Number of swap is 0 && Number of comparison is 36



    //! Using insertion sort 

    //int array[] = {32,51,27,85,66,23,13,57};
    //! Number of swap is 6 && Number of comparison is 28

    //int array[] = {5,7,9,12,17,22,36,53,67};
    //! Number of swap is 0 && Number of comparison is 36

    //int array[] = {9,8,7,6,5,4,3,2,1};
    //! Number of swap is 4 && Number of comparison is 36

    //int array[] = {7,7,7,7,7,7,7,7,7};
    //! Number of swap is 0 && Number of comparison is 36

    

    int array[] = {2,4,1,5,7,3}; //god array
    int size = sizeof(array)/sizeof(array[0]); // size of array


    //bubble_sort(array,size);
    //selection_sort(array,size);
    insertion_sort(array ,size);
    //merge_sort(array, 0, size-1);
    //quick_sort(array, 0, size-1);
    //radix_sort(array,size);


    array_print(array,size);

    cout<<"\nThe size of the array is " <<size <<endl;
    cout <<"Number of swap is " << number_of_swap<<endl;
    cout <<"Number of comparison is " << number_of_comparion<<endl;

  
    
    return 0;
}
