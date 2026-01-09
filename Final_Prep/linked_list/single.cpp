#include <iostream>
using namespace std;

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
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  };

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
    Node *newNode = new Node(value, nullptr);
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
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

    if (prev == tail) {
      tail = newNode;
    }
  }

  void insertBefore(Node *nextNode, int value) {
    if (nextNode == nullptr)
      return;
    if (head == nullptr)
      return;

    // Special case: inserting before head
    if (nextNode == head) {
      Node *newNode = new Node(value, head);
      head = newNode;
      return;
    }

    // Find the node before nextNode
    Node *current = head;
    while (current != nullptr && current->next != nextNode) {
      current = current->next;
    }
    
    // If nextNode is not in the list, return
    if (current == nullptr)
      return;

    Node *newNode = new Node(value, nextNode);
    current->next = newNode;
  }

  void deleteFromBeginning() {
    if (head == nullptr)
      return;

    Node *temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }
  }

  void deleteFromEnd() {
    if (head == nullptr)
      return;

    if (head == tail) {
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
    if (prev == nullptr)
      return;
    if (!prev || !prev->next) return;


    Node *target = prev->next;
    prev->next = prev->next->next;
    if (target == tail) {
      tail = prev;
    }
    delete target;
  }

  void display() {
    if (head == nullptr) {
      cout << "null" << endl;
      return;
    }
    Node *current = head;
    while (current!= nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "null" << endl;
  }

  void reverseAndDisplay() {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr) {
      next = current->next; // storing next node
      current->next = prev;
      prev = current;
      current = next; // moving the current state
    }

    // for example we have 1 - 2 -> 2 - 3 -> 3 - nullptr
    // next stores 2 - 3
    // 1s next becomes nullptr as prev = nullptr at first, it becomes tail. 1 -
    // nullptr prev becomes 1 - nullptr; current moves to 2-3.

    // In next iteration, next stores 3-nullptr
    // 2-3s next points to prev, which is 1 - nullptr, becoming 2-1
    // now prev becomes 2-3 instead of 1 - nullptr
    // current moves on to 3 - nullptr

    // In last iteration, current is 3-nullptr, so next stores nullptr
    // 3-nullptr's next become 2-1, becoming 3-2
    // prev becomes 3-2
    // current moves to nullptr, ending the loop.

    // now list looks like this:
    // 3-2 -> 2-1 -> 1 - nullptr

    head = prev;

    current = head;
    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "null" << endl;
  }

  void displayRecursive(Node *current) {
    if (current == nullptr) {
      return ;
    }
    displayRecursive(current->next);
    cout << current->data << " -> ";
  }

  // Getters
  Node *getHead() { return head; }
  Node *getTail() { return tail; }

  Node *mergeLists(Node *list1, Node *list2) {
    // if list1 is empty, merge list is just list2
    if (list1 == nullptr)
      return list2;

    // traverse list1 until last node
    Node *current = list1;
    while (current->next != nullptr) {
      current = current->next;
    }

    // link last node of list1 to head of list2
    current->next = list2;

    // merged list head is still list1
    return list1;
  }

  void findOccurrences(Node *head, int key) {
    Node *current = head;
    int index = 0; // position tracker, as index starts from 0.
    int count = 0;

    while (current != nullptr) {
      if (current->data == key) {
        cout << "Found at position: " << index << endl;
        count++;
      }
      current = current->next;
      index++;
    }

    if (count == 0) {
      cout << "Element " << key << " not found in the list." << endl;
    } else {
      cout << "Total occurrences of " << key << ": " << count << endl;
    }
  }

  void bubbleSort(Node *head) {
    if (!head)
      return;

    bool swapped;
    Node *ptr;
    Node *lptr = nullptr;

    do {
      swapped = false;
      ptr = head;
      while (ptr->next != lptr) {
        if (ptr->data > ptr->next->data) {
          int temp = ptr->data;
          ptr->data = ptr->next->data;
          ptr->next->data = temp;
          swapped = true;
        }
        ptr = ptr->next;
      }
      lptr = ptr;
    } while (swapped);
  }

  void splitList(Node *head) {
    if (head == nullptr) {
      cout << "List is empty, cannot split." << endl;
      return;
    }
    
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
      current = current->next;
      count++;
    }

    int half = count / 2;

    current = head;
    Node *first = head;
    Node *second = nullptr;

    for (int i = 0; i < half - 1 && current != nullptr; i++) {
      current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
      second = current->next;
      current->next = nullptr;
    }

    cout << "First Half: ";
    bubbleSort(first);
    Node *temp = first;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Second Half: ";
    bubbleSort(second);
    temp = second;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList list;

  list.insertAtBeginning(10);
  list.insertAtEnd(20);
  list.insertBefore(list.getHead(), 5);
  list.insertAfter(list.getTail(), 25);

  cout << "List after insertions: ";
  list.display();

  cout << "List after reverse: ";
  list.displayRecursive(list.getHead());

  // Create a second list to merge
  LinkedList list2;
  list2.insertAtEnd(40);
  list2.insertAtEnd(50);

  cout << "Second list: ";
  list2.display();

  // Merge list and list2
  Node *mergedHead = list.mergeLists(list.getHead(), list2.getHead());

  cout << "Merged list: ";
  Node *temp = mergedHead;
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "Null" << endl;

  cout << "Split list: " << endl;
  list.splitList(list.getHead());

  return 0;
}