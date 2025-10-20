#include <iostream>
using namespace std;

const int MAX_SEATS = 5;

struct Passenger {
    string name;
    string category;
    int seatNumber;
};

class TrainReservation {
private:
    Passenger queue[MAX_SEATS];
    int front;
    int rear;
    int count;

public:
    TrainReservation() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() const {
        return count == MAX_SEATS;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void bookAtFront(const string& name, const string& category) {
        if (isFull()) {
            cout << "Reservation Full! Cannot add passenger: " << name << endl;
            return;
        }

        // Move front backward circularly
        front = (front - 1 + MAX_SEATS) % MAX_SEATS;
        queue[front].name = name;
        queue[front].category = category;
        queue[front].seatNumber = front + 1;
        count++;

        cout << "Passenger " << name << " booked at seat " << queue[front].seatNumber << endl;
    }

    void bookAtRear(const string& name, const string& category) {
        if (isFull()) {
            cout << "Reservation Full! Cannot add passenger: " << name << endl;
            return;
        }

        // Move rear forward circularly
        rear = (rear + 1) % MAX_SEATS;
        queue[rear].name = name;
        queue[rear].category = category;
        queue[rear].seatNumber = rear + 1;
        count++;

        cout << "Passenger " << name << " booked at seat " << queue[rear].seatNumber << endl;
    }

    void cancelFromFront() {
        if (isEmpty()) {
            cout << "No reservations to cancel from front.\n";
            return;
        }

        cout << "Cancelled reservation of " << queue[front].name
             << " (Seat " << queue[front].seatNumber << ")" << endl;

        front = (front + 1) % MAX_SEATS;
        count--;
    }

    void cancelFromRear() {
        if (isEmpty()) {
            cout << "No reservations to cancel from rear.\n";
            return;
        }

        cout << "Cancelled reservation of " << queue[rear].name
             << " (Seat " << queue[rear].seatNumber << ")" << endl;

        rear = (rear - 1 + MAX_SEATS) % MAX_SEATS;
        count--;
    }

    void displayAllReservations() const {
        if (isEmpty()) {
            cout << "No reservations.\n";
            return;
        }

        cout << "\n--- Train Reservation List ---\n";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SEATS;
            cout << "Seat " << queue[index].seatNumber
                 << " -> " << queue[index].name
                 << " (" << queue[index].category << ")\n";
        }
        cout << "-------------------------------\n";
    }
};

int main() {
    TrainReservation tr;

    tr.bookAtRear("Ali", "Regular");
    tr.bookAtRear("Ahmed", "Regular");
    tr.bookAtFront("Sara", "VIP");
    tr.bookAtRear("Zain", "Regular");
    tr.bookAtFront("Maryam", "VIP");

    tr.displayAllReservations();

    cout << "\n--- Cancelling One from Front and One from Rear ---\n";
    tr.cancelFromFront();
    tr.cancelFromRear();

    tr.displayAllReservations();

    cout << "\n--- Adding New Bookings ---\n";
    tr.bookAtFront("Hassan", "VIP");
    tr.bookAtRear("Usman", "Regular");

    tr.displayAllReservations();

    return 0;
}
