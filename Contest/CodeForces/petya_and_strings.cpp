// A. Petya and Strings
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

// Input
// Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

// Output
// If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    string first_string;
    string second_string;

    cin >> first_string >> second_string;
    

    transform(first_string.begin(), first_string.end(), first_string.begin(), ::tolower);
    transform(second_string.begin(), second_string.end(), second_string.begin(), ::tolower);

    if (first_string != second_string)
    {
        if (first_string > second_string) cout << 1<<endl;
        else    cout << -1 << endl;
        
    }
    else cout<<0<<endl;

}