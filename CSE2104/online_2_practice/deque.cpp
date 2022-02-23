// Write a code to implement Queue (enqueue, dequeue & isEmpty functions) using linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *head;

void ENQUEUE(int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void DEQUEUE()
{
    node *newNode = head;
    if (head == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {

        // data=newNode->val;
        head = newNode->next;
        delete newNode;
        // return data;
    }
}

void IS_EMPTY()
{
    if (head == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}

void PRINT()
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    ENQUEUE(1);
    ENQUEUE(2);
    ENQUEUE(3);
    ENQUEUE(4);
    ENQUEUE(5);

    cout << "Before Enqueue\n"
         << endl;
    PRINT();
    cout << "\nAfter Dequeue\n"
         << endl;
    DEQUEUE();
    DEQUEUE();
    DEQUEUE();
    DEQUEUE();
    DEQUEUE();
    PRINT();
}
