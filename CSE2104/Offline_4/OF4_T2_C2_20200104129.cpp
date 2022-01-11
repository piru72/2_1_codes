#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* prev;
    int val;
    node* next;

    node(int x)
    {
        prev = NULL;
        val = x;
        next = NULL;
    }
};
node* head;

void INSERT_F(int x)
{
    //write your code from below this line with proper indentation

}
void INSERT_N(int x, int n)
{
    //write your code from below this line with proper indentation

}
void INSERT_L(int x)
{
    //write your code from below this line with proper indentation

}

void DELETE_F()
{
    //write your code from below this line with proper indentation

}
void DELETE_N(int n)
{
    //write your code from below this line with proper indentation

}
void DELETE_L()
{
    //write your code from below this line with proper indentation

}
int SEARCH(int x)
{
    //write your code from below this line with proper indentation

}
void PRINT()
{
    //write your code from below this line with proper indentation

}
void PRINT_REV()
{
    //write your code from below this line with proper indentation

}
int main()
{
    head = NULL;
    int x,n;

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
            scanf("%d",&x);
            INSERT_F(x);
            break;
        case 2:
            printf("\n Enter value, position: ");
            scanf("%d%d",&x,&n);
            INSERT_N(x,n);
            break;
        case 3:
            printf("\n Enter value: ");
            scanf("%d",&x);
            INSERT_L(x);
            break;
        case 4:
            DELETE_F();
            break;
        case 5:
            printf("\n Enter position: ");
            scanf("%d",&n);
            DELETE_N(n);
            break;
        case 6:
            DELETE_L();
            break;
        case 7:
            PRINT();
            break;
        case 8:
            PRINT_REV();
            break;
        case 9:
            printf("\n Enter value: ");
            scanf("%d",&x);
            printf("Value found at position: %d",SEARCH(x));
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
