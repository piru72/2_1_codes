#include<iostream>
#include<math.h>
using namespace std;


int main ()
{
    int number_of_elements;

    double data_set[40]={ 2.2, 4.1, 3.5, 4.5, 3.2, 3.7, 3.0, 2.6,3.4, 1.6, 3.1, 3.3,3.8, 3.1, 4.7, 3.7,2.5, 4.3, 3.4, 3.6, 2.9, 3.3, 3.9, 3.1,3.3, 3.1, 3.7, 4.4, 3.2, 4.1, 1.9, 3.4,4.7, 3.8, 3.2, 2.6, 3.9, 3.0, 4.2, 3.5};
    int number_of_data = 40;
    

    // double data_set[50]={ 66, 62, 45,79, 32, 51, 56, 60, 51, 49, 25,42,54,54,58,70,43,58,52,50,38,67,50,59,48,65,71,30,46,55,82,51,63,45,53,40,35,56,70,52,67,55,57,30,63,42,74,58,44,55};
    // int number_of_data = 50;


    double data_number = number_of_data;
    double minimum_value=data_set[0];
    double maximum_value=data_set[0];

    int  min;
    double temp; 

    for (int i = 0; i < number_of_data; i++)
    {
        min = i;
        for (int j = i + 1; j < number_of_data; j++)
        {
            if (data_set[j] < data_set[min])
            {
                min = j;
            }
        }
        
        temp = data_set[i];
        data_set[i] = data_set[min];
        data_set[min] = temp;
    }

    cout << "The sorted array is: ";
    for (int i = 0; i < number_of_data; i++)
    {
        cout << data_set[i] << " ";
    }

    for (int i = 0 ; i <number_of_data ; i++)
    {
        if (minimum_value > data_set[i])
        {
            minimum_value = data_set[i];
        }

        if (maximum_value < data_set[i])
        {
            maximum_value= data_set[i];
        }

    }

    

    int number_of_groups_k = 1;
    int k_counter ;

    for ( k_counter = 1 ;  ; )
    {
        number_of_groups_k= pow(2,k_counter);
        if (number_of_groups_k > number_of_data)
        {
            break;
        }
        k_counter++;
    }

    number_of_groups_k = k_counter;


    double class_interval_i =(maximum_value-minimum_value)/number_of_groups_k;

    class_interval_i = (class_interval_i < 1) ? ceil(class_interval_i)/2 : ceil(class_interval_i);

    double class_interval_start ;
    double class_interval_end;

    class_interval_start = (minimum_value == (int)minimum_value) ? minimum_value : ceil(minimum_value) - class_interval_i;
    class_interval_end = (maximum_value == (int) maximum_value) ? maximum_value : ceil(maximum_value) ;


    cout <<"\n\nNumber of data N: "<< number_of_data<<endl;
    cout <<"Maximum value H: "<< maximum_value<<endl;
    cout <<"Minimum value L: "<< minimum_value<<endl;
    cout <<"Value of k\t"<< number_of_groups_k<<endl;
    cout <<"Value of I\t"<< class_interval_i<<endl;
    cout <<"Class Interval Start\t"<< class_interval_start<<endl;
    cout <<"Class Interval End  \t"<< class_interval_end<<endl;
    cout<< "\n\n\t\t\tFrequency Distribution Table"<<endl;

    int frequency;
    int cumulative_frequency=0;

    number_of_groups_k = (class_interval_start == (int)class_interval_start) ? number_of_groups_k : number_of_groups_k+1;


    for(int i = 0 ; i < number_of_groups_k ; i++ )
    {
        if (i == 0)
        {
            cout<< "Class Interval\t" << "Tally marks\t" <<"Frequency\t "<< "Cumulative Frequency\t" << "Relative Frequency\t"<<endl;

            cout<< class_interval_start<< "-";
            class_interval_start += class_interval_i;
            cout<< class_interval_start<< "\t\t";

            frequency=0;
            for (int i =0 ; i <data_number ; i ++)
            {
                if (data_set[i] >= class_interval_start - class_interval_i  && data_set[i] < class_interval_start )
                {
                    frequency++;
                    cout<<"/";   
                }

            }

            cumulative_frequency += frequency;
            cout<< "\t\t";
            cout<< frequency<< "\t\t  ";
            cout<< cumulative_frequency<< "\t\t\t";
            cout<< frequency/data_number<< "\t\t  ";
            cout<<"\n";

        }
        else
        {
            cout<< class_interval_start<< "-";
            class_interval_start += class_interval_i;
            cout<< class_interval_start<< "\t\t";

            frequency=0;
            for (int i =0 ; i <data_number ; i ++)
            {
                if (data_set[i] >=class_interval_start - class_interval_i  && data_set[i] < class_interval_start )
                {
                    frequency++;
                    cout<<"/";
        
                }

            }
            cumulative_frequency += frequency;
            cout<< "\t\t";
            cout<< frequency<< "\t\t  ";
            cout<< cumulative_frequency<< "\t\t\t";
            cout<< frequency/data_number<< "\t\t  ";
            cout<<"\n";
        }
    }   
}



   
    

