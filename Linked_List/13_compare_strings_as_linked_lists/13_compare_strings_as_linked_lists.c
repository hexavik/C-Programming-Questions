/**
 * @file compare_strings_as_linked_lists.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-07
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
    char data;
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

Node* node_create(char ch) {
    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return nullptr; }
    new_node->data = ch;
    new_node->next = nullptr;
    return new_node;
}

void list_insert_back(LinkedList* list, char ch) {
    if (!list) { return; }

    Node* node = node_create(ch);
    if (!node) { return; }

    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

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
    if (current) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }

    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
}

void list_display(LinkedList* list) {
    if (!list) { return; }

    printf("List: ");
    Node* current = list->head;
    while (current) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * @brief Create a node for each character in a string (except '\0'),
 * input linked list must not be null and must be empty.
 *
 * @param str Input string to convert to a linked list
 * @param ls Input existing empty linked list
 */
void list_from_string(char* str, LinkedList* ls) {
    if (ls->head != nullptr) { return; }

    while (*str) {
        list_insert_back(ls, *str++);
    }
}

/**
 * @brief Compare two linked lists against their respective nodes,
 * both starts at their head nodes. If lenght of both linked lists
 * does not match then return false. Return true only and only if all
 * respective nodes are matching. Both linked lists must not be null.
 *
 * @param list1 Input existing first linked list
 * @param list2 Input existing second linked list
 * @return true If both strings are perfectly equal
 * @return false if neither length of linked lists nor their nodes
 * match with each other
 */
bool lists_compare(LinkedList* list1, LinkedList* list2) {
    if (list1->size != list2->size) { return false; }

    Node* curr1 = list1->head;
    Node* curr2 = list2->head;
    while (curr1) {
        if (curr1->data != curr2->data) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;
}

int main() {
    LinkedList ls1;
    LinkedList ls2;
    list_initialize(&ls1);
    list_initialize(&ls2);

    char* str1 = "Helllo";
    char* str2 = "world0";
    list_from_string(str1, &ls1);
    list_from_string(str2, &ls2);

    list_display(&ls1);
    list_display(&ls2);

    lists_compare(&ls1, &ls2) ?
        printf("Both strings are equal\n") :
        printf("Strings are not equal\n");

    list_destroy(&ls1);
    list_destroy(&ls2);

    return 0;
}
