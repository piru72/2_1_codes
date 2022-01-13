#include<iostream>
using namespace std;


template <typename T>
void value_swap(T &a,T &b)
{
   T temp = a;
   a = b;
   b = temp;

}

struct student_information
{
    int id;
    double sub_1_mark;
    double sub_2_mark;
    double average_mark;
}  student[5];

int number_of_students = 5; //taking input for 5 students


void information_input()
{
    
    for (int i = 0 ; i <number_of_students ; i++) // taking the user input
    {
        cout << "Id"<<endl;
        cin >> student[i].id;
        cout << "Subject 1 Mark"<<endl;
        cin >> student[i].sub_1_mark;
        cout << "Subject 2 mark"<<endl;
        cin >> student[i].sub_2_mark;
        student[i].average_mark = (student[i].sub_1_mark+student[i].sub_2_mark) / 2;
        
    }

}

void information_output()
{
    cout << "Id\t" << "Subject 1\t" << "Subject 2\t" << "Average\t" << endl;

    for(int i = 0 ; i < number_of_students ; i++ )
    
    {
        cout << student[i].id << "\t"<<student[i].sub_1_mark << "\t\t"<<student[i].sub_2_mark << "\t\t" << student[i].average_mark<< "\t" << endl;  //generating the table for showing 
    }
}

void sorting()
{
 
    for (int i = 0; i <number_of_students  ; i++) // using bubble sort to sort the structures in descending way based on average mark
    {
        
        for (int j = 0 ; j < number_of_students-i  ; j++)
        {
            
            if (student[j].average_mark < student[j+1].average_mark )
            {
                value_swap(student[j].average_mark,student[j+1].average_mark); //swapping the values bu calling value_swap function
                value_swap(student[j].id,student[j+1].id);
                value_swap(student[j].sub_1_mark,student[j+1].sub_1_mark);
                value_swap(student[j].sub_2_mark,student[j+1].sub_2_mark);
                
            }
        }
    }

}


int main ()
{
    information_input(); // taking input from the user
    sorting(); // sorting the structure according to the average mark
    information_output(); // showing the sorted marks table

    return 0;
}

