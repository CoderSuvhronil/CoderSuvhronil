#include <stdio.h>
#include <stdlib.h>

#define max_size 20

static int graph[max_size][max_size];

void create_graph(int n)
{
    int u, v;
    char choice;

    do
    {
        system("cls");

        printf("Enter Edge(1 to %d):", n);
        scanf("%d%d", &u, &v);

        if(u<=0||v<=0||u>n||v>n)//IF INPUT IS OUTOF RANGE
            printf("Invalid Edge!\n");
        else if(graph[u-1][v-1]==1)//IF INPUT IS ALREADY GIVEN
            printf("ALREADY INPUT WAS GIVEN\n");
        else
        {
            graph[u-1][v-1]=1;
            graph[v-1][u-1]=1;
        }

        fflush(stdin);
        printf("DO YOU WANT TO CONTINUE:");
        choice=getchar();
    }
    while (choice=='Y'||choice=='y');
}

void BFS(int n)
{
    int que[n];
    int status[n];
    int front,rear,v;
    int i,j;
    
    front=rear=-1;
    
    for(i=0;i<n;i++)
        status[i]=0;
    if(front=rear=-1)//for first
    {
        front=rear=0;
        que[rear]=0;
        status[rear]=1;
    }
    while(front!=n)
    {
        v=que[front];
        for(j=0;j<n;j++)
        {
            if(graph[v][j]==1 && status[j]==0)
            {
                que[++rear]=j;
                status[j]=1;
            }
        }
        front++;
        printf("%d  ",v+1);
        status[v]=2;
    }
}

void DFS(int n, int vertex, int* visited) 
{
	int j;
    printf("%d  ", vertex + 1);
    visited[vertex] = 1;

    for (j = 0; j < n; j++) 
	{
        if (graph[vertex][j] && !visited[j]) 
		{
            DFS(n, j, visited);
        }
    }
}

void performDFS(int n) 
{
	int i;
    int visited[max_size];

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(n, i, visited);
        }
    }
}

int main()
{
    int size,i,j;

    printf("\n\t\t\t***************************************");
    printf("\n\t\t\t\t  GRAPH DATA STRUCTURE");
    printf("\n\t\t\t***************************************");

    printf("\nEnter Number of the Vertex:");
    scanf("%d", &size);

    create_graph(size);

    printf("\nDisplay:\n\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%2d",graph[i][j]);
        printf("\n\n");
    }

    printf("GRAPH IS:  ");
    BFS(size);
    
    printf("\nDisplay:\n\n");
    for (i = 0; i < size; i++) 
	{
        for (j = 0; j < size; j++)
            printf("%2d", graph[i][j]);
        printf("\n\n");
    }

    performDFS(size);
    return 0;
}







