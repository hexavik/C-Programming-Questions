/**
 * @file flatten_multi_level_linked_list.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-16
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
    struct Node* child;
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
 * @brief Create a new linked list node
 *
 * @param data
 * @param child Pointer to the child node
 * @return Node* Output pointer of the created node
 */
Node* node_create(int data, Node* child) {
    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return nullptr; }
    new_node->data = data;
    new_node->next = nullptr;
    new_node->child = child;
    return new_node;
}

/**
 * @brief Insert a node at the front of the list
 *
 * @param list Existing list which must not be null
 * @param value Input value for a node
 */
void list_insert_front(LinkedList* list, Node* node) {
    if (!list || !node) { return; }

    node->next = list->head;
    list->head = node;
    list->size += 1;
}

/**
 * @brief Destroy all existing nodes inside the list,
 * must be called at the end of the program to avoid memory leak.
 *
 * @param list Existing linked list
 */
void list_destroy(Node* head) {
    if (!head) { return; }

    Node* current = head;
    while (current) {
        head = head->next;
        free(current);
        current = head;
    }
}

void list_display(Node* head) {
    printf("[");
    Node* current = head;
    while (current) {
        printf("%d", current->data);
        if (current->child) {
            printf(" ");
            list_display(current->child);
        }
        printf(" → ");
        current = current->next;
    }
    printf("Null]");
}

//
// A basic block fo a Stack
//
typedef struct StackNode {
    Node* data;
    struct StackNode* next;
} StackNode;

//
// Management for Stack
//
typedef struct Stack {
    StackNode* top;
} Stack;

/**
 * @brief Push a node inside a stack
 *
 * @param top Top Pointer of the stack
 * @param list_node Input linked list node
 */
void stack_push(StackNode** top, Node* list_node) {
    if (!list_node) { return; }

    StackNode* new_stack_node = malloc(sizeof(*new_stack_node));
    if (!new_stack_node) { return; }
    new_stack_node->data = list_node;
    new_stack_node->next = *top;
    *top = new_stack_node;
}

/**
 * @brief Pop a node from a stack
 *
 * @param top Top pointer of the stack
 * @return Node* Popped Node
 */
Node* stack_pop(StackNode** top) {
    if (!top || !(*top)) { return nullptr; }

    Node* popped_node = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return popped_node;
}

/**
 * @brief Push all the linked list nodes inside the stack
 *
 * @param top Top pointer of the stack
 * @param head Linked list head node pointer
 */
void list_stack(StackNode** top, Node* head) {
    if (!head) { return; }

    Node* current = head;
    while (current) {
        stack_push(top, current);
        if (current->child) {
            list_stack(top, current->child);
        }
        current = current->next;
    }
}

/**
 * @brief FLatten the multi-level linked list, where the ndoes may have a child
 * nodes which may have further next nodes to it.
 *
 * @param list Input multi-level linked list
 */
void list_flatten(LinkedList* list) {
    if (!list || !list->head) { return; }

    Stack st;
    st.top = nullptr;

    list_stack(&st.top, list->head);

    // De-stack
    list->head = nullptr;
    StackNode** stack_node = &st.top;
    while ((*stack_node)) {
        Node* temp = stack_pop(stack_node);
        temp->next = list->head;
        temp->child = nullptr;
        list->head = temp;
    }
}

int main() {
    //
    // Multilevel sample linked list
    // 1 → 2 → 3 → 4
    //     |
    //     5 → 6
    //     |
    //     7
    //
    LinkedList ls_lv1;
    LinkedList ls_lv2;
    LinkedList ls_lv3;
    list_initialize(&ls_lv1);
    list_initialize(&ls_lv2);
    list_initialize(&ls_lv3);

    // Create level 3 list first
    list_insert_front(&ls_lv3,
                      node_create(7, nullptr));

    // Create level 2 list
    list_insert_front(&ls_lv2,
                      node_create(6, nullptr));
    list_insert_front(&ls_lv2,
                      node_create(5, ls_lv3.head));

    // Create level 1 list
    list_insert_front(&ls_lv1, node_create(4, nullptr));
    list_insert_front(&ls_lv1, node_create(3, nullptr));
    list_insert_front(&ls_lv1, node_create(2, ls_lv2.head));
    list_insert_front(&ls_lv1, node_create(1, nullptr));

    list_display(ls_lv1.head);
    printf("\n");

    list_flatten(&ls_lv1);
    list_display(ls_lv1.head);
    printf("\n");

    list_destroy(ls_lv1.head);
    // Reset the pointers to the null to avoid any dangling pointers
    list_initialize(&ls_lv3);
    list_initialize(&ls_lv2);
    list_initialize(&ls_lv1);

    return 0;
}
