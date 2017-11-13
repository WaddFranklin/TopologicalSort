#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

struct node {

    int item;
    node* next;
};

struct stack {

    int nodes_number;
    node *head;
};

stack* create_empty_stack() {

    stack *new_stack = (stack*)malloc(sizeof(stack));
    new_stack->nodes_number = 0;
    new_stack->head = NULL;

    return new_stack;
}

void push(stack *stack, int item) {

    node *new_node = create_node(item);

    new_node->next = stack->head;
    stack->head = new_node;
    stack->nodes_number++;
}

void print_stack(stack *stack) {

    node *current = stack->head;

    while (current != NULL) {

        printf("%d ", current->item);
        current = current->next;
    }
    putchar('\n');
}

int empty_stack(stack *stack) {

    return (stack->head == NULL);
}
