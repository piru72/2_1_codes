// take n numbers of string input and show them in reverse order

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cout << s << endl;
    }
    return 0;
}