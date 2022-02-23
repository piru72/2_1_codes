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
    if (head == NULL) // checking if the queue is empty or not
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

    if (isEmpty()) // if the queue is empty then the new node is the head
    {

        head = n;
    }
    else
    {

        node *temp = head;

        while (temp->next != NULL) // if not empty inserting in last node
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
    if (isEmpty())
    {
        return store;
    }
    else
    {
        store = newNode->val; // storing the value of the first node
        head = newNode->next;
        delete newNode;
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
    for (int i = 1; i <= n; i++)
    {
        if (graph[nodeN][i] == 1 && status[i] == 1) // finding edge which wasnt visited before and adding it to queue
        {
            enqueue(i);
            status[i] = 2; // setting the status to 2 as working on it
        }
    }
}

void bfs(int source_node, int number_of_node)
{
    int dequeued_value;
    initStatus(number_of_node); // initialising correct status 1 as all is unvisited currently
    head = NULL;

    enqueue(source_node); // enqueueing the source node

    status[source_node] = 2; // the source node we are working so status is 2

    // until the queue is empty
    while (!isEmpty())
    {
        dequeued_value = dequeue(); // getting the value of the dequeued node and printing it
        cout << dequeued_value << "->";
        status[dequeued_value] = 3; // setting the status of the dequeued node to 3 as visited and dequeued

        addNeighbors(dequeued_value, number_of_node); // adding neighbors of source node to the queue
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
    bfs(source_node, number_of_node);

    return 0;
}
