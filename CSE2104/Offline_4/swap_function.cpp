// write a code to swap two numbers using function
#include <iostream>
using namespace std;

template <typename T>
void value_swap(T &a,T &b)
{
   T temp;
   temp = a;
   a = b;
   b = temp;

}

// template <class T, class U>    // stackoverflow solution which works
// void value_swap (T& t, U& u)
// {
//     const T tmp = t;
//     t = static_cast<T>(u);
//     u = static_cast<U>(tmp);
// }

int main()
{
    int a=4,b=5;
    //double a=4,b=5;
    
    cout <<"Value before swapping " << a<<" "<< b << endl;
    value_swap(a,b);
    cout <<"Value after swapping " << a<<" "<< b << endl;

    return 0;
}