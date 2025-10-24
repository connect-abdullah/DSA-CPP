#include <iostream>
#include <string>
using namespace std;

struct Stop {
    int id;
    string name;
    int distanceToNext;
    Stop* next;

    Stop(int _id, string _name, int _distance)
        : id(_id), name(_name), distanceToNext(_distance), next(nullptr) {}
};

class ShuttleService {
private:
    Stop* head; 

public:
    ShuttleService() : head(nullptr) {}

    void addStopAtEnd(int id, string name, int distance) {
        Stop* newStop = new Stop(id, name, distance);
        if (!head) {
            head = newStop;
            head->next = head; 
        } else {
            Stop* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newStop;
            newStop->next = head;
        }
    }

    void addStopAfter(int id, int newId, string newName, int distance) {
        if (!head) {
            cout << "Route is empty!\n";
            return;
        }

        Stop* temp = head;
        do {
            if (temp->id == id) {
                Stop* newStop = new Stop(newId, newName, distance);
                newStop->next = temp->next;
                temp->next = newStop;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Stop with ID " << id << " not found!\n";
    }

    void removeStop(int id) {
        if (!head) {
            cout << "Route is empty!\n";
            return;
        }

        Stop* curr = head;
        Stop* prev = nullptr;

        // special case: deleting head
        while (curr->id != id && curr->next != head) {
            prev = curr;
            curr = curr->next;
        }

        if (curr->id != id) {
            cout << "Stop with ID " << id << " not found!\n";
            return;
        }

        if (curr == head && curr->next == head) {
            // only one node
            delete head;
            head = nullptr;
        } else if (curr == head) {
            Stop* last = head;
            while (last->next != head) last = last->next;
            head = head->next;
            last->next = head;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    void displayRoute() {
        if (!head) {
            cout << "Route is empty!\n";
            return;
        }

        Stop* temp = head;
        do {
            cout << "[" << temp->id << ", " << temp->name
                 << ", " << temp->distanceToNext << "km] → ";
            temp = temp->next;
        } while (temp != head);

        cout << "back to " << head->name << "\n";
    }

    void findLongestDistance() {
        if (!head) {
            cout << "Route is empty!\n";
            return;
        }

        Stop* temp = head;
        Stop* maxStop = head;
        int maxDist = head->distanceToNext;

        do {
            if (temp->distanceToNext > maxDist) {
                maxDist = temp->distanceToNext;
                maxStop = temp;
            }
            temp = temp->next;
        } while (temp != head);

        cout << maxStop->name << " has the longest distance (" 
             << maxDist << " km) to next stop.\n";
    }
};


int main() {
    ShuttleService service;

    // Initial route
    service.addStopAtEnd(1, "Main Gate", 2);
    service.addStopAtEnd(2, "Roller Coaster", 3);
    service.addStopAtEnd(3, "Water Park", 5);

    cout << "Initial route:\n";
    service.displayRoute();

    // Add stop at end
    service.addStopAtEnd(4, "Zoo", 4);
    cout << "\nAfter addStopAtEnd(4, Zoo, 4):\n";
    service.displayRoute();

    // Find longest distance
    cout << "\nAfter findLongestDistance():\n";
    service.findLongestDistance();

    // Remove stop
    service.removeStop(2);
    cout << "\nAfter removeStop(2):\n";
    service.displayRoute();

    // Add after Water Park
    service.addStopAfter(3, 5, "Food Court", 6);
    cout << "\nAfter addStopAfter(3, Food Court, 6):\n";
    service.displayRoute();

    return 0;
}