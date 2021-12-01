// find a certain value in an array of integers and print found or not found also the position of the value

#include <iostream>
using namespace std;

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value;
    int position = 0;
    bool found = false;

    cout << "Enter a value to search for: ";
    cin >> value;

    for (int i = 0; i < 10; i++)
    {
        if (array[i] == value)
        {
            found = true;
            position = i;
        }
    }

    if (found)
    {
        cout << "Found " << value << " at index position " << position << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}

// this method is not efficient because it is searching the entire array every time
// this is a O(n) time complexity
// this is a O(1) space complexity
// this method is also known as linear search

// time complexity: O(n)
// space complexity: O(1)

// in this method we are using a for loop to iterate through the array and looking through every element to find the value as a result it is a time consuming method as it is iterating through the entire array so this method is not efficient as it will take a long time to find the value in the array