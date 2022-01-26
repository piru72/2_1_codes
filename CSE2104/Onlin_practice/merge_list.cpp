#include <iostream>
using namespace std;


// declaring the node
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
node* head_2;
node* split_head;
int size=0;

// creating a node and pointing its next as the new head which is basically NULL and letter saving the address of n in head
void INSERT_F(node** head_ref,int val)
{
    node* n = new node (val);
    n->next = *head_ref;
    *head_ref = n;
    size ++;
}


void INSERT_L(node** head_ref,int val)
{
    node* n = new node(val);

    if (*head_ref == NULL) // if the node is empty
    {
            n->next = *head_ref;
            *head_ref = n;
            size ++;
    }
    else 
    {
        node* temp = *head_ref;
        // finding the address of the last node which is saved in the second last node and adding the new node
        while (temp->next != NULL) 
        {
            temp = temp-> next;
        }
        temp-> next = n;
        size ++;

    }
}
 

void INSERT_N(node** head_ref,int pos, int val)
{
    node* temp1 = new node(val);
    if (pos < 1 || pos > size + 1) // checking if the size is invalid 
        cout << "Invalid position!" << endl;

    else if (pos == 1) // adding in the first position
    {
        temp1->next = *head_ref;
        *head_ref = temp1;
        return;
    }

    node* temp2 = *head_ref;

    // finding the address n-1 position holding 
    for (int i=0; i<pos-2; i++) 
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next; // setting the address n-1 position holding as new nodes next
    temp2->next = temp1; // linking the new nodes address
}

void MERGE(node** head_ref_1 ,node** head_ref_2)
{
    node* temp = *head_ref_1;
    while ( temp->next != NULL) 
    {   
        temp= temp->next;  
    }
    temp->next = *head_ref_2;
}
    


void PRINT(node** head_ref)
{
    node* temp = *head_ref;

    while ( temp != NULL) // print till last node
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }

}



int main()
{
    
    head = NULL;
    split_head = NULL;

   INSERT_F(&head,8);
   INSERT_F(&head,11);
   INSERT_F(&head,24);
   INSERT_F(&head,9);
   INSERT_F(&head_2,4);
   INSERT_F(&head_2,5);
   INSERT_F(&head_2,6);
   INSERT_F(&head_2,2);

   PRINT(&head);

   
   cout << "\nSecond Node \n" << endl;


   PRINT(&head_2);

   cout << "\nAfter merging \n" << endl;

   MERGE(&head,&head_2);
    

   PRINT(&head);

   



   
    return 0;
}
