//Write a code to implement merge sort.

#include <iostream>
using namespace std;

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
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // dividing point
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);//recursive call

    // Merge subarrays
    merge(arr, l, m, r);
  }
}

int main() {
  int arr[] = {1,2,8,3,11,5,23,7,9,12};
  int size = sizeof(arr) / sizeof(arr[0]);
  int lowest_index = 0;
  int highest_index = size -1;

    cout<<"The unsorted array is: "<<endl;
    for (int i=0; i < size; i++)
    {
         cout << arr[i] << " ";
    }
    cout<< endl;

  mergeSort(arr, lowest_index, highest_index);

  cout << "Sorted array: \n";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}