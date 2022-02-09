// There are three types of expressions 1. Infix operator between operand

// 2. Prefix  here operand will be before operator
// 3 in post fix the operator will be at last

/*
()          = highest precedence
unary -     = next highest
^           = next highest
*,/,%       = next highest
+,-         =lowest
 */

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

string reverse_full_string(string coming_string);
string bracket_corrected_string(string coming_string);

void prefix_converter(string coming_string);
string postfix_converter(string coming_string);

int main()
{

    string infix_string = "x+y*z/w+u";

    prefix_converter(infix_string);
    return 0;
}
void prefix_converter(string coming_string)
{
    coming_string = reverse_full_string(coming_string);
    coming_string = bracket_corrected_string(coming_string);
    string postfixed_string = postfix_converter(coming_string);
    string prefixed_string = reverse_full_string(postfixed_string);
    cout << prefixed_string;
}

string postfix_converter(string coming_string)
{
    return "Hello";
}
string reverse_full_string(string coming_string)
{

    int i = 0;
    int size = coming_string.size();
    while (i < size / 2)
    {
        swap(coming_string[i], coming_string[size - i - 1]);
        i++;
    }
    return coming_string;
}

string bracket_corrected_string(string coming_string)
{
    int i = 0;
    while (i < coming_string.size())
    {
        if (coming_string[i] == '(')
        {
            coming_string[i] = ')';
            i++;
        }
        else if (coming_string[i] == ')')
        {
            coming_string[i] = '(';
            i++;
        }
        i++;
    }
    return coming_string;
}
