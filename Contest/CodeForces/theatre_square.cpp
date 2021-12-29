#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long  n;
    unsigned long long  m;
    unsigned long long  a;
    unsigned long long  flagstons_needed ;
   
    cin >> n >> m >> a;

    flagstons_needed = ceil ((double) m/a) * ceil ((double)n/a);

    cout << flagstons_needed<< endl;

}
