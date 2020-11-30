#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_linked_list(node_t* head) {
    node_t* temp = head->next;
    
    while(temp != NULL) {
        printf("%d - ", temp->val);
        temp = temp->next;
    }

    printf("NULL\n");
}

node_t* create_node(nv_type val) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

node_t* insert_node_after_node(node_t* node1, node_t* node2) {
    node2->prev = node1;
    node2->next = node1->next;
    if(node1->next != NULL) 
        node1->next->prev = node2;
    node1->next = node2;
    return node1;
}

node_t* insert_val_after_node(node_t* node, nv_type val) {
    node_t* node2 = create_node(val);
    insert_node_after_node(node, node2);
    return node;
}

node_t* push_front_node(node_t* head, node_t* node) {
    insert_node_after_node(head, node);
    return head;
}

node_t* push_back_node(node_t* head, node_t* node) {
    node_t* tmp;
    tmp = head;

    while(tmp->next != NULL) 
        tmp = tmp->next;

    insert_node_after_node(tmp, node);
    return head; 
}

node_t* push_back(node_t* head, nv_type val) {
    node_t* new_node = create_node(val);
    push_back_node(head, new_node);
    return head; 

}

node_t* push_front(node_t* head, nv_type val) {
    node_t* new_node = create_node(val);
    push_front_node(head, new_node);
    return head;
}

void free_linked_list(node_t* head) {
    node_t* node1 = head->next;
    node_t* node2;
    while(node1 != NULL) {
        node2 = node1;
        node1 = node1->next;
        free(node2);
    }
    free(head);
}

int find_value(node_t* node, int val) {
    node_t* tmp = node;
    int index = 0;
    while(tmp->next != NULL && tmp->val != val) {
        tmp = tmp->next;
        index++;
    }
    return (tmp->val == val ? index : -1);
}