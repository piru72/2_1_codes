#include <iostream>
using namespace std;

struct node

{
    int data;
    node* next;

    node (int val)
    {
        data = val ;
        next = NULL;
    }
};

node* head;

void add(int data)
{
    node* n = new node (data);
    n->next = head; // NULL for first node 
    head = n;
}

int main ()
{
    head = NULL;

    add(1);
    add(2);
    add(3);

    node* temp = head;
  
    while (temp != NULL )
    {
          cout << temp->data <<"\t";
          temp = temp->next;
    }

    //cout <<"Heellooo";
}