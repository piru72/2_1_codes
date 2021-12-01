// write a code that will print certain elements of an array

#include <iostream>
using namespace std;

int main() {
    int array[] = {1, 2, 3, 4, 5,6,7,8,9,10};
    int i;
    for (i = 0; i < 10; i++) {
        cout << " The " << i+1 << " st element is " << array[i] << "\n";
    }


    return 0;
}

// to print a variable value must be kept between << and >>

//one way to print the array is to use a for loop
//the other way is to use a while loop
//the other way is to use a do while loop
