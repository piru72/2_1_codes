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
int size=0;

void INSERT_F(int val)
{
    node* n = new node (val);
    n->next = head;
    head = n;
    size ++;
}


 
void INSERT_N(int pos, int val)
{
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else if (pos == 1)
    {
        INSERT_F(val);
    }
    else 
    {
        
        while (pos--)
        {
            if (pos== 0)
            {
                node* newnode = new node(val);
                node* temp = newnode;
                temp->next = head;
                head = temp;
            }
            else head = head -> next;
        }
        size++;
    }
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

    INSERT_F(1);
    INSERT_F(2);
    INSERT_F(3);
    
    INSERT_N(2,41);

    PRINT();

    return 0;
}
