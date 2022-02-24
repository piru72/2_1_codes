//Write a code to implement Stack (push, pop & isEmpty functions) using linked list

#include <iostream>
using namespace std;


// the node structure
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

void PUSH(int val)
{
    node* n = new node (val);
    n->next = head;
    head = n;
 
}

int  POP()
{
    int store = 0;
    node* to_delete= head;
    head = head->next;
    store = to_delete->data;
    delete to_delete;
    return store;
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
    // pushing items in the stack
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    PUSH(5);

    cout << "Before popping\n" << endl;
    PRINT();
    cout << "\nAfter popping\n" << endl;
    // popping item from the stack
    //POP();
    //POP();

    cout << POP()<<endl;
    cout << POP()<<endl;
    cout << POP()<<endl;
    cout << POP()<<endl;
    cout << POP()<<endl;
    //PRINT();
}

/*
As we know that stack follows LIFO (Last In First Out) we used that method to implement the stack.
Here we have used linked list to implement the stack.
In the driver code above we input 4,5 at the last and they were the ones who were deleted when we called the pop function . So in brief the element which was added last was  the one who got popped out first

*/