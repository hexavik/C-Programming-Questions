/**
 * @file find_linked_list_length.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

Node * init(int data) {
    Node * head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;

    return head;
}

void add_node(Node * list, int data) {
    Node * new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // Traverse to the end
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = new_node;
}

void display_list(Node * list) {
    while (list) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void free_list(Node * list) {
    while (list) {
        Node * temp = list;
        list = list->next;
        free(temp);
    }
}

/**
* @note:This method is faster than the two pointers method
*/
// size_t get_list_size(list * l) {
//     size_t counter = 0;
//     while (l) {
//         counter++;
//         l = l->next;
//     }
//     return counter;
// }

/**
 * @brief Get the size of the linked list using two pointers method,
 * one is slow and another is fast. Fast moves two steps at once,
 * whereas slow moves one step at once.
 *
 * @param l Linked list pointer
 * @return size_t Total count of nodes in a linked list
 */
size_t get_list_size(Node * list) {
    size_t counter = 0;
    Node * slow = list;
    Node * fast = list;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        counter += 2;
    }

    if (fast) {
        counter++; // If list has odd number of nodes
    }

    return counter;
}

int main() {
    Node * lst = init(1);
    add_node(lst, 2);
    add_node(lst, 3);
    add_node(lst, 4);
    add_node(lst, 5);

    display_list(lst);

    printf("Length: %zu\n", get_list_size(lst));

    free_list(lst);

    return 0;
}
