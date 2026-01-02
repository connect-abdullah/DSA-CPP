#include <iostream>
#include <string>
using namespace std;

// =====================
// Property Node (BST + DLL)
// =====================
class Node {
public:
  int propertyID;
  string location;
  int price;
  Node *left;  // BST left or DLL previous
  Node *right; // BST right or DLL next

  Node(int id, string loc, int pr) {
    propertyID = id;
    location = loc;
    price = pr;
    left = right = nullptr;
  }
};

// =====================
// BST + DLL Manager
// =====================
class PropertyTree {
private:
  Node *root;
  Node *dllHead;
  Node *dllPrev;

  // Helper function for visual BST print
  void printBSTGraph(Node *node, int space = 0, int levelSpace = 8) {
    if (!node)
      return;

    space += levelSpace;

    // Print right subtree first
    printBSTGraph(node->right, space);

    // Print current node
    cout << endl;
    for (int i = levelSpace; i < space; i++)
      cout << " ";
    cout << "(" << node->propertyID << ")" << endl;

    // Print left subtree
    printBSTGraph(node->left, space);
  }

public:
  PropertyTree() {
    root = nullptr;
    dllHead = nullptr;
    dllPrev = nullptr;
  }

  // Insert into BST
  Node *insert(Node *node, int id, string loc, int price) {
    if (!node)
      return new Node(id, loc, price);
    if (id < node->propertyID)
      node->left = insert(node->left, id, loc, price);
    else
      node->right = insert(node->right, id, loc, price);
    return node;
  }

  void addProperty(int id, string loc, int price) {
    root = insert(root, id, loc, price);
  }

  // Display BST in-order
  void displayBST(Node *node) {
    if (!node)
      return;
    displayBST(node->left);
    cout << "ID: " << node->propertyID << ", Location: " << node->location
         << ", Price: " << node->price << endl;
    displayBST(node->right);
  }

  void printBST() {
    cout << "\n--- BST In-Order ---\n";
    displayBST(root);
  }

  // Print BST visually
  void displayBSTGraph() {
    cout << "\n--- BST Visual ---\n";
    printBSTGraph(root);
  }

  // Convert BST → DLL using in-order traversal
  void convertToDLL(Node *node) {
    if (!node)
      return;

    convertToDLL(node->left);

    if (!dllPrev)
      dllHead = node;
    else {
      dllPrev->right = node;
      node->left = dllPrev;
    }

    dllPrev = node;

    convertToDLL(node->right);
  }

  void convert() {
    dllHead = nullptr;
    dllPrev = nullptr;
    convertToDLL(root);
  }

  // Print DLL forward (ascending ID)
  void printForward() {
    cout << "\n--- DLL Forward (Ascending) ---\n";
    Node *current = dllHead;
    while (current) {
      cout << "ID: " << current->propertyID
           << ", Location: " << current->location
           << ", Price: " << current->price << endl;
      current = current->right;
    }
  }

  // Print DLL backward (descending ID)
  void printBackward() {
    cout << "\n--- DLL Backward (Descending) ---\n";
    Node *current = dllHead;
    if (!current)
      return;

    while (current->right)
      current = current->right;

    while (current) {
      cout << "ID: " << current->propertyID
           << ", Location: " << current->location
           << ", Price: " << current->price << endl;
      current = current->left;
    }
  }
};

// =====================
// MAIN PROGRAM
// =====================
int main() {
  PropertyTree system;

  // Insert properties into BST
  system.addProperty(50, "Karachi", 8000000);
  system.addProperty(30, "Lahore", 6000000);
  system.addProperty(70, "Islamabad", 12000000);
  system.addProperty(20, "Quetta", 4500000);
  system.addProperty(40, "Multan", 6500000);
  system.addProperty(60, "Peshawar", 9000000);
  system.addProperty(80, "Faisalabad", 11000000);

  // Display BST in-order
  system.printBST();

  // Display visual BST
  system.displayBSTGraph();

  // Convert BST → DLL
  system.convert();

  // Display DLL
  system.printForward();
  system.printBackward();

  return 0;
}
