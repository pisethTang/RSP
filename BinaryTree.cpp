#include <iostream>

// Node structure representing each element in the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinaryTree class to manage the binary tree operations
class BinaryTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the binary tree
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (current->left == nullptr) {
            current->left = insertRecursive(current->left, value);
        } else if (current->right == nullptr) {
            current->right = insertRecursive(current->right, value);
        } else {
            // If both children are present, insert into the left subtree
            current->left = insertRecursive(current->left, value);
        }

        return current;
    }

    // Helper function to perform in-order traversal
    void inOrderTraversal(TreeNode* current) {
        if (current != nullptr) {
            inOrderTraversal(current->left);
            std::cout << current->data << " ";
            inOrderTraversal(current->right);
        }
    }

    // Helper function to search for a value in the binary tree
    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else {
            return searchRecursive(current->left, value) || searchRecursive(current->right, value);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public function to insert a value into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Public function to perform in-order traversal
    void traverseInOrder() {
        std::cout << "In-Order Traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    // Public function to search for a value in the binary tree
    bool search(int value) {
        return searchRecursive(root, value);
    }
};

int main() {
    BinaryTree myTree;

    // Inserting values into the binary tree
    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(70);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(60);
    myTree.insert(80);

    // In-Order Traversal
    myTree.traverseInOrder();

    // Searching for values
    std::cout << "Is 40 in the tree? " << (myTree.search(40) ? "Yes" : "No") << std::endl;
    std::cout << "Is 90 in the tree? " << (myTree.search(90) ? "Yes" : "No") << std::endl;

    return 0;
}
