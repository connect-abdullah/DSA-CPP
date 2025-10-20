#include <iostream>
using namespace std;

const int MAX_SLOTS = 5;

struct Car {
    string carNumber;
    int slotNumber;
};

class ParkingLot {
private:
    Car parkingLot[MAX_SLOTS];
    int front;
    int rear;
    int count;
public:
    ParkingLot() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() const {
        return count == MAX_SLOTS;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void parkCar(const string& carNumber) {
        if (isFull()) {
            cout << "Parking Lot Full! Cannot park " << carNumber << endl;
            return;
        }
        rear = (rear + 1) % MAX_SLOTS;
        parkingLot[rear].carNumber = carNumber;
        parkingLot[rear].slotNumber = rear + 1;
        count++;
        cout << "Car " << carNumber << " parked at slot " << parkingLot[rear].slotNumber << endl;
    }

    void removeCar() {
        if (isEmpty()) {
            cout << "No cars to remove.\n";
            return;
        }
        cout << "Car " << parkingLot[front].carNumber
             << " leaving from slot " << parkingLot[front].slotNumber << endl;
        front = (front + 1) % MAX_SLOTS;
        count--;
    }

    void displayParkingStatus() const {
        if (isEmpty()) {
            cout << "Parking lot empty.\n";
            return;
        }
        cout << "\n--- Parking Lot Status ---\n";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SLOTS;
            cout << "Slot " << parkingLot[index].slotNumber
                 << " -> Car: " << parkingLot[index].carNumber << endl;
        }
        cout << "---------------------------\n";
    }
};

int main() {
    ParkingLot pl;
    pl.parkCar("ABC-123");
    pl.parkCar("XYZ-789");
    pl.parkCar("LMN-456");
    pl.parkCar("JKL-999");
    pl.parkCar("QWE-222");
    pl.parkCar("QTY-123");

    pl.displayParkingStatus();

    cout << "\n--- Removing Two Cars ---\n";
    pl.removeCar();
    pl.removeCar();
    pl.displayParkingStatus();

    cout << "\n--- Parking New Cars ---\n";
    pl.parkCar("TUV-333");
    pl.parkCar("RTY-444");
    pl.displayParkingStatus();

    return 0;
}