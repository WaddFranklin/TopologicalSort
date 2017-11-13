#include <stdlib.h>
#include "node.h"

struct node {

    int item;
    node* next;
};

node* create_node(int item) {

    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;

    return new_node;
}
