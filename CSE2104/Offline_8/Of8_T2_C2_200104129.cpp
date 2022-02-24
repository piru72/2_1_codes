
//Task 1. Write a code to implement the DFS algorithm
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
    if (head == NULL) // checking if the stack is empty or not
    {
        return true;
    }
    else
    {
        return false;
    }
}
void push(int val)
{
    node *n = new node(val);

    if (isEmpty()) // if the stack is empty then the new node is the head
    {

        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

int pop()
{
    int store = 0;
    node *temp = head;
    if (isEmpty())
    {
        return store;
    }
    else
    {
        store = temp->val; // storing the value of the first node
        head = temp->next;
        delete temp;
        return store;
    }
}

void inputGraph(int number_of_node, int number_of_edge)
{
    int source, destination, weight;
    weight = 1; // value setted as 1 as we are considering unweighted graph

    cout << "Enter the edges " << endl;
    for (int i = 1; i <= number_of_edge; i++) // taking input from user
    {
        cin >> source >> destination;
        graph[source][destination] = weight;
    }
}
void printAM(int N)
{
    for (int i = 1; i <= N; i++) // printing the matrix
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
    for (int i = 1; i <= number_of_node; i++) // initialising the status by 1 to all the nodes
    {
        status[i] = 1;
    }
}

void addNeighbors(int nodeN, int n)
{
    for (int i = n; i >= 1; i--)
    {
        if (graph[nodeN][i] == 1 && status[i] == 1) // finding edge which wasn't visited before and adding it to stack
        {
            push(i);
            status[i] = 2; // setting the status to 2 as working on it
        }
    }
}

void dfs(int source_node, int number_of_node)
{
    int popped_value;
    initStatus(number_of_node); // initialising correct status 1 as all is unvisited currently
    head = NULL;

    push(source_node); // pushing the source node

    status[source_node] = 2; // the source node we are working so status is 2

    // until the stack is empty
    while (!isEmpty())
    {
        popped_value = pop(); // getting the value of the popped node and printing it
        cout << popped_value << "->";
        status[popped_value] = 3; // setting the status of the popped node to 3 as visited and popped

        addNeighbors(popped_value, number_of_node); // adding neighbors of source node to the stack
    }
}

int main()
{

    int number_of_node, number_of_edge, source_node;

    // taking necessary inputs
    cout << "Enter no of Node: " << endl;
    cin >> number_of_node;

    cout << "Enter no of Edge: " << endl;
    cin >> number_of_edge;

    cout << "Enter Source: " << endl;
    cin >> source_node;

    // taking input in the graph
    inputGraph(number_of_node, number_of_edge);
    // printing the adjecency matrix
    cout << "The Adjecency Matrix is: " << endl;
    printAM(number_of_node);
    // calling the bfs function
    dfs(source_node, number_of_node);

    return 0;
}
