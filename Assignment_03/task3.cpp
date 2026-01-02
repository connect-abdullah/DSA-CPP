#include <iostream>
using namespace std;

// =====================
// BST Node
// =====================
struct Node {
    int amount;
    Node* left;
    Node* right;
    Node(int val) : amount(val), left(nullptr), right(nullptr) {}
};

// =====================
// BST Functions
// =====================
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->amount)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

void inorderBST(Node* root) {
    if (!root) return;
    inorderBST(root->left);
    cout << root->amount << " ";
    inorderBST(root->right);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

Node* deleteBST(Node* root, int val) {
    if (!root) return root;

    if (val < root->amount)
        root->left = deleteBST(root->left, val);
    else if (val > root->amount)
        root->right = deleteBST(root->right, val);
    else {
        // Node with one or no child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        Node* temp = minValueNode(root->right);
        root->amount = temp->amount;
        root->right = deleteBST(root->right, temp->amount);
    }
    return root;
}

// =====================
// Max Heap Functions
// =====================
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort (descending)
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// =====================
// MAIN PROGRAM
// =====================
int main() {
    int transactions[] = {4500, 2200, 5000, 1800, 3000, 4700, 5100, 2600, 1900};
    int n = sizeof(transactions)/sizeof(transactions[0]);

    Node* root = nullptr;

    // Build BST
    for (int i = 0; i < n; i++)
        root = insertBST(root, transactions[i]);

    cout << "BST In-Order (Before Deletion): ";
    inorderBST(root);
    cout << endl;

    // Delete 3000 and 5000
    root = deleteBST(root, 3000);
    root = deleteBST(root, 5000);

    cout << "BST In-Order (After Deletion): ";
    inorderBST(root);
    cout << endl;

    // Extract remaining transaction amounts for Max Heap
    int remaining[] = {4500, 2200, 1800, 4700, 5100, 2600, 1900};
    int remSize = sizeof(remaining)/sizeof(remaining[0]);

    // Heap sort
    heapSort(remaining, remSize);

    cout << "Transactions Descending: ";
    for (int i = remSize-1; i >= 0; i--)
        cout << remaining[i] << " ";
    cout << endl;

    return 0;
}
