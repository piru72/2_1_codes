#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* prev;
    int d;
    Node* next;


};
Node* head;

void INSERT_F(int data)
{
    //write your code from below this line with proper indentation
    struct Node *new_node,*temp;

    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->prev=NULL;
    new_node->d=data;
    new_node->next=NULL;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->prev==head)
        {
            new_node->next=head;
            head=new_node;
        }
        temp=temp->next;
    }
}
void INSERT_N(int pos, int data)
{
    //write your code from below this line with proper indentation
    int i;
    struct Node * newNode, *temp,*temp1;

    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(pos!=i && temp!=NULL)
        {
            temp = temp->next;
            i++;
            temp1=temp;
        }

        if(pos == 1)
        {
            INSERT_F(data);
        }

        else if(pos == i && temp!=NULL)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->d = data;
            newNode->next = temp1->next;
            newNode->prev = temp->prev;

            temp1->next = newNode;
            temp->prev = newNode;

            printf("Data Inserted Successfully\n");
        }
        else
        {
            printf("Invalid position\n");
        }
    }



}
void INSERT_L(int data)
{
    //write your code from below this line with proper indentation

    struct Node * new_node,*temp;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->prev=NULL;
    new_node->d=data;


    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next==NULL)
        {
            break;
        }
        else
        {
            temp=temp->next;
            temp->next=new_node;
            new_node->prev=temp;
            new_node->next=NULL;
        }
    }

}

void DELETE_F()
{
    //write your code from below this line with proper indentation

    struct Node *ptr;

    ptr=head;

    head = head->next;

    if (head != NULL){
        head->prev = NULL;
    }
    free(ptr);


}
void DELETE_N(int n)
{
    //write your code from below this line with proper indentation
    int i;
    struct Node * newNode, *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(n!=i && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
    }
    if(n == i && temp!=NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
    }

}
void DELETE_L()
{
    //write your code from below this line with proper indentation
    struct Node *temp=head,*ptr;
    while(temp->next!=NULL)
     {
        temp=temp->next;

     }

    ptr=temp->prev;
    ptr->next=NULL;
    free(temp);
    temp=NULL;

}

int SEARCH(int data)
{
    //write your code from below this line with proper indentation

    struct Node *temp=head;
    int i=0;
    bool b;
    while(temp!=NULL)
    {
        i++;
        if(temp->d==data)
        {
            b=true;
            printf("\nkey = %d\n",temp->d);
            break;
        }
        else
        {
        //printf("i= %d\t",i);
        temp=temp->next;
        }
    }
    if(b==true)
    {
        //printf("i = %d\n",i);
        return i;

    }
    else
    {
        return -1;
    }


}
void PRINT_REV()
{
    //write your code from below this line with proper indentation

    struct Node *ptr, *temp;

    ptr=head;
    temp=ptr->next;
    ptr->next=NULL;
    ptr->prev=temp;

    while(temp!=NULL)
    {
        temp->prev=temp->next;
        temp->next=ptr;
        ptr=temp;
        temp=ptr->prev;
    }
     head=ptr;
}
void PRINT()
{
    //write your code from below this line with proper indentation
    struct Node *temp1=head;
    int i=1;
    while(temp1!=NULL)
    {
        printf("Node %d = %d\n",i,temp1->d);
        temp1=temp1->next;
        i++;
    }

}

void create_list()
{
    struct Node *temp,*new_node;
    int n,data;
    printf("Enter the number of nodes you want to create:\n");
    scanf("%d",&n);
    printf("Enter the data of Node 1: \n");
    scanf("%d",&data);

    head=(struct Node*)malloc(sizeof(struct Node));
    temp=head;

    temp->prev=head;
    temp->d=data;
    temp->next=NULL;



    for(int i=2; i<=n; i++)
    {
        printf("Enter the data of Node %d:\n",i);
        scanf("%d",&data);
        new_node=(struct Node*)malloc(sizeof(struct Node));

        new_node->prev=temp;
        new_node->d=data;
        new_node->next=NULL;

        temp->next=new_node;
        temp=temp->next;
    }

}
int main()
{
    head = NULL;
    int val,n,pos,j;

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
            //create_list();
            printf("\n Enter value: ");
            scanf("%d",&val);
            INSERT_F(val);
            break;
        case 2:
            //create_list();
            printf("\n Enter value, position: ");
            scanf("%d%d",&val,&pos);
            INSERT_N(pos,val);
            break;
        case 3:
            //create_list();
            printf("\n Enter value: ");
            scanf("%d",&val);
            INSERT_L(val);
            break;
        case 4:
            //create_list();
            DELETE_F();
            break;
        case 5:
            //create_list();
            printf("\n Enter position: ");
            scanf("%d",&n);
            DELETE_N(n);
            break;
        case 6:
            //create_list();
            DELETE_L();
            break;
        case 7:
            PRINT();
            break;
        case 8:
            //create_list();
            PRINT_REV();
            break;
        case 9:
            //create_list();
            printf("\n Enter value: ");
            scanf("%d",&val);
            j=SEARCH(val);
            printf("Value found at position: %d\n",j);
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