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
node* even_head;
node* odd_head;
node* merge_head;
int global_even_minimum;
int global_odd_minimum;

void INSERT_L(node** head_ref,int val)
{
    node* n = new node(val);

    if (*head_ref == NULL)
    {
        
        n->next = *head_ref;
        *head_ref = n;
    }
    else 
    {
        node* temp = *head_ref;

        while (temp->next != NULL)
        {
        temp = temp-> next;
        }
        temp-> next = n;
     

    }
}

void minimum_value (node** head_ref,int choice)
{
    node* temp = *head_ref;
    int minimum = temp->data;

    while ( temp != NULL)
    {
        if (temp->data < minimum)
        {
            minimum = temp->data;
        }
        temp= temp->next;
    }

    if (choice == 1)
    {
        cout << "Odd minimum is " << minimum<< endl;
        global_odd_minimum = minimum;

    }
    else if (choice == 2)
    {
        cout << "Even minimum is " << minimum<< endl;
        global_even_minimum = minimum;
    }
    
}

int even_odd_seperator()
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            INSERT_L(&even_head,temp->data);
        }
        else 
            INSERT_L(&odd_head,temp->data);
            
        temp = temp->next;
    }
}

void merge_minimum()
{
    if (global_even_minimum > global_odd_minimum)
    {
        INSERT_L(&merge_head,global_odd_minimum);
        INSERT_L(&merge_head,global_even_minimum);
    }
    else
    {
        INSERT_L(&merge_head,global_even_minimum);
        INSERT_L(&merge_head,global_odd_minimum);
    }
}

void PRINT(node* head_ref)
{
    node* temp = head_ref;

    while ( temp != NULL)
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }

}

int main()
{
    
    head = NULL;
    even_head = NULL;

    INSERT_L(&head,2);
    INSERT_L(&head,6);
    INSERT_L(&head,5);
    INSERT_L(&head,4);
    INSERT_L(&head,3);
    INSERT_L(&head,7);
    INSERT_L(&head,9);
    INSERT_L(&head,24);
    INSERT_L(&head,11);
    INSERT_L(&head,8);
    

    PRINT(head);
    cout << endl;

    even_odd_seperator();

    cout <<"Task 1\n"<< endl;
    PRINT(even_head);
    cout << endl;
    PRINT(odd_head);
    

    cout <<"\nTask 2\n"<< endl;
    minimum_value (&odd_head,1);
    minimum_value (&even_head,2);

    cout <<"\nTask 3\n"<< endl;
    merge_minimum();
    PRINT(merge_head);
    
    return 0;
}
