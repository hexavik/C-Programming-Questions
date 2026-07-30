/**
 * @file add_numbers_represented_by_lists.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-12
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
void list_init(LinkedList* list) {
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

    list->head = nullptr;
    list->size = 0;
}

void list_display(LinkedList* list) {
    if (!list) { return; }

    Node* current = list->head;
    printf("List: ");
    while (current) {
        printf("%d → ", current->data);
        current = current->next;
    }
    printf("Null\n");
}

void list_reverse(LinkedList* list) {
    if (!list || !list->head) { return; }

    Node* prev = nullptr;
    Node* current = list->head;
    Node* next = current->next;

    while (current && current->next) {
        current->next = prev;
        prev = current;
        current = next;
        next = current->next;
    }

    current->next = prev;
    list->head = current;
}

void list_add_numbers(LinkedList* list1, LinkedList* list2, LinkedList* result_list) {
    if (!list1 || !list2 || !list1->head || !list2->head || !result_list) {
        return;
    }

    list_reverse(list1);
    list_reverse(list2);

    int carry = 0;

    Node* l1_curr = list1->head;
    Node* l2_curr = list2->head;
    while (l1_curr || l2_curr || carry) {
        int sum = carry;
        if (l1_curr) {
            sum += l1_curr->data;
            l1_curr = l1_curr->next;
        }
        if (l2_curr) {
            sum += l2_curr->data;
            l2_curr = l2_curr->next;
        }

        list_insert_front(result_list, sum % 10);
        carry = sum / 10;
    }
}

int main() {
    LinkedList ls1;
    LinkedList ls2;
    list_init(&ls1);
    list_init(&ls2);

    list_insert_front(&ls1, 4);
    list_insert_front(&ls1, 2);

    list_insert_front(&ls2, 6);
    list_insert_front(&ls2, 5);
    list_insert_front(&ls2, 1);

    list_display(&ls1);
    list_display(&ls2);

    LinkedList resultls;
    list_init(&resultls);
    list_add_numbers(&ls1, &ls2, &resultls);
    list_display(&resultls);

    list_destroy(&resultls);
    list_destroy(&ls2);
    list_destroy(&ls1);

    return 0;
}
