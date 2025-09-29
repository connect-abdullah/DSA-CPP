#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *prev;
  Node *next;

  Node(int value, Node *prevPtr = nullptr, Node *nextPtr = nullptr)
      : data(value), prev(prevPtr), next(nextPtr) {};
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void insert(int data) {
    Node *newNode = new Node(data, nullptr, nullptr);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->prev = tail; // Set newNode's prev to current tail
      tail->next = newNode; // Current tail's next points to new node
      tail = newNode;       // Update tail to newNode
    }
  }

  void insertAtMiddle(int nodeData, int data) {
    Node *newNode = new Node(data);
    Node *current = head;
    while (current->data != nodeData) {
      current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
  }

  // Lab Task 1
  void reverseDoubleList() {
    Node *temp = tail;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->prev;
    }
    cout << "NULL" << endl;
  }

  // Lab Task 2
  void swapNodes(int value1, int value2) {
    // Make sure both are not same
    if (value1 == value2) return;

    // Initialize both with head
    Node *node1 = head;
    Node *node2 = head;

    // Find node1
    while (node1 != nullptr && node1->data != value1) {
      node1 = node1->next;
    }

    // Find node2
    while (node2 != nullptr && node2->data != value2) {
      node2 = node2->next;
    }

    // if either not found
    if (node1 == nullptr || node2 == nullptr) return;

    // Now make conditions that if either of them was tail or head, how to deal
    // with them

    // If node1 was head
    if (node1->prev != nullptr) {
      node1->prev->next = node2;
    } else {
      head = node2;
    }

    // If node2 was head
    if (node2->prev != nullptr) {
      node2->prev->next = node1;
    } else {
      head = node1;
    }

    // If node1 was tail
    if(node1->next != nullptr) {
        node1->next->prev = node2;
    } else {
        tail = node2;
    }

    // If node2 was tail
    if(node2->next != nullptr) {
        node2->next->prev = node1;
    } else {
        tail = node1;
    }

    // Now all conditions are fulfilled, like any of those needed, function can adapt.
    // Now write basic default ones if none of that needed from above.

    // Now swap node1 and node2's prev/next
    Node* tempNext = node1->next;
    Node* tempPrev = node1->prev;

    node1->next = node2->next;
    node1->prev = node2->prev;

    node2->next = tempNext;
    node2->prev = tempPrev;
  }

  void display() {
    Node *current = head;
    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList list;
  list.insert(10);
  list.insert(20);
  list.insert(30);
  list.insert(40);

  list.insertAtMiddle(20, 25);

  list.display();
//   list.reverseDoubleList();
  list.swapNodes(20, 30);
  list.display();
  return 0;
}