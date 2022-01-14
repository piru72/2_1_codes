// A guy named Vasya attends the final grade of a high school. One day Vasya decided to watch a match of his favorite hockey team. And, as the boy loves hockey very much, even more than physics, he forgot to do the homework. Specifically, he forgot to complete his physics tasks. Next day the teacher got very angry at Vasya and decided to teach him a lesson. He gave the lazy student a seemingly easy task: You are given an idle body in space and the forces that affect it. The body can be considered as a material point with coordinates (0; 0; 0). Vasya had only to answer whether it is in equilibrium. "Piece of cake" — thought Vasya, we need only to check if the sum of all vectors is equal to 0. So, Vasya began to solve the problem. But later it turned out that there can be lots and lots of these forces, and Vasya can not cope without your help. Help him. Write a program that determines whether a body is idle or is moving by the given vectors of forces.

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    int value;
    int xi=0, yi=0,zi=0;

    cin >> n;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            cin >> value;
            if (j == 0 )        xi+= value;                    
            else if (j == 1 )   yi+= value;         
            else if (j == 2 )   zi+= value;    
        }
    }

    
    if (xi == 0 && yi == 0 & zi== 0)    cout << "YES"<< endl;
    else                    cout << "NO" << endl;
    
    return 0;
}