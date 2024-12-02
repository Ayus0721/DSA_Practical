#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert an element
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
        cout << "Inserted " << value << " into the BST.\n";
    }

    // Search for an element
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Delete an element
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
        cout << "Deleted " << value << " from the BST.\n";
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.inorder();
    tree.deleteNode(40);
    tree.inorder();
    cout << "Search 30: " << (tree.search(tree.root, 30) ? "Found" : "Not Found") << endl;
    return 0;
}
