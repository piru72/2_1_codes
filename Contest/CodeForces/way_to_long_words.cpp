#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    string word;
    int number_of_test_case;
    cin  >> number_of_test_case;


    while(number_of_test_case--)
    {
        cin >> word;

        if (word.length() > 10)
                cout<<word[0]<<word.length()-2<< word[word.length()-1]<<endl;
        else
                cout << word<<endl;  
    
    }

    return 0;

}