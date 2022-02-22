#include <bits/stdc++.h>
using namespace std;

int graph[5][5];
int status[200];

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

void enqueue(int node)
{
}
int dequeue()
{
}

bool isEmpty()
{
}

void inputGraph(int number_of_node, int number_of_edge)
{
    int source, destination, weight;
    weight = 1; // weight =1 as we are considering unweighted graph

    cout << "Enter the edges and their weight" << endl;
    for (int i = 1; i <= number_of_edge; i++)
    {
        cin >> source >> destination; // no need to scan weight as it is unweighted graph
        graph[source][destination] = weight;
        // graph[destination][source] = weight; // if directed graph there will be no need to add this line because edges will traverse in both direction
    }
}
void printAM(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
}

void initStatus(int N)
{
}

void addNeighbors(int nodeN, int n)
{
}

void bfs(int source, int n)
{
    // step 1
    initStatus(n);

    // step 2
    enqueue(source);
    status[source] = 2;

    // step 3
    while (!isEmpty())
    {
        // step 4
        int N; // do necessary things

        // step 5
        addNeighbors(N, n);
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
    inputGraph(number_of_node, number_of_edge); // takes graph input
    printAM(number_of_node);                    // prints adjecency matrix
    // bfs(source,n);

    return 0;
}
