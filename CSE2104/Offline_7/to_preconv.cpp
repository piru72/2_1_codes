

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

#define MAX 100
int stack1[MAX];
string infix;
string postfix;
int top = -1;

void push(int);
int pop();
int isEmpty();
void toPostfix();
int isSpace(char);
void print();
int precedence(char);
void prefix_converter();


int main()
{

    infix = "1+2";
    prefix_converter();
    return 0;
}
void prefix_converter()
{
    reverse(infix.begin(), infix.end());
    toPostfix();
    print();
}

void toPostfix()
{
    int i, j = 0;
    char next;
    char symbol;
    for (i = 0; i < infix.size(); i++)
    {
        symbol = infix[i];

        if (!isSpace(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;

            case ')':
                while ((next = pop()) != '(')
                    ;
                postfix[j++] = next;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack1[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}
int isSpace(char c)
{
    if (c == ' ' || c == '\t')
    {
        return 1;
    }
    else
        return 0;
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void print()
{
    int i = 0;
    string temp;
    int size = 0;
    cout << "Equivalent Expression in postfix form : " + postfix << endl;
    while (postfix[i])
    {
        i++;
        size++;
    }

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        cout << postfix[i];
    }
}

void push(int val)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow \n";
        return;
    }
    top++;
    stack1[top] = val;
}
int pop()
{
    int val;
    if (top == -1)
    {
        cout << "Stack Underflow " << endl;
        exit(1);
    }
    val = stack1[top];
    top = top - 1;
    return val;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
