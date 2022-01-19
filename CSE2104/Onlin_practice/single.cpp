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
    
   
   

void DELETE_F(node** head_ref)
{
    
    node* to_delete= *head_ref; // deleting the first node and linking head to the next node
    *head_ref = to_delete->next;
    delete to_delete;
}


void DELETE_N(node** head_ref,int position)
{
    
    node* temp = *head_ref;
    int i =1;

    if (*head_ref == NULL) // in case of empty node
    {
        return;
    }
    else if (temp->next == NULL) // deleting the first node
    {
        *head_ref = NULL;
        delete *head_ref;
        return;
    }

    while( i +1 != position) // finding the n -1 th next
    {
        temp = temp->next;
        i++;
    }
    node* to_delete = temp->next; // address of the node we want to delete
    temp->next = temp->next->next; // linking with the next node

    delete to_delete;

}


void DELETE_L(node** head_ref)
{
   node* temp_1 = *head_ref;

    if ( temp_1 == NULL) //empty node
    {
        return;
    }
    else if (temp_1->next == NULL) // only one node
    {
        *head_ref = NULL;
        delete *head_ref;
        return;
    }

    node* temp = *head_ref;

    while(temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL; // finding the second last node setting the value Null

}

int SEARCH(node** head_ref,int val)
{
    node* temp = *head_ref;
    int i = 1;

    while(temp != NULL) // traversing till the end of the list
    {   
      
        if (temp->data == val) // if found returning the position
        {
            return i;
        }
        temp = temp->next;
          i++;
    }

    return -1;
    
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
// void swap(node *head_ref, int pos1, int pos2)
// {
//     node *node1, *node2, *prev1, *prev2, *temp;
//     int i;

   
//     int maxPos = (pos1 > pos2) ? pos1 : pos2;

//     int nodes = 0;

//     node* iterate = head_ref;
//     while (head_ref != NULL) 
//     {
//         nodes++;
//         head_ref = head_ref->next;
//     }
//     const int totalNodes = nodes;

//     // Validate swap positions
//     if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
//     {
        
//         return ;
//     }
    
//     // If both positions are same then no swapping required
//     if (pos1 == pos2)
//     {
        
//         return ;
//     }


//     // Identify both nodes to swap
//     i = 1;
//     temp  = head_ref;
//     prev1 = NULL;
//     prev2 = NULL;
    

//     // Find nodes to swap
//     while (temp != NULL && (i <= maxPos))
//     {
//         if (i == pos1 - 1)
//             prev1 = temp;
//         if (i == pos1)
//             node1 = temp;

//         if (i == pos2 - 1)
//             prev2 = temp;
//         if (i == pos2)
//             node2 = temp;

//         temp = temp->next;
//         i++;
//     }
    
//     // If both nodes to swap are found.
//     if (node1 != NULL && node2 != NULL)
//     {
        
//         // Link previous of node1 with node2
//         if (prev1 != NULL)
//             prev1->next = node2;

//         // Link previous of node2 with node1
//         if (prev2 != NULL)
//             prev2->next = node1;

        

//         // Swap node1 and node2 by swapping their 
//         // next node links

//         cout << node1 -> data << node2->data ;
//         // temp        = node1->next;
//         // node1->next = node2->next;
//         // node2->next = temp;

//         cout << "Hello world for third " << endl;

//         // // Make sure to swap head node when swapping
//         // // first element.
//         // if (prev1 == NULL)
//         //     head = node2;
//         // else if (prev2 == NULL)
//         //     head = node1;
//     }

//     return ;
// }


// void swap_node(int pos)
// {
//     int i=1;
//     struct node *currenNode,*prevNode,*nextNode;
//     currenNode=nextNode=head;
//     prevNode=NULL;

//     while(pos!=i)
//     {
//        nextNode=nextNode->next;
//        prevNode=currenNode;
//        currenNode=nextNode;
//        i++;
//     }
//     if(i==pos)
//     {
//         nextNode=nextNode->next;
//         prevNode->next=nextNode;
//         currenNode->next=nextNode->next;
//         nextNode->next=currenNode;
//     }

// }
int main()
{
    
    head = NULL;

   INSERT_F(&head,1);
   INSERT_F(&head,2);
   INSERT_F(&head,3);
   INSERT_L(&head,4);
   INSERT_N(&head,2,41);

//     PRINT(&head);
//    swap(head,1,2);

   PRINT(&head);
   cout << endl;
   DELETE_F(&head);
   DELETE_L(&head);
   DELETE_N(&head,2);

   //swap(head,1,2);

   //swap_node(1);

   PRINT(&head);
    return 0;
}
