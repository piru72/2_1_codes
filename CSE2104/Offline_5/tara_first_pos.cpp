#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int d;
    Node* link;


};
Node* head;
void insert_F(int val);
void print_list();
int main()
{

    int val;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->link=NULL;
    head->d=3;

    printf("Enter the value you want to insert\n");
    scanf("%d",&val);
    insert_F(val);

    print_list();

}
void insert_F(int val)
{
    struct Node *temp=head,*newNode;
    if(temp==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->d=val;
        newNode->link=head;
        head=newNode;
    }
}
void print_list()
{
    //write your code from below this line with proper indentation
    struct Node *temp1=head;
    int i=1;
    while(temp1!=NULL)
    {
        printf("value of the %d Node= %d\n",i,temp1->d);
        temp1=temp1->link;
        i++;
    }

}