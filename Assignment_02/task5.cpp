#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

struct Passenger {
    string passengerName;
    string destination;
    string ticketType;
};

class AirportManagementSystem {
private:
    Passenger queue[MAX_SIZE];
    int front; // front element (1,2,4,5), it points to 1 because 1 came first. FIFO
    int rear;  // last element

public:
    AirportManagementSystem() : front(-1), rear(-1) {}

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueuePassenger(string passengerName, string destination, string ticketType) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot add more passengers.\n";
            return;
        }

        if (front == -1) front = 0;

        rear++;
        queue[rear].passengerName = passengerName;
        queue[rear].destination = destination;
        queue[rear].ticketType = ticketType;

        cout << "Passenger Enqueued: " << passengerName << endl;
    }

    void dequeuePassenger() {
        if (isEmpty()) {
            cout << "No Passengers in the queue.\n";
            return;
        }

        cout << "Passenger Dequeued: " << queue[front].passengerName << endl;
        front++;

        if (front > rear) {
            front = rear = -1; // reset queue when empty
        }
    }

    void peekReturnReq() {
        if (isEmpty()) {
            cout << "No Passengers in the queue.\n";
            return;
        }
        cout << "Next Passenger in Line: " << queue[front].passengerName
             << " → " << queue[front].destination << endl;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No Requests in the queue.\n";
            return;
        }

        cout << "---- Current Queue ----\n";
        for (int i = front; i <= rear; i++) {
            cout << i + 1 << ". " << queue[i].passengerName
                 << " → " << queue[i].destination
                 << " (" << queue[i].ticketType << ")\n";
        }
    }
};

int main() {
    AirportManagementSystem ams;

    ams.enqueuePassenger("John", "New York", "VIP");
    ams.enqueuePassenger("Jane", "Los Angeles", "Regular");
    ams.enqueuePassenger("Jim", "Chicago", "VIP");
    ams.enqueuePassenger("Jill", "Houston", "Regular");
    ams.enqueuePassenger("Jack", "Miami", "VIP");

    cout << endl;
    ams.displayQueue();

    cout << endl;
    ams.dequeuePassenger();

    cout << endl;
    ams.displayQueue();

    cout << endl;
    ams.peekReturnReq();

    return 0;
}
