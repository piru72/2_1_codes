#include<iostream>
using namespace std;

struct student
{
    int id;
    double sub1;
    double sub2;
    double avg;
}  student[5];


int main ()
{
    for (int i = 0 ; i < 5  ; i++) 
    {
      
        cin >> student[i].id;
        cin >> student[i].sub1;
        cin >> student[i].sub2;
        student[i].avg = (student[i].sub1+student[i].sub2) / 2;
    }

    for (int i = 0; i < 5  ; i++) 
    {
        
        for (int j = 0 ; j < 5-i  ; j++)
        {
            
            if (student[j].avg < student[j+1].avg )
            {
                swap(student[j].avg,student[j+1].avg); 
                swap(student[j].id,student[j+1].id);
                swap(student[j].sub1,student[j+1].sub1);
                swap(student[j].sub2,student[j+1].sub2);
                
            }
        }
    }



    cout << "Id\t Subject 1\tSubject 2\tAverage\t" << endl;

    for(int i = 0 ; i < 5 ; i++ )
    
    {
        cout << student[i].id << "\t"<<student[i].sub1 << "\t\t"<<student[i].sub2 << "\t\t" << student[i].avg<< "\t" << endl;   
    }

    return 0;
}

