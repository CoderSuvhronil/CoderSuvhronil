#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the adjacency list structure
typedef struct AdjList {
    int dest;
    struct AdjList *next;
} AdjList;

// Define the graph structure
typedef struct Graph {
    int num_vertices;
    struct AdjList *array[MAX_VERTICES];
} Graph;

// Function to create a new adjacency list node
AdjList *new_adj_list_node(int dest) {
    AdjList *new_node = (AdjList *) malloc(sizeof(AdjList));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int src, int dest) {
    // Add an edge from the source vertex to the destination vertex
    AdjList *new_node = new_adj_list_node(dest);
    new_node->next = graph->array[src];
    graph->array[src] = new_node;

    // Since the graph is undirected, add an edge from the destination vertex to the source vertex
    new_node = new_adj_list_node(src);
    new_node->next = graph->array[dest];
    graph->array[dest] = new_node;
}

// Function to print the graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        AdjList *temp = graph->array[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to create a graph
Graph *create_graph(int num_vertices) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        graph->array[i] = NULL;
    }
    return graph;
}

int main() {
    // Create a graph with 5 vertices
    Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    return 0;
}
