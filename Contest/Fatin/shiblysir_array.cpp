#include <iostream>
using namespace std;


void print_array(int *array,int lowest_index , int highest_index)
{
    if (lowest_index <= highest_index)
    {
        cout << array[lowest_index] << "\t" << array[highest_index] <<endl;
        print_array(array,lowest_index+1 , highest_index-1);

    }
    

}

int main ()
{
    int array []= {1,5,7,8,9};

     int size = sizeof(array) / sizeof(array[0]);

     //cout << size <<endl;

    int lowest_index = 0 ;
    int highest_index = size-1;

    print_array(array,lowest_index,highest_index);
}