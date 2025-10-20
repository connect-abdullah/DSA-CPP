// Return Management System using Stack
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum number of static array

struct ReturnRequest {
    int orderID;
    string customerName;
    string returnReason;
    string dateOfReq;
};

class ReturnSystem {
private:
    ReturnRequest stack[MAX_SIZE];
    int top;
public:
    ReturnSystem() : top(-1) {}

    void pushReturnReq(int orderID, string customerName, string returnReason, string dateOfReq) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow: Cannot add more return requests." << endl;
            return;
        }
        top++;
        stack[top].orderID = orderID;
        stack[top].customerName = customerName;
        stack[top].returnReason = returnReason;
        stack[top].dateOfReq = dateOfReq;
    }

    void popReturnReq() {
        if (top == -1) {
            cout << "No Requests in the stack." << endl;
            return;
        }
        cout << "This returnID is removed: " << stack[top].orderID << endl;
        top--;
    }

    void peekReturnReq() {
        if (top == -1) {
            cout << "No Requests in the stack." << endl;
            return;
        }
        cout << "This is the Last Return Request: " << stack[top].orderID << " By " << stack[top].customerName << endl;
    }

    void displayAllRequests() {
        if (top == -1) {
            cout << "No Requests in the stack." << endl;
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << stack[i].orderID << " -> ";
        }
        cout << "Null" << endl;
    }
};

int main () {
    ReturnSystem rms;

    rms.pushReturnReq(1, "Abdullah", "not good", "20/10/25");
    rms.pushReturnReq(101, "Abbas", "damaged item", "2024/06/01");
    rms.pushReturnReq(102, "Hashim", "wrong size", "2024/06/02");
    rms.pushReturnReq(103, "Kiran", "late delivery", "2024/06/03");

    rms.displayAllRequests();
    rms.popReturnReq();
    rms.displayAllRequests();
    rms.peekReturnReq();

    return 0;
}