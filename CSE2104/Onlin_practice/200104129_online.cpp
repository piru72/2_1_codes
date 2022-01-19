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
    


void PRINT(node** head_ref)
{
    node* temp = *head_ref;

    while ( temp != NULL) // print till last node
    {
        cout << temp ->data << "->";
        temp= temp->next;
    }

}
 void SPLIT(node** head_ref)
 {
     node* temp = *head_ref;
     node* temp_2 = *head_ref;
     int odd_pos = 1;
     int even_pos = 2;

     while (temp != NULL)
     {
         if (temp->data % 2 != 0)
         {
             INSERT_L(&split_head,temp->data);  
         }
        temp= temp->next;
     }  
 }


void EVEN_ADDER(node** head_ref_1 , node** head_ref_2)
{
    node* temp = *head_ref_1;
    node* temp_2 = *head_ref_2;
    int i = 2;

    while (temp!= NULL)
    {
        if (temp->data%2 == 0)
        {
            INSERT_N(&temp_2,i,temp->data);
            i+= 2;
        }
        
        temp= temp->next;
    }
}


void NODE_SWAP(node** node_ref)
{
   

    node* first_node = *node_ref;
    node* second_node = first_node->next;
    node* third_node = first_node->next->next;

    node* temp = first_node;
    first_node = second_node;
    second_node = temp;

    first_node ->next = third_node;
    
    
}
int main()
{
    
    head = NULL;
    split_head = NULL;

   INSERT_F(&head,8);
   INSERT_F(&head,11);
   INSERT_F(&head,24);
   INSERT_F(&head,9);
   INSERT_F(&head,7);
   INSERT_F(&head,3);
   INSERT_F(&head,4);
   INSERT_F(&head,5);
   INSERT_F(&head,6);
   INSERT_F(&head,2);

   PRINT(&head);

   SPLIT(&head);
   EVEN_ADDER(&head , &split_head);
    cout << "\nTask 1" << endl;
   PRINT(&split_head);

    cout << "\nTask 2" << endl;

    NODE_SWAP(&head);
    PRINT(&head);


   
    return 0;
}
