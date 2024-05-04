#include "IntegerBST.h"
#include <assert.h>
#include <string.h>

// Returns the comparison result between two integers
int compareByValue(int a, int b) {
    // Return 1 if a is greater, -1 if less, and 0 if equal
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

// Calculate the sum of digits of an integer
int sumDigits(int n) {
    int sum = 0; // Initialize sum of digits
    while (n != 0) { // Process each digit
        sum += n % 10; // Add digit to sum
        n /= 10; // Remove last digit
    }
    return sum; // Return the sum of digits
}

// Compares two integers based on the sum of their digits
int compareByDigitSum(int a, int b) {
    // Delegate to compareByValue using sum of digits
    return compareByValue(sumDigits(a), sumDigits(b));
}

// Reverses the digits of an integer
int reverseDigits(int n) {
    int reversed = 0; // Initialize reversed number
    while (n != 0) { // Loop until all digits are reversed
        reversed = reversed * 10 + n % 10; // Append digit to reversed number
        n /= 10; // Remove the last digit
    }
    return reversed; // Return the reversed number
}

// Compares two integers based on their reversed digit values
int compareByDigitReverse(int a, int b) {
    // Delegate to compareByValue using reversed numbers
    return compareByValue(reverseDigits(a), reverseDigits(b));
}

// Main function: entry point of the program
int main(int argc, char *argv[]) {
    BinarySearchTree bst; // Declare a binary search tree
    assert(&bst != NULL);   // Verify BST memory allocation

    // Initialize BST with default comparison function
    initializeBST(&bst, compareByValue);  
    // Ensure BST is initialized correctly
    assert(bst.root == NULL && bst.nodeCount == 0 && bst.compare != NULL); 

    int *testKey = NULL; // Pointer to test search functionality later
    // Insert integers provided as command line arguments into BST
    for (int i = 1; i < argc; i++) {
        int key = atoi(argv[i]); // Convert argument to integer
        if (i == 1) { // Save first key to test search functionality
            testKey = &key;
        }

        // Attempt to insert key and report any errors
        if (insertKey(&bst, key) != 0) {
            printf("Error inserting key: %d\n", key);
        }
    }
    
    // Validate search functionality with the first inserted key
    if (testKey != NULL) {
        assert(searchKey(&bst, *testKey)); // Ensure the key can be found
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

    // Query and display the minimum and maximum key in the BST
    int min, max;
    queryMinMax(&bst, &min, &max);
    printf("Minimum key: %d\n", min);
    printf("Maximum key: %d\n", max);

    return 0; // Exit the program
}
