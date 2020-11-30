#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define nv_type int

struct node {
    nv_type val;
    struct node* next;
    struct node* prev;
};

typedef struct node node_t;

void print_linked_list(node_t* head);

node_t* create_node(int val);

node_t* insert_node_after_node(node_t* node1, node_t* node2);
node_t* insert_val_after_node(node_t* node, nv_type val);

node_t* push_front_node(node_t* head, node_t* node); 
node_t* push_front(node_t* head, nv_type val);

node_t* push_back_node(node_t* head, node_t* node);
node_t* push_back(node_t* head, nv_type val);

void free_linked_list(node_t* head);

int find_value(node_t* node, int val);

#endif // LINKED_LIST_H
