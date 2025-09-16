// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };
// Node* head = nullptr;
// Node* first = new Node{10, nullptr};
// Node* second = new Node{20, nullptr};
// Node* third = new Node{30, nullptr};
// Node* tail = nullptr;

// int main() {
//    // Create nodes dynamically
    
    
//     first->next = second;
//     second->next = third;
//     third->next = nullptr;
    
//     cout << "The data of second after node first: " << first->next->next->data << endl;
//     // first(next) [first->next] -> second(next) [next->next] -> third(data) [next->data]
//     // first → [10 | addr_of_second] → [20 | addr_of_third] → [30 | nullptr]

//     // Clean up dynamically allocated memory
//     delete third;
//     delete second;
//     delete first;

//     return 0;
// }



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
}

class LinkedList {
    private: 
        Node* head;
        Node* tail;

    public: 
        // Constructor so that at the start, head & tails are null
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        // Clean up after destroying the object
        ~LinkedList() {
            Node* current = head;
            while(current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }

    void insertAtStart(int value) {
        Node* newNode = new Node(value, head);
        head = newNode;
        if(tail == nullptr) {
            tail = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value,nullptr);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(Node* prev, int value) {
        if(prev == nullptr) return;
        Node* newNode = new Node(value,prev->value);
        prev->value = newNode
        if(prev == tail) tail = newNode;
    }

    void deleteFromStart(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if(head == nullptr) tail == nullptr;
    }

    void deleteFromEnd() {
        if(head == nullptr) return;
        if(head == tail) { // If only one node available
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* current = head;
        while(current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr
    }

    void deleteAfter(Node* prev) {
        if(prev == nullptr || prev->next == nullptr) return;
        Node* target = prev->next;
        prev->next = target->next;
        if(target == tail) tail== prev;
        delete target
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
}

int main() {
    LinkedList list;

    list.insertAtEnd(10);       // list: 10
    list.insertAtEnd(20);       // list: 10 -> 20
    list.insertAtBeginning(5);  // list: 5 -> 10 -> 20
    list.insertAtEnd(30);       // list: 5 -> 10 -> 20 -> 30

    cout << "List after insertions: ";
    list.display();

    list.deleteFromBeginning(); // list: 10 -> 20 -> 30
    list.deleteFromEnd();       // list: 10 -> 20

    cout << "List after deletions: ";
    list.display();

    return 0;
}
