#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void insert(int val) {
        this->root = insert(root, val);
    }

    // Helper to display the tree sideways
    void displayTree(Node* root, int space = 0, int height = 5) {
        // Base case
        if (root == nullptr)
            return;

        space += height;

        // Print right child first
        displayTree(root->right, space, height);

        // Print current node
        cout << endl;
        for (int i = height; i < space; i++)
            cout << " ";
        cout << root->data << endl;

        // Print left child
        displayTree(root->left, space, height);
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
    void display() {
        displayTree(root, 0, 5);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);

    cout << "Tree structure:\n";
    tree.display();
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;
    return 0;
}