#include <iostream>
using namespace std;

class Node {
    public:
    string data;
    Node* next;
    Node(string data, Node* nextPtr = nullptr) : data(data), next(nextPtr) {}
};

class CircularList{
    public: 
    Node* head;
    Node* tail;
    Node* cursor;
    CircularList(Node* headPtr = nullptr, Node* tailPtr = nullptr, Node* cursorPtr = nullptr) : head(headPtr), tail(tailPtr), cursor(cursorPtr) {}

    void insert(string data){
        Node* newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
            tail->next = head;
            cursor = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        cout << "Inserted " << data << " at the end of the list.\n";
    }

    void undo(){
        Node* current = head;
        while (current->next->next != head){
            current = current->next;
        }
        Node* temp = current->next; // 9 - 10 - 1, temp = 10
        current->next = current->next->next; // 9 - 1, current = 9, current->next = 1 (head)
        if (current->next == head){
            tail = current;
            tail->next = head;
        }
        delete temp;
        cout << "Deleted Last Word" << temp->data << " from the list.\n";
        display();
    }
   
    void find_and_replace(string data, string newData){
        Node* current = head;
        while (current->next->data != data){
            current = current->next;
        }
        current->next->data = newData;
        cout << "Replaced " << data << " with " << newData << " in the list.\n";
        display();
    }

    void countWords(){
        Node* current = head;
        int count = 0;
        do {
            count++;
            current = current->next;
        } while (current != head);
        cout << "There are " << count << " words in the list.\n";
    }
    
    void gotoNext() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cursor = (cursor == nullptr) ? head : cursor->next;
        cout << "Cursor moved to: " << cursor->data << endl;
        display();
    }
    
    void display() {
        if (!head) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        do {
            if (temp == cursor) cout << "[" << temp->data << "] "; // mark cursor
            else cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

};

void printMenu() {
    cout << "\nText Editor - Circular Linked List\n";
    cout << "-----------------------------------\n";
    cout << "Select an operation:\n";
    cout << "1. Insert word\n";
    cout << "2. Undo (delete last word)\n";
    cout << "3. Find and replace\n";
    cout << "4. Count words\n";
    cout << "5. Move cursor to next word\n";
    cout << "6. Display text\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CircularList list;
    int choice;
    string word, newWord;

    do {
        printMenu();
        cin >> choice;
        cin.ignore(); // To clear newline from input buffer

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                getline(cin, word);
                list.insert(word);
                break;
            case 2:
                list.undo();
                break;
            case 3:
                cout << "Enter word to find: ";
                getline(cin, word);
                cout << "Enter new word to replace with: ";
                getline(cin, newWord);
                list.find_and_replace(word, newWord);
                break;
            case 4:
                list.countWords();
                break;
            case 5:
                list.gotoNext();
                break;
            case 6:
                list.display();
                break;
            case 0:
                cout << "Exiting editor.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}