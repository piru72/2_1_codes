#include <bits/stdc++.h>
using namespace std;

int graph[5][5];
int status[5];

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

void enqueue(int x)
{

    node *n = new node(x);

    if (head == NULL)
    {
        head = n;
        cout << "Step 2 done" << endl;
    }
    else
    {
        cout << "Step 3 done" << endl;
        node *newNode2 = head;
        while (newNode2->next != NULL)
        {
            newNode2 = newNode2->next;
        }
        newNode2->next = n;
    }
    return;
}

int dequeue()
{
    int store = 0;
    node *newNode = head;
    if (head == NULL)
    {
        // printf("Empty Queue\n");
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

bool isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
}

void bfs(int source_node, int number_of_node)
{

    // cout << "BFS function"<< source<<n << endl;
    // step 1
    initStatus(number_of_node);
    cout << "Step 1 done" << endl;

    // step 2
    enqueue(source_node);

    status[source_node] = 2;

    int N;
    N = dequeue();
    cout << N << ">";
    status[N] = 3;

    // // step 3
    // while (!isEmpty())
    // {
    //     // step 4
    //     int N; // do necessary things
    //     N = dequeue();
    //     cout << N << ">";
    //     status[N] = 3;

    //     // step 5
    //     addNeighbors(N, number_of_node);
    // }
}

int main()
{
    head = NULL;
    int number_of_node, number_of_edge, source_node;

    cout << "Enter no of Node: " << endl;
    cin >> number_of_node;

    cout << "Enter no of Edge: " << endl;
    cin >> number_of_edge;

    cout << "Enter Source: " << endl;
    cin >> source_node;
    inputGraph(number_of_node, number_of_edge); // takes graph input
    // printAM(number_of_node);                    // prints adjecency matrix
    bfs(source_node, number_of_node);

    return 0;
}

/*
1 4
1 5
4 2
5 2
2 3

*/

// status update
//  1 - unvisited
//  2 - visiting
//  3 - visited and in queue