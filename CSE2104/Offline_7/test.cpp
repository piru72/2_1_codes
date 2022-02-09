//! Task 1. Write a code to convert an Infix Expression to Postfix Expression. Evaluate both the expression to check.
// For example,
// Infix Expression: 1+2
// Infix Evaluation: 3
// Converted Postfix Expression: 12+
// Converted Postfix Evaluation: 3


#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 100
int stack1[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

void push(int);
int pop();
int isEmpty();
void toPostfix();
int space(char);
void print();
int precedence(char);
int postfix_eval();

int main (void)
{
    int result;
    cout << "Enter Expression in infix form : " << endl;
    gets(infix);

    toPostfix();


    print();
    cout <<"Result in postfix evaluation is : " << endl;
    result=postfix_eval();
    printf("%d",result);




    return 0;

}
void toPostfix()
{
    int i,j=0;
    char next;
    char symbol;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];


        if(!space(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;

            case ')':
                while((next=pop())!='(');
                postfix[j++]=next;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack1[top])>=precedence(symbol))
                {
                    postfix[j++]=pop();
                }
                push(symbol);
                break;

            default :
                postfix[j++]=symbol;
            }


        }
    }

    while(!isEmpty())
        postfix[j++]=pop();
    postfix[j]='\0';
}
int space (char c)
{
    if (c== ' ' || c=='\t')
    {
        return 1;
    }
    else
        return 0;
}
int precedence(char symbol)
{
    switch(symbol)
    {
    case '^' :
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default :
        return 0;
    }

}

void print()
{
    int i=0;
    cout << "Equivalent Expression in postfix form : " << endl;
    {
        while(postfix[i])
        {
            printf("%c",postfix[i++]);

        }
        printf("\n");
    }
}

void push(int val)
{
    if(top==MAX -  1)
    {
        printf("Stack Overflow \n");
        return;
    }
    top++;
    stack1[top]=val;
}
int pop()
{
    int val;
    if (top== -1)
    {
        cout << "Stack Underflow " << endl;
        exit(1);
    }
    val=stack1[top];
    top=top-1;
    return val;

}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int postfix_eval()
{
    int i;
    int a,b;
    for (i=0; i<strlen(postfix); i++)
    {


        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                push(b+a);
                break;
            case '-':
                push(b-a);
                break;
            case '*':
                push(b*a);
                break;
            case '/':
                push(b/a);
                break;
            case '^':
                push(pow (b,a));
                break;
            }
        }
    }
    return pop();
}

