/**
 * @file intersection_point_two_lists.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-08
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

/**
 * @brief Create a new node using an input value
 *
 * @param value Input value for the node
 * @return Node* new node pointer newly allocated on dynamic memory
 */
Node* node_create(int value) {
    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return nullptr; }
    new_node->data = value;
    new_node->next = nullptr;
    return new_node;
}

/**
 * @brief Destory both lists, even if they have a intersection node. Delete the
 * first list till the intersection node, and then delete the second list till
 * the intersection point. At last, delete the remaining nodes from the list
 * starting from the intersexction node.
 *
 * @param list1_head head pointer of the first input list
 * @param list2_head head pointer of the second input lists
 * @param intersect Node pointer at where the intersection node is availble
 */
void lists_destroy(Node* list1_head, Node* list2_head, Node* intersect) {
    Node* current = list1_head;
    if (current && current != intersect) {
        list1_head = list1_head->next;
        free(current);
        current = list1_head;
    }

    current = list2_head;
    if (current && current != intersect) {
        list2_head = list2_head->next;
        free(current);
        current = list2_head;
    }

    current = intersect;
    while (current) {
        intersect = intersect->next;
        free(current);
        current = intersect;
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

Node* lists_intersection(Node* head1, Node* head2) {
    if (!head1 || !head2) { return nullptr; }

    //
    // Use two pointers which are assigned to each list individually, let them
    // traverse till the end of the list, as soon as any one of them reach to
    // the end of the list (null value), then assign the head pointer of the
    // another list to it, and continue with traversal, at a certain point
    // they both will point to the intersection node.
    //
    Node* curr1 = head1;
    Node* curr2 = head2;

    while (curr1 != curr2) {
        curr1 = curr1 ? curr1->next : head2;
        curr2 = curr2 ? curr2->next : head1;
    }

    return curr1;
}

int main() {
    //
    // Creation of two intersecting linked lists:
    // List A: 1 → 2 → 3
    //                  \
    //                   → 4 → 5 → NULL
    //                  /
    // List B:     6 → 7
    //

    // Create the common intersecting nodes list
    Node* intersect_node = node_create(4);
    intersect_node->next = node_create(5);

    // Create List A
    Node*  head_a = node_create(1);
    head_a->next = node_create(2);
    head_a->next->next = node_create(3);
    // Connect the intersecting node to the end of the list A
    head_a->next->next->next = intersect_node;

    // Create List B
    Node* head_b = node_create(6);
    head_b->next = node_create(7);
    // Connect the intersecting node to the end of the list B
    head_b->next->next = intersect_node;

    list_display(head_a);
    list_display(head_b);

    Node* get_intersection = lists_intersection(head_a, head_b);
    if (get_intersection) {
        printf("Interection: %d\n", get_intersection->data);
    }

    lists_destroy(head_a, head_b, intersect_node);

    return 0;
}
