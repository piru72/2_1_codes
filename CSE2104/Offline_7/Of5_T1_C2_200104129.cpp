#include <iostream>
using namespace std;


// declaring the node
struct node
{
    int data;
    node* next;

    node(int val)
    {
        data  = val;
        next = NULL;
    }
};

node* head;
int size=0;

// creating a node and pointing its next as the new head which is basically NULL and letter saving the address of n in head
void INSERT_F(int val)
{
    node* n = new node (val);
    n->next = head;
    head = n;
    size ++;
}


void INSERT_L(int val)
{
    node* n = new node(val);

    if (head == NULL) // if the node is empty
    {
            n->next = head;
            head = n;
            size ++;
    }
    else 
    {
        node* temp = head;
        // finding the address of the last node which is saved in the second last node and adding the new node
        while (temp->next != NULL) 
        {
            temp = temp-> next;
        }
        temp-> next = n;
        size ++;

    }
}
 

void INSERT_N(int pos, int val)
{
    node* temp1 = new node(val);
    if (pos < 1 || pos > size + 1) // checking if the size is invalid 
        cout << "Invalid position!" << endl;

    else if (pos == 1) // adding in the first position
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    node* temp2 = head;

    // finding the address n-1 position holding 
    for (int i=0; i<pos-2; i++) 
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next; // setting the address n-1 position holding as new nodes next
    temp2->next = temp1; // linking the new nodes address
}
    
   
   

void DELETE_F()
{
    
    node* to_delete= head; // deleting the first node and linking head to the next node
    head = head->next;
    delete to_delete;
}


void DELETE_N(int position)
{
    
    node* temp = head;
    int i =1;

    if (head == NULL) // in case of empty node
    {
        return;
    }
    else if (head->next == NULL) // deleting the first node
    {
        node* to_delete= head;
        head = head->next;
        delete to_delete;
        return;
    }

    while( i +1 != position) // finding the n -1 th next
    {
        temp = temp->next;
        i++;
    }
    node* to_delete = temp->next; // address of the node we want to delete
    temp->next = temp->next->next; // linking with the next node

    delete to_delete;

}


void DELETE_L()
{
   

    if (head == NULL) //empty node
    {
        return;
    }
    else if (head->next == NULL) // only one node
    {
        delete head;
        return;
    }

    node* temp = head;

    while(temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL; // finding the second last node setting the value Null

}

int SEARCH(int val)
{
    node* temp = head;
    int i = 1;

    while(temp != NULL) // traversing till the end of the list
    {   
      
        if (temp->data == val) // if found returning the position
        {
            return i;
        }
        temp = temp->next;
          i++;
    }

    return -1;
    
}

void PRINT()
{
    node* temp = head;

    while ( temp != NULL) // print till last node
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }

}

int main()
{
    
    head = NULL;

   int x,n;

    while(true)
    {
      
      

        cout << "1. Insert First\n2. Insert N\n3. Insert Last\n4. Delete First\n5. Delete N\n6. Delete Last\n7. Print\n8. Search\n9. Exit\n"<<endl;

        cout << "Enter Choice: "<<endl;
        int ch;
        cin >> ch;
        

        switch(ch)
        {
        case 1:
    
            cout <<"\n Enter value: "<<endl;
            cin>>x;

            INSERT_F(x);
            break;
        case 2:
            
            
            cout <<"\n Enter value, position: "<<endl;
            cin>>x;
            cin>>n;

            INSERT_N(x,n);
            break;
        case 3:
             cout <<"\n Enter value: "<<endl;
             cin>>x;

            INSERT_L(x);
            break;
        case 4:
            DELETE_F();
            break;
        case 5:
            
            cout << "\nEnter a position: " <<endl;
            cin >> n;
            DELETE_N(n);
            break;
        case 6:
            DELETE_L();
            break;
        case 7:
            cout << " Linked list is \n"<< endl; 
            PRINT();
            cout << endl;
            break;
        case 8:
            cout <<"\n Enter value: "<<endl;
            cin>>x;
            cout << "\n Value found at position " << SEARCH(x) <<endl;
            break;

        case 9:
            return 0;
            break;
        default:
            continue;
        }
    }

    return 0;
}
