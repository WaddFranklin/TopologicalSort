typedef struct graph graph;
typedef struct stack stack;

graph* create_empty_graph(int vertex_number);

void add_vertex(graph *graph, int vertex1, int vertex2);

void bfs(graph *graph, stack *stack, int initial_vertex);
