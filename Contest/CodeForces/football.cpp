// Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.

#include<bits/stdc++.h>
#include<string>
using namespace std;

int main (){

    string s;
    string st1 = "1111111";
    string st2 = "0000000";
    int count = 0;
    cin >> s;
    if ((s.find(st1) != string::npos) || (s.find(st2) != string::npos)) cout << "YES" <<endl;
    else cout << "NO" << endl;
    return 0;
}
