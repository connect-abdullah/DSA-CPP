// Browser Navigation using Stack
#include <iostream>
#include <ctime>
using namespace std;

struct Node {
    string pageTitle;
    string URL;
    int timeVisited;
    Node* prev;
    Node* next;

    Node(string pageTitle, string URL ,int timeVisited): pageTitle(pageTitle), URL(URL), timeVisited(timeVisited), prev(nullptr), next(nullptr) {};
};

class BrowserNavigation {
    private: 
        Node* head;
        Node* tail;
        Node* temp;
        
    public:
    BrowserNavigation() {
        head = nullptr;
        tail = nullptr;
        temp = nullptr;
    }

    void visitPage(string pageTitle, string URL, int time) {
        Node* newNode = new Node(pageTitle, URL, time);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->next = newNode;
            newNode->prev = head;
            head = newNode;
        }
    }

    void goBack() {
        if (head == nullptr) {
            cout << "Navigation Stack is empty." << endl;
            return;
        }
        temp = head;
        head = head->prev;
        if(head != nullptr) {
            head->next = nullptr;
        } else {
            tail = nullptr;
        }
        
        if(head != nullptr) {
            cout << " ---- Going Back ----" << endl;
            cout << "Going back to: " << head->URL << endl;
        } else{
            cout << " ---- Going Back ----" << endl;
            cout << "No previous page." << endl;
        }
    }
    void goForward() {
        if (temp == nullptr) {
            cout << " ---- Going Back ----" << endl;
            cout << "No forward pages available." << endl;
            return;
        }
        head->next = temp;
        temp->prev = head;
        head = temp;
        cout << " ---- Going Forward ----" << endl;
        cout << "Going forward to: " << head->URL << endl;
    }

    void viewCurrentPage() {
        if (head == nullptr) {
            cout << "No current page to display." << endl;
            return;
        }
        cout << " ---- Current Page ----" << endl;
        cout << "Title: " << head->pageTitle << endl;
        cout << "URL: " << head->URL << endl;
        cout << "Time visited: " << head->timeVisited << endl;
    }

    void displayHistory() {
        Node* current = head;
        if (current == nullptr) {
            cout << "No browsing history." << endl;
            return;
        }
        cout << " ---- Browsing History ----" << endl;
        while (current != nullptr) {
            cout << "Title: " << current->pageTitle << ", URL: " << current->URL << endl;
            current = current->prev;
        }
    }
};

int main () {
    BrowserNavigation bn;

    // Geting time ( trying to get :) )
    int currentTime = time(0);

    bn.visitPage("Google", "https://www.google.com", currentTime);
    bn.visitPage("YouTube", "https://www.youtube.com", currentTime);
    bn.visitPage("GitHub", "https://github.com", currentTime);
    bn.visitPage("Wikipedia", "https://www.wikipedia.org", currentTime);

    bn.viewCurrentPage();
    bn.displayHistory();
    bn.goBack();
    bn.displayHistory();
    bn.goForward();
    bn.displayHistory();
    
    return 0;
}