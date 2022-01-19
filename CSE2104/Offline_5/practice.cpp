#include <iostream>
using namespace std;

struct Node
{
    Node* prev;
    int data;
    Node* next;

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};


void INSERT_F(Node** head_ref, int new_data) 
{ 
  
    Node* new_node = new Node(new_data);  
    new_node->next = (*head_ref); 
    

   
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node; 
} 

void INSERT_L(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node(new_data); 

    Node* last = *head_ref; /* used in step 5*/


    /* 4. If the Linked List is empty, then make the new 
        node as head */
    if (*head_ref == NULL)
    { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 

    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 

    /* 6. Change the next of last node */
    last->next = new_node; 

    /* 7. Make last node as previous of new node */
    new_node->prev = last; 

    return; 
} 


void INSERT_N(Node** head_ref,int new_data, int pos)
{
    

    int i;
    struct Node * newnode, *tmp;
    if(head_ref == NULL)
    {
        printf(" No data found in the list!\n");
    }
     else
     {
        tmp = *head_ref;
        i=1;
        while(i<pos-1 && tmp!=NULL)
        {
            tmp = tmp->next;
            i++;
        }
        if(pos == 1)
        {
            INSERT_F(head_ref,new_data);
        }
        else if(tmp == NULL)
        {
            INSERT_L(head_ref,new_data);
        }
        else if(tmp!=NULL)
         {

                Node* new_node = new Node(new_data); 
           
                new_node->next = tmp->next; 

                new_node->prev = tmp;              
            if(tmp->next != NULL)
            {
                tmp->next->prev = new_node; 
            }
            tmp->next = new_node; 
         }
        else
        {
            printf(" The position you entered, is invalid.\n");
        }
      }
} 

void DELETE_N(struct Node** head_ref, int n);







void DELETE_F(struct Node** head_ref) 
{
    Node* current = *head_ref;
    *head_ref = current->next;
    current->next->prev = current->prev;
    free(current);
    
}



void DELETE_N(struct Node** head_ref, int position)
{
   
   
    if (*head_ref == NULL || position <= 0)
        return;
 
    struct Node* current = *head_ref;
    int i;
 
    
    for (int i = 1; current != NULL && i < position; i++)
        current = current->next;
 
    
    if (current == NULL)
        return;
    
    if (*head_ref == NULL || current == NULL)
        return;

    if (*head_ref == current)
        *head_ref = current->next;
 
    
    if (current->next != NULL)
        current->next->prev = current->prev;
 
    
    if (current->prev != NULL)
        current->prev->next = current->next;
 
    free(current);
   
}

void DELETE_L(struct Node** head_ref)
{
    //Delete last node of the list
        Node* temp = *head_ref;
      if(temp != NULL) 
      {
        if(temp->next == NULL) {
          temp = NULL;
        }
         else {
          
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next;
          temp->next = NULL;
          free(lastNode); 
        }
      }


}

int SEARCH( Node* head_ref,int val)
{
    Node* temp = head_ref;
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

void PRINT(Node* node) 
{ 
    Node* last; 
    cout<<"\nTraversal in forward direction \n"; 
    while (node != NULL) 
    { 
        cout<<" "<<node->data<<" "; 
        last = node; 
        node = node->next; 
    } 
}

void PRINT_REV(Node* node)
{
    
    Node* last; 
    while (node != NULL) 
    {  
        last = node; 
        node = node->next; 
    } 
    cout<<"\nTraversal in reverse direction \n"; 
    while (last != NULL) 
    { 
        cout<<" "<<last->data<<" "; 
        last = last->prev; 
    } 

}



int main ()
{
    
    Node* head = NULL; 
    int value,position;

    while(true)
    {
        printf("1. Insert First\n2. Insert N\n3. Insert Last\n");
        printf("4. Delete First\n5. Delete N\n6. Delete Last\n");
        printf("7. Print\n8. Reverse Print\n9. Search\n");
        printf("10. Exit\n");
        printf("Enter Choice: ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\n Enter value: ");
            scanf("%d",&value);
            INSERT_F(&head,value);
            break;
        case 2:
            printf("\n Enter value, position: ");
            scanf("%d%d",&value,&position);
            INSERT_N(&head,value,position);
            break;
        case 3:
            printf("\n Enter value: ");
            scanf("%d",&value);
            INSERT_L(&head,value);
            break;
        case 4:
            DELETE_F(&head);
            break;
        case 5:
            printf("\n Enter position: ");
            scanf("%d",&position);
            DELETE_N(&head,position);
            break;
        case 6:
            DELETE_L(&head);
            break;
        case 7:
            PRINT(head);
            break;
        case 8:
            PRINT_REV(head);
            break;
        case 9:
            printf("\n Enter value: ");
            scanf("%d",&value);
            printf("Value found at position: %d",SEARCH(head,value));
            break;
        case 10:
            return 0;
            break;
        default:
            continue;
        }
    }

    return 0;
    return 0; 
}