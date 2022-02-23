
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int graph[100][100];
int status[100];

struct node
{
    int val;
    node *next;

    node(int x)
    {
        val = x;
        next = NULL;
    }
};
node *head;
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueue(int val)
{
    node *n = new node(val);

    if (isEmpty())
    {

        head = n;
    }
    else
    {

        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

int dequeue()
{
    int store = 0;
    node *newNode = head;
    if (head == NULL)
    {

        return store;
    }
    else
    {

        store = newNode->val;
        head = newNode->next;
        delete newNode;
        return store;
    }
}

void inputGraph(int number_of_node, int number_of_edge)
{
    int source, destination, weight;
    weight = 1;

    cout << "Enter the edges " << endl;
    for (int i = 1; i <= number_of_edge; i++)
    {
        cin >> source >> destination;
        graph[source][destination] = weight;
    }
}
void printAM(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
}

void initStatus(int number_of_node)
{
    for (int i = 1; i <= number_of_node; i++)
    {
        status[i] = 1;
    }
}

void addNeighbors(int nodeN, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (graph[nodeN][i] == 1 && status[i] == 1)
        {
            //cout << "value of I " << i << endl;
            enqueue(i);
            status[i] = 2;
        }
    }
}

void bfs(int source_node, int number_of_node)
{
    int dequeued_value;
    initStatus(number_of_node);
    head = NULL;

    enqueue(source_node);
    cout << "Status value of 5" << status[5]<<endl;

    status[source_node] = 2;

    while (!isEmpty())
    {
        dequeued_value = dequeue();
        cout << dequeued_value << ">";
        status[dequeued_value] = 3;

        addNeighbors(dequeued_value, number_of_node);
    }
}

int main()
{

    int number_of_node, number_of_edge, source_node;

    cout << "Enter no of Node: " << endl;
    cin >> number_of_node;

    cout << "Enter no of Edge: " << endl;
    cin >> number_of_edge;

    cout << "Enter Source: " << endl;
    cin >> source_node;

    inputGraph(number_of_node, number_of_edge);
    printAM(number_of_node);
    bfs(source_node, number_of_node);

    return 0;
}
