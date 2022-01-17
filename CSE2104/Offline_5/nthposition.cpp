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

void INSERT_N(int pos, int val)
{
    node* temp1 = new node(val);

    if (pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    node* temp2 = head;

    for (int i=0; i<pos-2; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
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

int main ()
{
    head = NULL;

    INSERT_N(1,2); // 2
    INSERT_N(2,3); // 2 3
    INSERT_N(1,4);
    INSERT_N(2,5);

    PRINT();
}