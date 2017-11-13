#include <stdio.h>
#include "node.h"
#include "graph.h"
#include "stack.h"

struct graph {

    int *depending;
    int *visited;
    node **vertex;
};

int main () {

    int vertex_number = 11;
    int i;

    graph *G = create_empty_graph(vertex_number);
    stack *S = create_empty_stack();

    add_vertex(G, 3, 10);
    add_vertex(G, 10, 0);
    add_vertex(G, 10, 1);
    add_vertex(G, 0, 6);
    add_vertex(G, 6, 5);
    add_vertex(G, 6, 4);
    add_vertex(G, 1, 9);
    add_vertex(G, 2, 1);
    add_vertex(G, 2, 7);
    add_vertex(G, 7, 8);

    for (i = 0 ; i < vertex_number ; i++) {

        if (G->depending[i] == 0) {

            bfs(G, S, i);
        }
    }

    print_stack(S);

    return 0;
}
