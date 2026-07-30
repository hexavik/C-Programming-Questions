/**
 * @file merge_sort_on_linked_list.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//
// A basic block of a Linked List
//
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//
// Management for LinkedList for easy insertion and deletion
//
typedef struct {
    Node* head;
    size_t size;
} LinkedList;

/**
 * @brief Initialize the empty list with default values
 *
 * @param list Input linked list created using LinkedList type
 */
void list_initialize(LinkedList* list) {
    if (!list) { return; }

    list->head = nullptr;
    list->size = 0;
}

/**
 * @brief Insert a node at the front of the list
 *
 * @param list Existing list which must not be null
 * @param value Input value for a node
 */
void list_insert_front(LinkedList* list, int value) {
    if (!list) { return; }

    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return; }
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size += 1;
}

/**
 * @brief Destroy all existing nodes inside the list,
 * must be called at the end of the program to avoid memory leak.
 *
 * @param list Existing linked list
 */
void list_destroy(LinkedList* list) {
    if (!list || !list->head) { return; }

    Node* current = list->head;
    while (current) {
        list->head = list->head->next;
        free(current);
        current = list->head;
    }
}

void list_display(Node* head) {
    printf("List: ");
    Node* current = head;
    while (current) {
        printf("%d → ", current->data);
        current = current->next;
    }
    printf("Null\n");
}

Node* merge(Node* l, Node* r) {
    if (!l) { return r; }
    if (!r) { return l; }

    if (l->data <= r->data) {
        l->next = merge(l->next, r);
        return l;
    } else {
        r->next = merge(l, r->next);
        return r;
    }

    return l;
}

Node* split(Node* head) {
    if (!head) { return nullptr; }

    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* temp = slow->next;
    slow->next = nullptr;

    return temp;
}

Node* list_merge_sort(Node* head) {
    if (!head || !head->next) { return head; }

    Node* mid = split(head);
    return merge(list_merge_sort(head), list_merge_sort(mid));
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_insert_front(&ls, 3);
    list_insert_front(&ls, 4);
    list_insert_front(&ls, 1);
    list_insert_front(&ls, 5);
    list_insert_front(&ls, 2);

    list_display(ls.head);

    ls.head = list_merge_sort(ls.head);
    list_display(ls.head);

    list_destroy(&ls);

    return 0;
}
