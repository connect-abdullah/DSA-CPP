#include <iostream>
using namespace std;

const int MAX_PATIENTS = 10;

struct Patient {
    int patientID;
    string name;
    string condition;
    int priority;
};

class EmergencyRoom {
private:
    Patient queue[MAX_PATIENTS];
    int count;

public:
    EmergencyRoom() {
        count = 0;
    }

    bool isFull() const {
        return count == MAX_PATIENTS;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void addPatient(int id, const string& name, const string& condition, int priority) {
        if (isFull()) {
            cout << "ER Full! Cannot admit new patient: " << name << endl;
            return;
        }

        Patient newPatient = {id, name, condition, priority};

        // According to priority
        int i = count - 1;
        while (i >= 0 && queue[i].priority > newPatient.priority) {
            queue[i + 1] = queue[i]; // shift right
            i--;
        }

        queue[i + 1] = newPatient;
        count++;

        cout << "Patient " << name << " (Priority " << priority << ") added.\n";
    }

    void treatPatient() {
        if (isEmpty()) {
            cout << "No patients to treat.\n";
            return;
        }

        cout << "Treating Patient: " << queue[0].name
             << " | Condition: " << queue[0].condition
             << " | Priority: " << queue[0].priority << endl;

        for (int i = 0; i < count - 1; i++) {
            queue[i] = queue[i + 1];
        }
        count--;
    }

    void displayAllPatients() const {
        if (isEmpty()) {
            cout << "No patients in queue.\n";
            return;
        }

        cout << "\n--- ER Waiting List (High → Low Priority) ---\n";
        for (int i = 0; i < count; i++) {
            cout << "ID: " << queue[i].patientID
                 << " | Name: " << queue[i].name
                 << " | Priority: " << queue[i].priority
                 << " | Condition: " << queue[i].condition << endl;
        }
    }
};

int main() {
    EmergencyRoom er;

    // Arrivals in order: 4, 1, 3, 2
    er.addPatient(101, "Ali", "Minor Injury", 4);
    er.addPatient(102, "Sara", "Heart Attack", 1);
    er.addPatient(103, "Ahmed", "Fracture", 3);
    er.addPatient(104, "Zain", "High Fever", 2);

    er.displayAllPatients();

    cout << "\n--- Treatment Sequence ---\n";
    while (!er.isEmpty()) {
        er.treatPatient();
    }

    return 0;
}
