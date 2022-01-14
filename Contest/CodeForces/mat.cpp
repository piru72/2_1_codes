#include <iostream>
using namespace std;

int main ()
{
   int matrix[5][5];
   int position_j_move=0;
   int position_i_move=0;

   for (int i = 0 ; i <3; i++)
   {
       for (int j = 0 ; j <3 ; j++)
       {
           cin >> matrix[i][j];
           if (matrix[i][j] == 1)
           {
               cout<<"Hello world"<<endl;
               if (j > 1)
               {
                   position_j_move = j-1;
                   cout <<"J index first worked"<<endl;

               }       
               else if (j <1) 
               {
                   cout <<"J index second worked"<<endl;
                   position_j_move = 1-j;
               }  
               else if (j == 1) 
               {
                   cout <<"J index third worked"<<endl;
                   position_j_move = 0;
               }

               if (i > 1) 
               {
                   position_i_move = i-1;
               }      
               else if (i < 1)   position_i_move = 1-i;
               else if (i == 1) position_i_move = 0;
               
           }
       }
   }

     for (int i = 0 ; i <3; i++)
   {
       for (int j = 0 ; j<3 ; j++)
       {
           cout << matrix[i][j]<<"\t";
          
       }
       cout<<endl;

   }
   cout << position_i_move + position_j_move <<endl;

  




}