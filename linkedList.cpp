#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
   // Create nodes dynamically
    Node* first = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};

    
    first->next = second;
    second->next = third;
    third->next = nullptr;
    
    cout << "The data of second after node first: " << first->next->next->data << endl;
    // first(next) [first->next] -> second(next) [next->next] -> third(data) [next->data]
    // first → [10 | addr_of_second] → [20 | addr_of_third] → [30 | nullptr]

    // Clean up dynamically allocated memory
    delete third;
    delete second;
    delete first;

    return 0;
}