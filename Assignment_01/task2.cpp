#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data, Node *nextPtr = nullptr) : data(data), next(nextPtr) {}
};

class LinkedList {
public:
  Node *head;
  Node *firstHalf;
  Node *secondHalf;
  LinkedList(Node *headPtr = nullptr) : head(headPtr) {}

  void insert(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  Node *splitList(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    int half = count / 2;
    secondHalf = head;
    for (int i = 0; i < half; i++) {
      secondHalf = secondHalf->next;
    }
    current = head;
    firstHalf = current;
    for (int i = 0; i < half - 1; i++) {
      current = current->next;
    }
    current->next = nullptr;
    return (count == 0) ? nullptr : secondHalf;

    // Node* slow = head;
    // Node* fast = head;
    // while (fast != nullptr && fast->next != nullptr){
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }
    // Node* secondHalf = slow->next; // fast will be at the end of the list, so
    // slow will be at the middle. Therefore second half will start after the
    // middle one, so we are assigning to slow->next. slow->next = nullptr; //
    // and in the middle, we are assigning the mid one's next to nullptr, so
    // that it becomes the tail of the first half. return secondHalf;  // Return
    // the second half of the list
  }

  void displayFirstHalf() {
    Node *current = firstHalf;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
  }


// Bubble sorting
//   Node *curr = head 
//   while (curr->next != nullptr) {
//     Node *index = curr->next;
//     while (index != nullptr) {
//       if (curr->data > index->data) {
//         int temp = curr->data;
//         curr->data = index->data;
//         index->data = temp
//       }
//       index = index->data;
//     }
//     curr = curr->next
//   }

  void displaySecondHalf() {
    Node *current = secondHalf;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
  }

  void displaySortedDescending(Node *head) {
    Node *sorted = nullptr;
    Node *current = head;
    while (current != nullptr) {
      // Insert current->data into the sorted list in descending order
      Node *newNode = new Node(current->data);
      if (sorted == nullptr || newNode->data > sorted->data) {
        newNode->next = sorted;
        sorted = newNode;
      } else {
        Node *temp = sorted;
        while (temp->next != nullptr && temp->next->data > newNode->data) {
          temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
      }
      current = current->next;
    }
    // Print the sorted list
    Node *temp = sorted;
    while (temp != nullptr) {
      cout << temp->data << " ";
      Node *toDelete = temp;
      temp = temp->next;
      delete toDelete;
    }
  }

  void displayList() {
    Node *current = head;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
  }
};

int main() {
  LinkedList list;
  list.insert(5);
  list.insert(5);
  list.insert(3);
  list.insert(8);
  list.insert(1);
  list.insert(4);
  // Display the original list
  cout << "Original list: ";
  list.displayList();
  cout << endl;

  // Split the list into two halves
  Node *secondHalf = list.splitList(list.head);

  // Display the first half
  cout << "First half: ";
  list.displayFirstHalf();
  cout << endl;

  // Display the second half
  cout << "Second half: ";
  list.displaySecondHalf();
  cout << endl;

  // Display the first half sorted
  cout << "First half sorted: ";
  list.displaySortedDescending(list.firstHalf);
  cout << endl;

  // Display the second half sorted
  cout << "Second half sorted: ";
  list.displaySortedDescending(list.secondHalf);
  cout << endl;

  return 0;
}