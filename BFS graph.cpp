#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the graph
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Create a node
Node* createNode(int v) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with 'V' vertices
Graph* createGraph(int vertices) 
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) 
	{
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all vertices as not visited
    }

    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) 
{
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS traversal
void BFS(Graph* graph, int startVertex) 
{
    Node* temp;
    int v;
    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) 
	{
        // Dequeue a vertex from the queue
        v = queue[front++];
        printf("Visited %d\n", v);

        // Get all adjacent vertices of the dequeued vertex v
        for (temp = graph->adjLists[v]; temp != NULL; temp = temp->next) 
		{
            if (!graph->visited[temp->vertex]) 
			{
                graph->visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
        }
    }
}

int main() 
{
    int i, V, E; // V -> number of vertices, E -> number of edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Graph* graph = createGraph(V);

    printf("Enter the edges (start to end):\n");
    for (i = 0; i < E; i++) 
	{
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth First Traversal starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}

