// #include <bits/stdc++.h>
// using namespace std;

// struct node
// {
//     int val;
//     node* next;

//     node(int x)
//     {
//         val = x;
//         next = NULL;
//     }
// };
// node* head;

// void PUSH(int x)
// {
//      node* f=new node (x);
//      f->next=head;
//      head=f;

// }
// int p;



// void POP()
// {
//     if(head==NULL)
//     {
//         cout<<"List is empty"<<endl;
//     }
//     else
//     {
//         node* temp=head;
//         head=head->next;
//         free(temp);
//     }
// }


// void PRINT()
// {
//     int count=0;
//      node *temp=head;
//         while (temp!=NULL)
//         {
//             printf("%d\t",temp->val);
//             temp=temp->next;
//             p=count++;
//         }
//         cout<<endl;
// }
// int main()
// {
    
//     PUSH(1);
//     PUSH(2);
//     PUSH(3);
//     PUSH(4);
//     PUSH(5);
//     PRINT();
//     POP();
//     POP();
//     PRINT();
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* next;

    node(int x)
    {
        val = x;
        next = NULL;
    }
};
node* head;

void ENQUEUE(int x)
{
     node* f=new node (x);
     f->next=head;
     head=f;

}
int p;


void DEQUEUE()
{
    node* temp=head;
    node* temp1;
    while (temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    free(temp);
}


void PRINT()
{
    int count=0;
     node *temp=head;
        while (temp!=NULL)
        {
            printf("%d\t",temp->val);
            temp=temp->next;
            p=count++;
        }
        cout<<endl;
}
int main()
{
    ENQUEUE(1);
    ENQUEUE(2);
    ENQUEUE(3);
    ENQUEUE(4);
    ENQUEUE(5);

    
    PRINT();
    
    DEQUEUE();
    DEQUEUE();
    PRINT();
    
}