#include <iostream>
using namespace std;
#include <vector>

struct Node {
  int data;
  Node *next;

  // Constructor
  Node(int value, Node *nextPtr = nullptr) : data(value), next(nextPtr) {}
};

class LinkedList {
private:
  Node *head;
  Node *tail;

public:
  // Constructor so that at the start, head & tails are null
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // Clean up after destroying the object
  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }

  void insertAtBeginning(int value) {
    Node *newNode = new Node(value, head);
    head = newNode;
    if (tail == nullptr) {
      tail = newNode;
    }
  }

  void insertAtEnd(int value) {
    Node *newNode = new Node(value, nullptr);
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void insertAfter(Node *prev, int value) {
    if (prev == nullptr)
      return;
    Node *newNode = new Node(value, prev->next);
    prev->next = newNode;
    if (prev == tail)
      tail = newNode;
  }

  void deleteFromBeginning() {
    if (head == nullptr)
      return;
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr)
      tail = nullptr;
  }

  void deleteFromEnd() {
    if (head == nullptr)
      return;
    if (head == tail) { // If only one node available
      delete head;
      head = tail = nullptr;
      return;
    }

    Node *current = head;
    while (current->next != tail) {
      current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
  }

  void deleteAfter(Node *prev) {
    if (prev == nullptr || prev->next == nullptr)
      return;
    Node *target = prev->next;
    prev->next = target->next;
    if (target == tail)
      tail = prev;
    delete target;
  }

  void display() {
    Node *current = head;
    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "Null" << endl;
  }

  void displayReverse() {
    vector<int> values;
    Node *current = head;
    while (current != nullptr) {
      values.push_back(current->data);
      current = current->next;
    }
    for (int i = values.size() - 1; i >= 0; i--) {
      cout << values[i] << " -> ";
    }
    cout << "Null" << endl;
  }

  void displayRecursive(Node *current) {
    if (current == nullptr) {
      return;
    }
    displayRecursive(current->next);
    cout << current->data << " -> ";
  }

  Node *getHead() { return head; }
};

int main() {
  LinkedList list;

  list.insertAtEnd(10);      // list: 10
  list.insertAtEnd(20);      // list: 10 -> 20
  list.insertAtBeginning(5); // list: 5 -> 10 -> 20
  list.insertAtEnd(30);      // list: 5 -> 10 -> 20 -> 30

  cout << "List after insertions: ";
  list.display();

  cout << "List after reverse: ";
  list.displayReverse();

  cout << "List Recursively: ";
  list.displayRecursive(list.getHead());

  return 0;
}
