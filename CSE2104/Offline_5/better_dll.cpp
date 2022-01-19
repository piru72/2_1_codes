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

int list_size = 0;
void INSERT_F(Node** head_ref, int new_data) 
{ 
  
    Node* new_node = new Node(new_data); // creating a node  
    new_node->next = *head_ref; // linking the old node

    if (*head_ref != NULL) 
        (*head_ref)->prev = new_node;

    *head_ref = new_node; // creating the new head 
    list_size++;
    
    return;
} 

void INSERT_L(Node** head_ref, int new_data) 
{ 
   
    Node* new_node = new Node(new_data); 
    Node* last = *head_ref; 

    if (*head_ref == NULL) // if the list is empty
    { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 

    while (last->next != NULL)
    {
        last = last->next; 
    }
        
    last->next = new_node; //linking the new node in the founded last nodes address
    new_node->prev = last; 
    list_size++;

    return; 
} 


void INSERT_N(Node** head_ref,int new_data, int pos)
{
    

    int i;
    struct Node * newnode, *temp;
    if(*head_ref == NULL) // adding data in empty list is not allowed
    {
        cout <<" Can not enter data in empty list . Insert one data first using other options!\n" <<endl;
    }
     else
     {
        temp = *head_ref;
        i=1;
        while(i<pos-1 && temp!=NULL) // finding the position not crossing last node
        {
            temp = temp->next;
            i++;
        }
        if (pos  > list_size+1){
            cout << " The position you entered, is invalid.\n"<< endl;
            }
        else if(pos == 1){
            INSERT_F(head_ref,new_data); // inserting in first position
        }
        else if(temp == NULL){
            INSERT_L(head_ref,new_data); // inserting in first position
        }
        else if(temp!=NULL)
         {

                Node* new_node = new Node(new_data); // node creation
           
                new_node->next = temp->next; // linking pos node with pos+1 node
                new_node->prev = temp; // linking pos node with pos-1 node

            if(temp->next != NULL)
            {
                temp->next->prev = new_node;  // linking with pos+1 node
            }
            temp->next = new_node; // linking with pos node
            list_size++;
         }
        
      }
} 

void DELETE_F( Node** head_ref) 
{
    Node* to_delete = *head_ref;

    *head_ref = to_delete->next; // pointing to next node

    to_delete->next->prev = to_delete->prev; // to_delete -> prev value will always be NULL
    
    delete to_delete;
    list_size--;
    
}

void DELETE_N( Node** head_ref, int position)
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

void DELETE_L( Node** head_ref)
{
    Node* temp = *head_ref;
    if (temp == NULL)
    {
        return;
    }
    else
      {
        if(temp->next == NULL) { // if only one node
          *head_ref = NULL;
          delete *head_ref;
          list_size --;
        }
         else {
          
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next; // temp-> next hold address of last node
          temp->next = NULL;
          delete lastNode;
        }
      }


}

int SEARCH( Node* head_ref,int val)
{
    Node* temp = head_ref;
    int i = 1;

    while(temp != NULL)  // going till end
    {   
      
        if (temp->data == val) 
        {
            return i;
        }
        temp = temp->next;
          i++;
    }

    return -1; // returning -1 if not found
    
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
    
    Node* last = NULL; 
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
        cout << "\n1. Insert First\n2. Insert N\n3. Insert Last\n";
        cout << "4. Delete First\n5. Delete N\n6. Delete Last\n";
        cout << "7. Print\n8. Reverse Print\n9. Search\n";
        cout << "10. Exit\n";
        cout << "Enter Choice: "<< endl;
        int ch;
       
        cin >> ch;

        switch(ch)
        {
        case 1:
            cout << "\n Enter value: "<< endl;
           
            cin >> value;
            INSERT_F(&head,value);
            break;
        case 2:
            cout << "\n Enter value, position: "<< endl;
            
            cin >> value >> position;
            INSERT_N(&head,value,position);
            break;
        case 3:
            cout << "\n Enter value: "<<endl;
            cin >> value;
            INSERT_L(&head,value);
            break;
        case 4:
            DELETE_F(&head);
            break;
        case 5:
            cout << "\n Enter position: "<<endl;
            cin >> position;
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
            cout << "\n Enter value: "<<endl;
            cin >> value;
            cout << "Value found at position: "<< SEARCH(head,value)<<endl;
            break;
        case 10:
            return 0;
            break;
        default:
            continue;
        }
    }

   
    return 0; 
}