#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// ===============================
// Node Structure (Binary Tree Node)
// Each employee has a name, and pointers to left & right children
// ===============================
struct Node {
  string name;
  Node *left;
  Node *right;

  Node(const string &name) : name(name), left(nullptr), right(nullptr) {}
};

// ================================================================
// Function to reconstruct a Full Binary Tree from preorder & postorder
// preorder  → Root, Left, Right
// postorder → Left, Right, Root
// This function works only for Full Binary Trees (every node has 0 or 2
// children)
// ================================================================
Node *buildTree(vector<string> &preorder, vector<string> &postorder,
                int &preIndex, int postStart, int postEnd) {

  // If we run past array bounds, or invalid segment, stop recursion
  if (preIndex >= preorder.size() || postStart > postEnd)
    return nullptr;

  // Create current root using preorder
  Node *root = new Node(preorder[preIndex]);
  preIndex++; // Move to next element in preorder

  // If only one element exists in this postorder segment → leaf node
  if (postStart == postEnd)
    return root;

  // The next element in preorder is always root of left subtree
  string leftSubtreeRoot = preorder[preIndex];

  // Search for this element in postorder to determine left subtree boundary
  int index = -1;
  for (int i = postStart; i <= postEnd; i++) {
    if (postorder[i] == leftSubtreeRoot) {
      index = i;
      break;
    }
  }

  // Recursively build left subtree (from postStart to index)
  root->left = buildTree(preorder, postorder, preIndex, postStart, index);

  // Recursively build right subtree (index+1 to postEnd-1)
  root->right =
      buildTree(preorder, postorder, preIndex, index + 1, postEnd - 1);

  return root;
}

// ================================================================
// Display Tree in Level Order (BFS) to show structure clearly
// CEO
// Managers
// Team Leads
// Developers
// ================================================================
void printLevelOrder(Node *root) {
  if (!root)
    return;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();

    // Print all nodes at current level
    while (levelSize--) {
      Node *current = q.front();
      q.pop();

      cout << current->name << " ";

      if (current->left)
        q.push(current->left);
      if (current->right)
        q.push(current->right);
    }
    cout << endl;
  }
}

// ================================================================
// MAIN FUNCTION
// Builds tree from employee hierarchy and prints level-order output
// ================================================================
int main() {

  // Example traversal data from TechTree Inc. (as per problem statement)
  vector<string> preorder = {"CEO",  "Manager1", "TeamLead1",
                             "Dev1", "Dev2",     "TeamLead2",
                             "Dev3", "Dev4",     "Manager2"};

  vector<string> postorder = {"Dev1",     "Dev2",     "TeamLead1",
                              "Dev3",     "Dev4",     "TeamLead2",
                              "Manager1", "Manager2", "CEO"};

  // Start from first element of preorder
  int preIndex = 0;

  // Reconstruct the Full Binary Tree
  Node *root =
      buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1);

  // Display hierarchy
  cout << "Company Hierarchy (Level Order):\n";
  printLevelOrder(root);

  return 0;
}

// Here is the **same explanation broken into clear, memorable points**:
// * Preorder gives nodes in the exact order they must be created: first the
// root, then left subtree, then right subtree.
// * Each time we take the next value from preorder, we are building the correct
// parent node.
// * After picking a root, the next value in preorder must be the root of the
// left subtree.
// * We search for this value in the current postorder range.
// * All postorder elements before that index belong to the entire left subtree.
// * All elements after that index (except the last one, which is the current
// root) belong to the right subtree.
// * If the postorder slice has only one element, that node must be a leaf, so
// recursion stops for that branch.
// * By repeatedly splitting preorder and postorder like this, the entire tree
// is reconstructed correctly.
// * This ensures every non-leaf node ends up with exactly two children, which
// satisfies the Full Binary Tree requirement.