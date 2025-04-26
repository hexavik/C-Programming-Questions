/**
 * @file memory_leak_detector.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    long address;
    bool is_free;
    struct Node * next;
} Node;

Node * init(int data) {
    Node * new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->address = (long )new_node;
    new_node->is_free = false;
    new_node->next = NULL;

    return new_node;
}

void add_node(Node * list, int data) {
    Node * new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->address = (long )new_node;
    new_node->is_free = false;
    new_node->next = NULL;

    while (list->next != NULL) {
        list = list->next;
    }
    list->next = new_node;
}

void free_single_node(Node ** list) {
    if (list == NULL || *list == NULL) {
        return;
    }

    Node * temp = *list;
    *list = (*list)->next;

    temp->is_free = true;

    free(temp);
}

void display_list(Node * list) {
    while (list) {
        printf("%d (%ld) -> ", list->data, list->address);
        list = list->next;
    }
    printf("NULL\n");
}

Node * allocate(size_t size) {
    Node * new_list = init(0);
    for (int i = 0; i < size - 1; ++i) {
        add_node(new_list, 0);
    }

    return new_list;
}

void memory_leak_report(Node * list) {
    int leaks = 0;
    while (list) {
        if (!list->is_free) {
            printf("Memory Leak Detected! Address: %ld, Data: %d\n", list->address, list->data);
            leaks++;
        }
        list = list->next;
    }
    if (leaks == 0) {
        printf("No memory leaks detected.\n");
    }
}

int main() {
    Node * lst = allocate(5);
    display_list(lst);
    free_single_node(&lst);
    free_single_node(&lst);
    free_single_node(&lst);
    free_single_node(&lst);
    //free_single_node(&lst);

    memory_leak_report(lst);

    display_list(lst);

    return 0;
}
