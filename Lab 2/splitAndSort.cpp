#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value, Node *nextPtr = nullptr) : data(value), next(nextPtr) {};
};

class LinkedList {
  void splitList(Node *head) {
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

    for (int j = 0; j < half - 1 && current->next != nullptr; j++) {
      current = current->next;
    }

    if (current->next != nullptr && current != nullptr) {
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

  void bubbleSort(Node *head) {
    if (head == nullptr || !head) {
      return;
    }
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
  };
};