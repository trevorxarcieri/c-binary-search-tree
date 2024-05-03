#include "IntegerBST.h"
#include <string.h>

// Comparison functions
int compareByValue(int a, int b) {
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

int sumDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int compareByDigitSum(int a, int b) {
    return compareByValue(sumDigits(a), sumDigits(b));
}

int reverseDigits(int n) {
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int compareByDigitReverse(int a, int b) {
    return compareByValue(reverseDigits(a), reverseDigits(b));
}

int main(int argc, char *argv[]) {
    BinarySearchTree bst;
    initializeBST(&bst, compareByValue);  // Default comparison function

    // Insert integers provided as command line arguments
    for (int i = 1; i < argc; i++) {
        int key = atoi(argv[i]);
        if (insertKey(&bst, key) != 0) {
            printf("Error inserting key: %d\n", key);
        }
    }

    // Print the BST in inorder traversal
    printf("BST in inorder traversal: ");
    printBST(&bst, "inorder");
    
    // Print the BST in preorder traversal
    printf("BST in preorder traversal: ");
    printBST(&bst, "preorder");

    // Print the BST in postorder traversal
    printf("BST in postorder traversal: ");
    printBST(&bst, "postorder");

    // Query and print the min and max values
    int min, max;
    queryMinMax(&bst, &min, &max);
    printf("Minimum key: %d\n", min);
    printf("Maximum key: %d\n", max);

    return 0;
}

