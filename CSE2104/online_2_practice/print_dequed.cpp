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

    if (head== NULL)
    {
        head = n;
    }
    else
    {
        node *newNode2 = head;
        while (newNode2->next != NULL)
        {
            newNode2 = newNode2->next;
        }
        newNode2->next = n;
    }
}

int DEQUEUE()
{
    int store = 0;
    node *newNode = head;
    if (head == NULL)
    {
        // printf("Empty Queue\n");
        return 0;
    }
    else
    {

        store = newNode->data;
        head = newNode->next;
        delete newNode;
        return store;
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
    // ENQUEUE(2);
    // ENQUEUE(3);
    // ENQUEUE(4);
    // ENQUEUE(5);

    cout << "Before Enqueue\n"
         << endl;
    PRINT();
    cout << "\nAfter Dequeue\n"
         << endl;
    int n;
    // cout << "\n" << n << endl;
    for (int i = 1; i <= 1; i++)
    {
        n = DEQUEUE();
        cout << n << "\t";
    }
    // DEQUEUE();
    // PRINT();
}
