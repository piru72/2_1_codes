//write a program that uses the merge sort algorithm to sort an array of integers

#include<iostream>
using namespace std;

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int temp[10];
    int i, j, k;
    int n = 10;
    int mid;

    for (i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    for (i = 0; i < n; i++)
    {
        temp[i] = array[i];
    }

    for (i = 1; i < n; i = i + i)
    {
        for (j = 0; j < n; j = j + i + i)
        {
            mid = j + i - 1;
            k = j;
            int l = 0;
            int m = mid + 1;

            while (k <= mid && m <= j + i)
            {
                if (temp[k] < temp[m])
                {
                    array[l] = temp[k];
                    k = k + 1;
                }
                else
                {
                    array[l] = temp[m];
                    m = m + 1;
                }
                l = l + 1;
            }

            while (k <= mid)
            {
                array[l] = temp[k];
                k = k + 1;
                l = l + 1;
            }

            while (m <= j + i)
            {
                array[l] = temp[m];
                m = m + 1;
                l = l + 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}