#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "graph.h"
#include "stack.h"

struct node {

    int item;
    node* next;
};

struct graph {

    int *depending;
    int *visited;
    node **vertex;
};

graph* create_empty_graph(int vertex_number) {

    graph *new_graph = (graph*)malloc(sizeof(graph));
    new_graph->depending = (int*)malloc(vertex_number * sizeof(int));
    new_graph->visited = (int*)malloc(vertex_number * sizeof(int));
    new_graph->vertex = (node**)malloc(vertex_number * sizeof(node*));

    int i;

    for (i = 0 ; i < vertex_number ; i++) {

        new_graph->depending[i] = 0;
        new_graph->visited[i] = 0;
        new_graph->vertex[i] = NULL;
    }

    return new_graph;
}

void add_vertex(graph *graph, int vertex1, int vertex2) {

    node *new_node = create_node(vertex2);
    graph->depending[vertex2]++;

    if (graph->vertex[vertex1] == NULL) {

        graph->vertex[vertex1] = new_node;
    }
    else {

        node *current = graph->vertex[vertex1];

        while (current->next != NULL) {

            current = current->next;
        }

        current->next = new_node;
    }
}

void bfs(graph *graph, stack *stack, int initial_vertex) {

    if (graph->visited[initial_vertex] == 0) {

        graph->visited[initial_vertex] = 1;
        node *current = graph->vertex[initial_vertex];

        while (current != NULL) {

            if (graph->visited[current->item] != 1) {

                bfs(graph, stack, current->item);
            }
            current = current->next;
        }

        push(stack, initial_vertex);
    }

}
