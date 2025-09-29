#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value, Node *nextPtr = nullptr) : data(value), next(nextPtr) {};
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
    Node *newNode = new Node(data, nullptr);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode; // Current tail's next points to new node
      tail = newNode; // then the tail becomes newNode with next to nullptr
    }
  }

  void insertAtBeginning(int data) {
    Node *newNode = new Node(data, head);
    head = newNode;
    if (tail == nullptr) {
      tail = newNode;
    }
  }

  void insertAtEnd(int data) {
    Node *newNode = new Node(data, nullptr);

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    } else {
      tail->next = newNode;
      tail = newNode;
    }

    // Using Traversing

    // Node* current = head;
    // while(current->next != nullptr) {
    //     current = current->next;
    // }
    // current->next = newNode;
    // tail = newNode;
  }

  void insertAtMiddle(int nodeNumber, int data) {
    Node *newNode = new Node(data, nullptr);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }
    Node *current = head;
    while (current->data != nodeNumber) {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }

  void deleteHead() {
    if (head == nullptr) {
      return; // List is already empty
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }
  }

  void deleteAtEnd() {
    // Case 1: Empty list
    if (head == nullptr) {
      return;
    }

    // Case 2: Only one node
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      tail = nullptr;
      return;
    }

    Node *prev = nullptr;
    Node *current = head;

    while (current->next != nullptr) {
      prev = current;
      current = current->next;
    }

    prev->next = nullptr;
    delete current;
    tail = prev;
  }

  void deleteAtMiddle(int nodeData) {
    if (head == nullptr) {
      return;
    }

    Node* prev = nullptr;
    Node* current = head;
    while(current->data != nodeData) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    if (current == tail) tail = prev;
    delete current;
  }

  void reverseAndDisplay(){
    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    while (current->next != nullptr) {
        next = current->next; // 2->5->10 , 5node will be stored here
        current->next = prev; // 2node's next will become nullptr, becoming tail
        prev = current; // current one will be stored here because at next iteration, we will point other node towards 2node.
        current = next; // 5node will become the first one and loop starts again
    }

    // now when current->next == nullptr
    current->next = prev;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
      }
      cout << "NULL" << endl;

  }

  void returnHead() {
    cout << "This is the current head: " << head->data << endl;
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

  list.insertAtBeginning(5);
  list.insertAtEnd(35);
  list.insertAtMiddle(20, 25);

  list.display();

  list.returnHead();

  list.reverseAndDisplay();

//   list.deleteAtMiddle(10);
//   list.display();

//   list.deleteHead();
//   list.deleteAtEnd();
//   list.display();
//   list.returnHead();
  return 0;
}