#include <stdio.h>
#include <stdlib.h>

#define max_size 20

static int graph[max_size][max_size];

void create_graph(int n) 
{
    int u, v;
    char choice;

    do {
        system("cls");
        printf("Enter Edge(1 to %d):", n);
        scanf("%d%d", &u, &v);

        if (u <= 0 || v <= 0 || u > n || v > n) // IF INPUT IS OUT OF RANGE
            printf("Invalid Edge!\n");
        else if (graph[u - 1][v - 1] == 1) // IF INPUT IS ALREADY GIVEN
            printf("ALREADY INPUT WAS GIVEN\n");
        else {
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        fflush(stdin);
        printf("DO YOU WANT TO CONTINUE:");
        choice = getchar();
    } while (choice == 'Y' || choice == 'y');
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
    int size, i, j;

    printf("\n\t\t\t***************************************");
    printf("\n\t\t\t\t  GRAPH DATA STRUCTURE");
    printf("\n\t\t\t***************************************");

    printf("\nEnter Number of Vertices: ");
    scanf("%d", &size);

    create_graph(size);

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

