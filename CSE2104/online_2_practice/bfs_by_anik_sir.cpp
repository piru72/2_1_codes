#include<stdio.h>
#include<stdlib.h>

int graph[200][200];
int status[200];

struct Node
{
    int data;
    struct Node *next;
} *current=NULL,*prev=NULL;

bool isEmpty()
{
    bool emp = false;
    if(current==NULL && prev==NULL)
    {
        //printf("Empty Queue\n");
        emp = true;
    }

    return emp;
}

void enqueue(int val)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;

    if (prev==NULL)
    {
        current=prev=temp;;
        //prev=temp;
        //printf("Data Inserted into Queue\n");
       // printf("Enqueue val = %d\n",current ->data);
    }
    else
    {
        prev->next=temp;
        prev=temp;
    }


}
int dequeue()
{
    int store;
    struct Node *temp;
    if(current== NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp=current;
        current=current->next;
        store = temp ->data;
        if(current==NULL)
        {
            prev=NULL;
        }

        free(temp);
       // printf("Data got removed successfully.\n");
    }
    return store;


}


void inputGraph(int N, int E)
{
    int sr,des;///as the weight is 1 in unweighted graph
    for(int i=1; i<=E; i++)
    {
        scanf("%d %d",&sr,&des);
        graph[sr][des]=1;
    }

}
void printAM(int N)
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
}

void initStatus(int N)
{
    for(int i=1; i<=N; i++)
    {
        status[i]=1;
    }

}

void addNeighbors(int nodeN, int n)
{
    for(int i=1;i<=n;i++)   //traversing the row
    {
        if(graph[nodeN][i]==1 && status[i]==1)  // Condition 1: Checking neighbors -> graph[nodeN][i]
                                                // Condition 2: Checking status -> status[i]
        {
            enqueue(i);
            status[i] = 2;
        }
    }
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
        int N;
        N = dequeue();
        status[N] = 3;
        printf("N = %d\n",N);

        //step 5
        addNeighbors(N, n);//here I change the sequence

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
    inputGraph(n,e);///directed unweighted
    printAM(n);
    bfs(source,n);

    return 0;
}
/* INPUT taken for my graph
node = 6, edge = 7;             *************edge should be 6********
  1 2
  2 3
  2 4
  3 1
  3 6
  4 5
  5 6
 Dequeue value should be 1,2,3,4,6,5.
 */
