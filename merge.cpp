#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value, Node* nextPtr = nullptr) : data(value), next(nextPtr) {};
};

Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = nullptr;
    Node* tail = nullptr;

    // pick the first node
    if (a->data <= b->data) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next;
    }

    // merge rest
    while (a && b) {
        Node* nextNode = nullptr;

        if (a->data <= b->data) {
            nextNode = a;
            a = a->next;
        } else {
            nextNode = b;
            b = b->next;
        }

        tail->next = nextNode;
        tail = nextNode;
    }

    // attach leftover
    tail->next = (a) ? a : b;

    return head;
}


int main() {
    Node* a = nullptr;
    Node* b = nullptr;

    a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);

    b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);

    Node* merged = mergeLists(a, b);

    while (merged != nullptr) {
        cout << merged->data << " -> ";
        merged = merged->next;
    }
    cout << "NULL" << endl;

    return 0;
}