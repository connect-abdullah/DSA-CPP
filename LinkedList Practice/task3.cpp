#include <iostream>
using namespace std;

struct singleNode {
    int data;
    singleNode *next;
  
    singleNode(int value, singleNode *nextPtr = nullptr)
        : data(value), next(nextPtr) {};
  };

struct doubleNode {
  int data;
  doubleNode *prev;
  doubleNode *next;

  doubleNode(int value, doubleNode *prevPtr = nullptr, doubleNode *nextPtr = nullptr)
      : data(value), prev(prevPtr), next(nextPtr) {};
};

class singleLinkedList {
public:
  singleNode *head;
  singleNode *tail;

  singleLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void insert(int data) {
    singleNode *newNode = new singleNode(data, nullptr);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode; // Current tail's next points to new node
      tail = newNode;       // Update tail to newNode
    }
  }

  singleNode* getHead() {
    return head;
  }
  void display() {
    singleNode *current = head;
    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "NULL" << endl;
  }
};

class doubleLinkedList {
    public:
      doubleNode *head;
      doubleNode *tail;
    
      doubleLinkedList() {
        head = nullptr;
        tail = nullptr;
      }
    
      void insert(int data) {
        doubleNode *newNode = new doubleNode(data, nullptr,nullptr);
        if (head == nullptr) {
          head = newNode;
          tail = newNode;
        } else {
          tail->next = newNode; // Current tail's next points to new node
          tail = newNode;       // Update tail to newNode
        }
      }

      void convertSingleList(singleNode* head){
        singleNode* current = head;
        doubleNode* prev = nullptr;
        while(current != nullptr) {
            doubleNode* newNode = new doubleNode(current->data, prev, nullptr);
            if (prev == nullptr) {
                // First node, set as head
                this->head = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            current = current->next;
        }
        this->tail = prev;
      }
    
      // running in reverse so we know it is done correctly
      void display() {
        doubleNode *current = tail;
        while (current != nullptr) {
          cout << current->data << " -> ";
          current = current->prev;
        }
        cout << "NULL" << endl;
      }
    };
int main() {
singleLinkedList singleList;
doubleLinkedList doubleList;
  singleList.insert(10);
  singleList.insert(20);
  singleList.insert(30);
  singleList.insert(40);


  singleList.display();

  doubleList.convertSingleList(singleList.getHead());
  doubleList.display();

  return 0;
}