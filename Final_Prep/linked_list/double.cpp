#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end (O(1))
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insert after a given node (O(1))
    void insertAfter(Node* node, int value) {
        if (!node) return;

        Node* newNode = new Node(value);
        newNode->next = node->next;
        newNode->prev = node;

        if (node->next)
            node->next->prev = newNode;
        else
            tail = newNode;

        node->next = newNode;
    }

    // Delete from beginning (O(1))
    void deleteFromBeginning() {
        if (!head) return;

        Node* temp = head;
        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    // Delete from end (O(1))
    void deleteFromEnd() {
        if (!tail) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }

    // Delete a given node (O(1))
    void deleteNode(Node* node) {
        if (!node) return;

        if (node == head)
            deleteFromBeginning();
        else if (node == tail)
            deleteFromEnd();
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
    }

    // Display forward
    void displayForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward() {
        Node* current = tail;
        while (current) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL\n";
    }

    // Reverse list (simple swap)
    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp)
            head = temp->prev;

        swap(head, tail);
    }

    Node* getHead() { return head; }
    Node* getTail() { return tail; }
};

int main() {
    DoublyLinkedList dll;

    // Insert at end
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    // Insert at beginning
    dll.insertAtBeginning(5);

    // Display forward
    cout << "List forward: ";
    dll.displayForward();

    // Display backward
    cout << "List backward: ";
    dll.displayBackward();

    // Delete from beginning
    dll.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    dll.displayForward();

    // Delete from end
    dll.deleteFromEnd();
    cout << "After deleting from end: ";
    dll.displayForward();

    // Insert after second node (with data 10)
    Node* secondNode = dll.getHead()->next;
    if(secondNode)
        dll.insertAfter(secondNode, 15);

    cout << "After inserting 15 after second node: ";
    dll.displayForward();

    // Reverse the list
    dll.reverse();
    cout << "After reversal: ";
    dll.displayForward();

    return 0;
}
