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
int size=0;

void INSERT_F(int val)
{
    node* n = new node (val);
    n->next = head;
    head = n;
    
}
node* merge_head;
void INSERT_MERGE(int val)
{
    node* n = new node (val);
    n->next = merge_head;
    merge_head = n; 
}

void insert_even_node (int val)
{
    node* n = new node (val);
    n->next = even_head;
    even_head = n;
}



void insert_odd_node (int val)
{
    node* n = new node (val);
    n->next = odd_head;
    odd_head = n;
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
        size ++;

    }
}
 




int global_even_minimum;
void even_minimum_value ()
{
    node* temp = even_head;
    int even_minumum = temp->data;
    

    while ( temp != NULL)
    {
        if (temp->data < even_minumum)
        {
            even_minumum = temp->data;
        }
        temp= temp->next;
    }

    cout << "Even minimum is " << even_minumum<< endl;
    global_even_minimum = even_minumum;
}

int global_odd_minimum;
void odd_minimum_value ()
{
    node* temp = odd_head;
    int odd_minumum = temp->data;

    while ( temp != NULL)
    {
        if (temp->data < odd_minumum)
        {
            odd_minumum = temp->data;
        }
        temp= temp->next;
    }

    cout << "Odd minimum is " << odd_minumum<< endl;
    global_odd_minimum = odd_minumum;
}

int even_odd_seperator()
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            insert_even_node(temp->data);
        }
        else 
            insert_odd_node(temp->data);
            
        temp = temp->next;
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

void PRINT_EVEN()
{
    node* temp = even_head;

    while ( temp != NULL)
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }
}

void PRINT_ODD()
{
    node* temp = odd_head;

    while ( temp != NULL)
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }
}

void PRINT_MERGE()
{
    node* temp = merge_head;

    while ( temp != NULL)
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }
}

void merge_minimum()
{
    if (global_even_minimum > global_odd_minimum)
    {
        INSERT_MERGE(global_even_minimum);
        INSERT_MERGE(global_odd_minimum);
    }
    else
    {
        INSERT_MERGE(global_odd_minimum);
        INSERT_MERGE(global_even_minimum);
    }
}



int main()
{
    
    head = NULL;
    even_head = NULL;

    INSERT_L(2);
    INSERT_L(6);
    INSERT_L(5);
    INSERT_L(4);
    INSERT_L(3);
    INSERT_L(7);
    INSERT_L(9);
    INSERT_L(24);
    INSERT_L(11);
    INSERT_L(8);
    

    //PRINT();
    cout << endl;

    even_odd_seperator();

    cout <<"Task 1"<< endl;
    PRINT_EVEN();
    cout << endl;
    PRINT_ODD();

    cout <<"Task 2"<< endl;
    even_minimum_value ();
    odd_minimum_value ();

    cout <<"Task 3"<< endl;
    merge_minimum();
    PRINT_MERGE();
    
   
    

    return 0;
}
