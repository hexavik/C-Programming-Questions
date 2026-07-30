/**
 * @file clone_linked_list_with_random_pointer.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//
// A basic block of a Linked List
//
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* random;
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

    printf("List: ");
    Node* current = list->head;
    while (current) {
        // Display address to distinguish betwwen original and cloned node
        printf("[%d (%p)] → ", current->data, current);
        current = current->next;
    }
    printf("Null\n");
}

/**
 * @brief Add fixed set of nodes inside a linked list and assign a random
 * pointer to each node in the list manually
 *
 * @param list Exisiting linked list which must be empty
 */
void list_add_nodes(LinkedList* list) {
    //
    // Set original linked list next pointers
    //
    list_insert_front(list, 1);
    list_insert_front(list, 2);
    list_insert_front(list, 3);
    list_insert_front(list, 4);
    list_insert_front(list, 5);

    //
    // Set random pointers
    //
    list->head->random = list->head->next->next;
    list->head->next->random = list->head;
    list->head->next->next->random = nullptr;
    list->head->next->next->next->random = list->head->next->next->next;
    list->head->next->next->next->next->random = list->head->next;
}

//
// Fix size of the hash table indices
//
enum {
    HASH_SIZE = 16
};

//
// A basic block of a hash table entry
//
typedef struct HashEntry {
    Node* key;              // Store original node address
    Node* value;            // Store cloned node address
    struct HashEntry* next; // Handle collisions via chaining
} HashEntry;

/**
 * @brief Convert a pointer address intp an array index
 *
 * @param key Original node pointer
 * @return size_t the index of the hash table at which the node present
 */
size_t hash_pointer(Node* key) {
    return ((uintptr_t)key) % HASH_SIZE;
}

/**
 * @brief Insert a hash table entry of the original node and the cloned node,
 * where the index of the hash table auto-calculated based on the original
 * node address
 *
 * @param table An existing hash table pointer
 * @param key Input original node address/pointer
 * @param value Input cloned node address/pointer
 */
void ht_insert(HashEntry** table, Node* key, Node* value) {
    if (key == nullptr) { return; }

    size_t index = hash_pointer(key);

    HashEntry* entry = malloc(sizeof(*entry));
    if (!entry) { return; }
    entry->key = key;
    entry->value = value;
    entry->next = table[index];
    table[index] = entry;
}

/**
 * @brief Retrieve the cloned node address/pointer of the respective input
 * original node address/pointer
 *
 * @param table An existing hash table
 * @param key Input original node pointer
 * @return Node* Output cloned node pointer
 */
Node* ht_get(HashEntry** table, Node* key) {
    if (!key) { return nullptr; }

    size_t index = hash_pointer(key);
    HashEntry* current = table[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return nullptr;
}

/**
 * @brief Destroy all the entries inside a hash table
 *
 * @param table An existing hash table
 */
void ht_destroy(HashEntry** table) {
    for (size_t i = 0; i < HASH_SIZE; ++i) {
        HashEntry* current = table[i];
        while (current) {
            HashEntry* temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = nullptr;
    }
}

/**
 * @brief Clone an input linked list along with all 'next' and 'random'
 * pointers assigned to each of its existing nodes without changing the pattern
 * of the 'next' and 'random' pointers of the each node using a hash table
 *
 * @param list An existing non-empty linked list
 * @return Node* head node of the cloned linked list
 */
Node* list_clone_random(LinkedList* list) {
    if (!list || !list->head) { return nullptr; }

    //
    // Initiate our translation ledger array
    //
    HashEntry* table[HASH_SIZE] = { nullptr };

    Node* current = list->head;
    Node* clone_head = nullptr;
    Node* clone_tail = nullptr;

    //
    // Copy nodes, link 'next' pointers and fill the ledger
    //
    while (current) {
        Node* new_node = malloc(sizeof(*new_node));
        if (!new_node) {
            ht_destroy(table);
            return nullptr;
        }
        new_node->data = current->data;
        new_node->next = nullptr;
        new_node->random = nullptr;

        //
        // Write to ledger: [Original address → Cloned address]
        //
        ht_insert(table, current, new_node);

        //
        // Build the basic straight-line clone list
        //
        if (clone_head == nullptr) {
            clone_head = new_node;
            clone_tail = new_node;
        } else {
            clone_tail->next = new_node;
            clone_tail = new_node;
        }

        current = current->next;
    }

    //
    // Connect the random pointers
    //
    current = list->head;
    while (current) {
        //
        // Find who the current clone node is
        //
        Node* clone_current = ht_get(table, current);

        if (clone_current) {
            //
            // Look up where the original's random pointed
            // translate it o the clone equivalent, and assign it
            //
            clone_current->random = ht_get(table, current->random);
        }
        current = current->next;
    }

    ht_destroy(table);

    return clone_head;
}

int main() {
    LinkedList ls;
    list_init(&ls);
    list_add_nodes(&ls);

    list_display(&ls);

    LinkedList cloned_ls;
    list_init(&cloned_ls);
    cloned_ls.head = list_clone_random(&ls);
    list_display(&cloned_ls);

    list_destroy(&cloned_ls);
    list_destroy(&ls);

    return 0;
}
