#ifndef INTEGERBST_H
#define INTEGERBST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef int (*CompareFunc)(int a, int b);

typedef struct {
    BSTNode *root;
    int nodeCount;
    CompareFunc compare;
} BinarySearchTree;

// Initialize the BST
void initializeBST(BinarySearchTree *bst, CompareFunc compFunc) {
    bst->root = NULL;
    bst->nodeCount = 0;
    bst->compare = compFunc;
}

// Insert a key into the BST
int insertKey(BinarySearchTree *bst, int key) {
    BSTNode **current = &(bst->root);
    while (*current != NULL) {
        int compResult = bst->compare(key, (*current)->key);
        if (compResult == 0) return -1; // Key already exists
        current = (compResult > 0) ? &((*current)->right) : &((*current)->left);
    }
    *current = (BSTNode *)malloc(sizeof(BSTNode));
    if (*current == NULL) return -2; // Memory allocation failed
    (*current)->key = key;
    (*current)->left = (*current)->right = NULL;
    bst->nodeCount++;
    return 0; // Success
}

// Search for a key in the BST
BSTNode *searchKey(BinarySearchTree *bst, int key) {
    BSTNode *current = bst->root;
    while (current != NULL) {
        int compResult = bst->compare(key, current->key);
        if (compResult == 0) return current; // Key found
        current = (compResult > 0) ? current->right : current->left;
    }
    return NULL; // Key not found
}

// Helper functions for different traversal orders
void printInOrder(BSTNode *node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

void printPreOrder(BSTNode *node) {
    if (node != NULL) {
        printf("%d ", node->key);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printPostOrder(BSTNode *node) {
    if (node != NULL) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%d ", node->key);
    }
}

// Print the BST based on the traversal mode
void printBST(BinarySearchTree *bst, const char *order) {
    if (strcmp(order, "inorder") == 0) {
        printInOrder(bst->root);
    } else if (strcmp(order, "preorder") == 0) {
        printPreOrder(bst->root);
    } else if (strcmp(order, "postorder") == 0) {
        printPostOrder(bst->root);
    }
    printf("\n");
}

// Query the maximum and minimum key in the BST
void queryMinMax(BinarySearchTree *bst, int *min, int *max) {
    *min = *max = 0;
    if (bst->root == NULL) return;

    BSTNode *current = bst->root;
    *min = current->key;
    while (current->left != NULL) {
        current = current->left;
        *min = current->key;
    }

    current = bst->root;
    *max = current->key;
    while (current->right != NULL) {
        current = current->right;
        *max = current->key;
    }
}

#endif
