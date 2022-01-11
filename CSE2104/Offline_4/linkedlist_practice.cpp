#include <iostream>
using namespace std;

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

void INSERT_F(int val)
{
    node* n = new node (val);
    n->next = head;
    head = n;

}

void INSERT_L(int val)
{
    
    node* n = new node(val);

    if (head == NULL)
    {
        INSERT_F(val);
    }
    else 
    {
        node* temp = head;

        while (temp->next != NULL)
        {
        temp = temp-> next;
        }
        temp-> next = n;

    }
}
int SEARCH(int val)
{
    
    node* temp = head;
    int i = 1;

    while(temp != NULL)
    {   
      
        if (temp->data == val)
        {
            return i;
        }
        temp = temp->next;
          i++;
    }

    return -1;
}
void DELETE_F()
{
    //write your code from below this line with proper indentation
    node* to_delete= head;
    head = head->next;
    delete to_delete;

}

void DELETE_N(int position)
{
    //write your code from below this line with proper indentation

    node* temp = head;
    int i =1;

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        DELETE_F();
        return;
    }

    while( i +1 != position)
    {
        temp = temp->next;
        i++;
    }
    node* to_delete = temp->next;
    temp->next = temp->next->next;

    delete to_delete;

}



void PRINT()
{
    node* temp = head;

    while ( temp != NULL)
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }
    
}

int main()
{
    head = NULL;

    INSERT_L(1);
    INSERT_L(2);
    INSERT_L(3);
    INSERT_F(4);
    INSERT_F(5);


    PRINT();
    int position = SEARCH(2);

    cout<< "The position is 1 is found at " << position << endl; 
    //DELETE_N(3);
    //DELETE_F();
    PRINT();

    return 0;
}
