#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int tabID;
    string websiteTitle;
    string url;
    Node* next;
    Node(int tabID, string websiteTitle, string url, Node* prevPtr = nullptr, Node* nextPtr = nullptr)
        : prev(prevPtr), tabID(tabID), websiteTitle(websiteTitle), url(url), next(nextPtr) {}
};

class BrowserTabManager {
private:
    Node* head;
    Node* tail;
    Node* currentTab;

public:
    BrowserTabManager() : head(nullptr), tail(nullptr), currentTab(nullptr) {}

    void openTab(int tabID, string websiteTitle, string url) {
        Node* newNode = new Node(tabID, websiteTitle, url, tail, nullptr);
        if (!head) {
            head = tail = newNode;
            currentTab = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Opened new tab: [" << tabID << "] " << websiteTitle << endl;
    }

    void closeTabByID(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->tabID == id) {
                // Reconnect neighbors
                if (temp->prev) temp->prev->next = temp->next; // if the tab has a previous tab, we need to link the previous tab to the next tab
                else head = temp->next; // if the tab is the head, we need to link the head to the next tab, because head prev is nullptr.
    
                if (temp->next) temp->next->prev = temp->prev; // if the tab has a next tab, we need to link the next tab to the previous tab
                else tail = temp->prev; // if the tab is the tail, we need to link the tail to the previous tab, because tail next is nullptr.
    
                // Adjust current tab
                if (currentTab == temp)
                    currentTab = head ? head : nullptr;
    
                cout << "Closed tab: [" << temp->tabID << "] " << temp->websiteTitle << endl;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Tab with ID " << id << " not found." << endl;
    }
    
    void switchTab(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->tabID == id) {
                currentTab = temp;
                cout << "Switched to tab: [" << temp->tabID << "] " << temp->websiteTitle << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Tab with ID " << id << " not found.\n";
    }

    // Forward order.
    void displayTabsForward() {
        Node* temp = head;
        cout << "-----Tabs (forward):-----\n";
        while (temp) {
            if (temp == currentTab)
                cout << "-> ";
            cout << "[" << temp->tabID << "] " << temp->websiteTitle << endl;
            temp = temp->next;
        }
    }

    // Reverse order.
    void displayTabsReverse() {
        Node* temp = tail;
        cout << "-----Tabs (reverse):-----\n";
        while (temp) {
            if (temp == currentTab)
                cout << "-> ";
            cout << "[" << temp->tabID << "] " << temp->websiteTitle <<endl;
            temp = temp->prev;
        }
    }
};

int main(){
    BrowserTabManager browser;
    cout << "-----Opening Tabs:-----\n";
    browser.openTab(1, "Google", "https://www.google.com");
    browser.openTab(2, "Facebook", "https://www.facebook.com");
    browser.openTab(3, "Twitter", "https://www.twitter.com");
    cout << "-----Displaying Tabs:-----\n";
    browser.displayTabsForward();
    browser.displayTabsReverse();
    cout << "-----Closing Tab:-----\n";
    browser.closeTabByID(1);
    cout << "-----Displaying Tabs:-----\n";
    browser.displayTabsForward();
    cout << "-----Switching Tab:-----\n";
    browser.switchTab(3);
    cout << "-----Displaying Tabs:-----\n";
    browser.displayTabsForward();
    return 0;
}