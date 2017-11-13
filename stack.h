typedef struct stack stack;

stack* create_empty_stack();

void push(stack *stack, int item);

void print_stack(stack *stack);

int empty_stack(stack *stack);
