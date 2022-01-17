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
        

    }
}

void INSERT_L_EVEN(int val)
{
    node* n = new node(val);

    if (even_head == NULL)
    {
        INSERT_F(val);
    }
    else 
    {
        node* temp = even_head;

        while (temp->next != NULL)
        {
        temp = temp-> next;
        }
        temp-> next = n;
        

    }
}

void INSERT_L_ODD(int val)
{
    node* n = new node(val);

        node* temp = odd_head;

        while (temp->next != NULL)
        {
        temp = temp-> next;
        }
        temp-> next = n;
        
}
 




int even_odd_seperator()
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            INSERT_L_EVEN(temp->data);
        }
        else 
            insert_odd_node(temp->data);
            
        temp = temp->next;
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

    
    
   
    

    return 0;
}
