/**
 * @file common_ancestor_in_binary_tree_doubly_linked_list.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

typedef struct Node {
    int data;
    struct Node* left;   // Represents 'prev' in DLL
    struct Node* right;  // Represents 'next' in DLL
    struct Node* parent; // Parent node for backtracking
} Node;

typedef struct {
    Node* root;
    size_t size;
} BinaryTree;

void tree_initialize(BinaryTree* tree) {
    if (!tree) { return; }

    tree->root = nullptr;
    tree->size = 0;
}

Node* node_create(int value) {
    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return nullptr; }
    new_node->data = value;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->parent = nullptr;
    return new_node;
}

Node* tree_insert(BinaryTree* tree, int value) {
    if (!tree) { return nullptr; }

    Node* new_node = node_create(value);
    if (!new_node) { return nullptr; }

    if (tree->root == nullptr) {
        tree->root = new_node;
        tree->size += 1;
        return new_node;
    }

    Node* current = tree->root;
    Node* parent_tracker = nullptr;

    // Traverse down to find the right spot
    while (current) {
        parent_tracker = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Assign the crucial backward parent pointer
    new_node->parent = parent_tracker;

    // Common parent's downward child branch
    if (value < parent_tracker->data) {
        parent_tracker->left = new_node;
    } else {
        parent_tracker->right = new_node;
    }

    tree->size += 1;
    return new_node; // Return address so main can save direct node targets
}

void nodes_destroy(Node* node) {
    if (!node) { return; }
    nodes_destroy(node->left);
    nodes_destroy(node->right);
    free(node);
}

void tree_destroy(BinaryTree* tree) {
    if (!tree) { return; }
    nodes_destroy(tree->root);
    tree->root = nullptr;
    tree->size = 0;
}

void nodes_display(Node* node) {
    if (!node) { return; }
    nodes_display(node->left);
    printf("%d ", node->data);
    nodes_display(node->right);
}

void tree_display(BinaryTree* tree) {
    if (!tree || !tree->root) {
        printf("Tree is empty.\n");
        return;
    }
    printf("Tree: ");
    nodes_display(tree->root);
    printf("\n");
}

int get_node_depth(Node* node) {
    int depth = 0;
    while (node) {
        depth += 1;
        node = node->parent;
    }

    return depth;
}

Node* find_common_ancestor(Node* node_a, Node* node_b) {
    if (!node_a || !node_b) { return nullptr; }

    int depth_a = get_node_depth(node_a);
    int depth_b = get_node_depth(node_b);

    while (depth_a > depth_b) {
        node_a = node_a->parent;
        depth_a -= 1;
    }
    while (depth_b > depth_a) {
        node_b = node_b->parent;
        depth_b -= 1;
    }

    while (node_a != node_b) {
        node_a = node_a->parent;
        node_b = node_b->parent;
    }

    return node_a;
}

int main() {
    /*
        Sample Binary Tree
            20
          /    \
        10     30
       /  \
      5   15
     */

    BinaryTree tree;
    tree_initialize(&tree);

    tree_insert(&tree, 20);
    Node* ten = tree_insert(&tree, 10);
    tree_insert(&tree, 30);
    Node* five = tree_insert(&tree, 5);
    Node* fifteen = tree_insert(&tree, 15);

    tree_display(&tree);

    Node* ancestor1 = find_common_ancestor(five, fifteen);
    if (ancestor1) {
        printf("Common ancestor of %d and %d: %d\n", five->data, fifteen->data, ancestor1->data);
    }

    Node* ancestor2 = find_common_ancestor(five, ten);
    if (ancestor2) {
        printf("Common ancestor of %d and %d: %d\n", five->data, ten->data, ancestor1->data);
    }

    tree_destroy(&tree);

    return 0;
}
