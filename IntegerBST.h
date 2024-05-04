#ifndef INTEGERBST_H
#define INTEGERBST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the binary search tree
typedef struct BSTNode {
    int key;                   // The value/key of the node
    struct BSTNode *left;      // Pointer to the left child
    struct BSTNode *right;     // Pointer to the right child
} BSTNode;

// Function pointer type for comparison functions
typedef int (*CompareFunc)(int a, int b);

// Structure to represent the binary search tree
typedef struct {
    BSTNode *root;             // Pointer to the root node of the tree
    int nodeCount;             // Number of nodes in the tree
    CompareFunc compare;       // Function pointer for the comparison function
} BinarySearchTree;

// Initializes the BST with a given comparison function
void initializeBST(BinarySearchTree *bst, CompareFunc compFunc) {
    bst->root = NULL;          // Set the root to NULL indicating an empty tree
    bst->nodeCount = 0;        // Initialize node count to zero
    bst->compare = compFunc;   // Set the comparison function
}

// Inserts a key into the BST, returns 0 on success, or an error code
int insertKey(BinarySearchTree *bst, int key) {
    BSTNode **current = &(bst->root);
    while (*current != NULL) {
        int compResult = bst->compare(key, (*current)->key);
        if (compResult == 0) return -1; // Key already exists, return error
        // Navigate to the correct child based on comparison result
        current = (compResult > 0) ? &((*current)->right) : &((*current)->left);
    }
    *current = (BSTNode *)malloc(sizeof(BSTNode)); // Allocate memory for new node
    if (*current == NULL) return -2; // Memory allocation failed, return error
    (*current)->key = key;          // Set the key for the new node
    (*current)->left = (*current)->right = NULL; // Initialize children to NULL
    bst->nodeCount++;               // Increment the count of nodes
    return 0;                       // Success
}

// Searches for a key in the BST, returns a pointer to the node if found
BSTNode *searchKey(BinarySearchTree *bst, int key) {
    BSTNode *current = bst->root;   // Start from the root
    while (current != NULL) {
        int compResult = bst->compare(key, current->key);
        if (compResult == 0) return current; // Key found, return node
        // Move to the next child based on comparison result
        current = (compResult > 0) ? current->right : current->left;
    }
    return NULL; // Key not found
}

// Recursively frees nodes of the BST
void freeBST(BSTNode *node) {
    if (node != NULL) {
        freeBST(node->left);  // Free the left subtree
        freeBST(node->right); // Free the right subtree
        free(node);           // Free the current node
    }
}

// Recursive function to print nodes in inorder
void printInOrder(BSTNode *node) {
    if (node != NULL) {
        printInOrder(node->left);   // Recurse on left child
        printf("%d ", node->key);   // Print the key
        printInOrder(node->right);  // Recurse on right child
    }
}

// Recursive function to print nodes in preorder
void printPreOrder(BSTNode *node) {
    if (node != NULL) {
        printf("%d ", node->key);   // Print the key
        printPreOrder(node->left);  // Recurse on left child
        printPreOrder(node->right); // Recurse on right child
    }
}

// Recursive function to print nodes in postorder
void printPostOrder(BSTNode *node) {
    if (node != NULL) {
        printPostOrder(node->left);  // Recurse on left child
        printPostOrder(node->right); // Recurse on right child
        printf("%d ", node->key);    // Print the key
    }
}

// Prints the BST based on the specified traversal order
void printBST(BinarySearchTree *bst, const char *order) {
    if (strcmp(order, "inorder") == 0) {
        printInOrder(bst->root);   // Print in inorder
    } else if (strcmp(order, "preorder") == 0) {
        printPreOrder(bst->root);  // Print in preorder
    } else if (strcmp(order, "postorder") == 0) {
        printPostOrder(bst->root); // Print in postorder
    }
    printf("\n");
}

// Queries and returns the minimum and maximum key in the BST
void queryMinMax(BinarySearchTree *bst, int *min, int *max) {
    *min = *max = 0; // Initialize min and max
    if (bst->root == NULL) return; // Return if tree is empty

    BSTNode *current = bst->root;
    *min = current->key; // Start with root for min
    while (current->left != NULL) { // Traverse to the leftmost node
        current = current->left;
        *min = current->key; // Update min
    }

    current = bst->root;
    *max = current->key; // Start with root for max
    while (current->right != NULL) { // Traverse to the rightmost node
        current = current->right;
        *max = current->key; // Update max
    }
}

#endif // INTEGERBST_H
