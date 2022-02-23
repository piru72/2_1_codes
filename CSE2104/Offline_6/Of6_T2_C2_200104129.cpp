//Write a code to implement Queue (enqueue, dequeue & isEmpty functions) using linked list

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



void ENQUEUE(int val)
{
    node* n = new node (val);
    n->next = head;
    head = n;
}


void DEQUEUE()
{
     if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
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
    temp->next = NULL;
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
    node* temp = head;

    while ( temp != NULL)
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }

}

int main()
{
    ENQUEUE(1);
    ENQUEUE(2);
    ENQUEUE(3);
    ENQUEUE(4);
    ENQUEUE(5);

    cout << "Before Enqueue\n" << endl;
    PRINT();
    cout << "\nAfter Dequeue\n" << endl;
    DEQUEUE();
    DEQUEUE();
    PRINT();

 
}

/* We know that queue follows the  FIFO (First in First Out) we used that method to implement the queue
Here we have used linked list to implement the queue;

In the driver code above we enqueued 1,2 at the first and they were the ones who were dequeued when we called the pop function . So in brief the element which was added first was the one who got dequeued out first*/