//Write a code to search an element from a given sorted array using binary search
#include <iostream>
using namespace std;


void binary_search(int *array,int size,int key)
{
    int lowest_index = 0 ,highest_index = size-1,mid_index;

     while(lowest_index<=highest_index)  
        {
            mid_index=(lowest_index+highest_index)/2;

            if(key==array[mid_index])
            {
                cout<<"The key is found at index "<<mid_index<<endl;
                break;
            }
            else if(key<array[mid_index])
            {
                highest_index=mid_index-1;
            }
            else
            {
                lowest_index=mid_index+1;
            }
        }

        if(lowest_index>highest_index)
        {
            cout<<"The key is not found"<<endl;
        }

}

 int main()
 {
        int key; 
       

         int array[] = {1,2,3,7,5,23,7,8,9,12}; 
         int size = sizeof(array)/sizeof(array[0]); 

         
        
        cout<<"Enter the key for finding: ";
        cin>>key;

        binary_search(array,size, key);

        

       
        return 0;
    }


    try {
            num = Double.parseDouble(jTextField1.getText());
        calculation = 3;
        jTextField1.setText("");
        jLabel1.setText(num + "*");
        }catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid Input");
        }