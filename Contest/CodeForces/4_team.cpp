
#include <iostream>
using namespace std;

int main ()
{
    int test_cases;
    int surety_1;
    int surety_2;
    int surety_3;
    
    int number_of_problem_to_be_solved = 0;

    cin >> test_cases;

    while (test_cases--)
    {

        cin >> surety_1 >> surety_2 >> surety_3;

        if ( surety_1 + surety_2 + surety_3 >= 2)
        {
            number_of_problem_to_be_solved++;
        }
    }

    cout << number_of_problem_to_be_solved<<endl;
    
}

