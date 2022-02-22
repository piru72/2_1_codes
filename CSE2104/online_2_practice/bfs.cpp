#include <bits/stdc++.h>
using namespace std;

int graph[200][200];
int status[200];

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

void enqueue(int node)
{

}
int dequeue()
{

}

bool isEmpty()
{

}

void inputGraph(int N, int E)
{


}
void printAM(int N)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
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
    //step 1
    initStatus(n);

    //step 2
    enqueue(source);
    status[source] = 2;

    //step 3
    while(!isEmpty())
    {
        //step 4
        int N;  //do necessary things


        //step 5
        addNeighbors(N, n);

    }


}

int main()
{
    int n,e, source;
    printf("Enter no of Node: ");
    scanf("%d",&n);

    printf("Enter no of Edge: ");
    scanf("%d", &e);

    printf("Enter Source: ");
    scanf("%d", &source);
    //inputGraph(n,e);
    //printAM(n);
    //bfs(source,n);

    return 0;
}

