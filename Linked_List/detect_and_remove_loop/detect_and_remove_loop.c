/**
 * @file detect_and_remove_loop.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-09
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
    Node* tail;
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
    list->tail = nullptr;
    list->size = 0;
}

/**
 * @brief Insert a node at the fron of the list
 *
 * @param list Existing list which must not be null
 * @param value Input value
 */
void list_insert_front(LinkedList* list, int value) {
    if (!list) { return; }

    if (!list->tail && list->head) { list->tail = list->head; }

    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return; }
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size += 1;
}

/**
 * @brief Insert a node at the end of the list
 *
 * @param list Existing list which must not be null
 * @param data Input value
 */
void list_insert_back(LinkedList* list, int value) {
    if (!list) { return; }

    Node* new_node = malloc(sizeof(*new_node));
    new_node->data = value;
    new_node->next = nullptr;
    if (!list->head) {
        list->head = new_node;
        list->tail = new_node;
        return;
    }
    list->tail->next = new_node;
    list->tail = new_node;
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
        list->head = current->next;
        free(current);
        current = list->head;
    }

    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
}

void list_display(LinkedList* list) {
    if (!list || !list->head) { return; }

    printf("List: ");
    Node* current = list->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("Null\n");
}

/**
 * @brief Traverse the list using Floyd's Algorithm (slow and fast pointers),
 * detect the loop in case fast and slow pointers intersects each other,
 * otherwise return to main as soon as fast or fast->next becomes null.
 * In case of detection of the loop, remove it by resetting the slow pointer
 * to the head and keeping the fast pointer at the intersection. Continue
 * traversing again the same way slow and fast pointer moves, mark the previous
 * node where they intersect again and assign null value to node->next so that
 * the loop is broken.
 *
 * @param list Existing list must not be null
 * @return true Loop is detected and removed
 * @return false No loop is detected
 */
bool loop_detect_and_remove(LinkedList* list) {
    Node* slow = list->head;
    Node* fast = list->head;
    bool is_detected = false;
    Node* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            if (is_detected == true) {
                prev->next = nullptr;
                return true;
            }

            slow = list->head;
            is_detected = true;
        }
    }

    return false;
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_insert_back(&ls, 1);
    list_insert_back(&ls, 2);
    list_insert_back(&ls, 3);
    list_insert_back(&ls, 4);
    list_insert_back(&ls, 5);
    list_insert_back(&ls, 6);
    list_insert_back(&ls, 7);
    list_insert_back(&ls, 8);

    // Use tail pointer only to make the list looped within
    ls.tail->next = ls.head;

    loop_detect_and_remove(&ls)
        ? printf("Loop detected and removed\n")
        : printf("No loop detected\n");

    list_display(&ls);

    list_destroy(&ls);

    return 0;
}
