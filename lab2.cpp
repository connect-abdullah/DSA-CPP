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

  void reverseAndDisplay() {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    // Reverse the list
    while (current != nullptr) {
      next = current->next; // store next node
      current->next = prev; // reverse the link
      prev = current;       // move prev forward
      current = next;       // move current forward
    }

    head = prev; // update head to new first node

    // Display the reversed list
    current = head;
    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
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

  // Release ownership of all nodes without deleting them
  void releaseOwnership() {
    head = nullptr;
    tail = nullptr;
  }

  Node *mergeLists(Node *list1, Node *list2) {
    // if list1 is empty, merged list is just list2
    if (list1 == nullptr) {
      return list2;
    }
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
    int index = 1; // position tracker
    int count = 0; // how many times found

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

  void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    Node* ptr;
    Node* lptr = nullptr;  // last sorted element

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                // swap values (simpler than swapping nodes)
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;  // shrink last boundary
    } while (swapped);
}


  void splitLink(Node *head) {
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

    for (int j = 0; j < half - 1 && current != nullptr; j++) {
      current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
      second = current->next;   
      current->next = nullptr; 
    }

    cout << "First half: ";
    bubbleSort(first);
    Node *temp = first;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Second half: ";
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

  list.insertAtEnd(10);      // list: 10
  list.insertAtEnd(20);      // list: 10 -> 20
  list.insertAtBeginning(5); // list: 5 -> 10 -> 20
  list.insertAtEnd(30);      // list: 5 -> 10 -> 20 -> 30

  cout << "List after insertions: ";
  list.display();

  cout << "List after reverse: ";
  list.displayReverse();

  cout << "reverseAndDisplay: ";
  list.reverseAndDisplay();

  cout << "List Recursively: ";
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
  list.splitLink(list.getHead());
  // Clear list2's ownership to prevent double-delete
  // Since list2's nodes are now part of list, we need to prevent list2's
  // destructor from deleting them
  list2.releaseOwnership();

  return 0;
}
