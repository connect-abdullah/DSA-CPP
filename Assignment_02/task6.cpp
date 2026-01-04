// Hospital Management System Using Queue
#include <iostream>
using namespace std;

struct Node {
  int patientID;
  string patientName;
  string doctorName;
  string appointmentTime;
  Node *prev;
  Node *next;

  Node(int patientID, string patientName, string doctorName,
       string appointmentTime)
      : patientID(patientID), patientName(patientName), doctorName(doctorName),
        appointmentTime(appointmentTime), prev(nullptr), next(nullptr) {};
};

class HospitalManagementSystem {
private:
  Node *head;
  Node *tail;

public:
  HospitalManagementSystem() {
    head = nullptr;
    tail = nullptr;
  }

  void addPatient(int patientID, string patientName, string doctorName,
                  string appointmentTime) {
    Node *newNode =
        new Node(patientID, patientName, doctorName, appointmentTime);
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode; // link new node at the end
      newNode->prev = tail; // previous of new node is old tail
      tail = newNode;       // update tail
    }
  }

  void callNextPatient() {
    if (head == nullptr) {
      cout << "Patient Queue is empty." << endl;
      return;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }

    cout << " ---- Next Patient ----" << endl;
    cout << "Next Patient is: " << head->patientName << endl;

    delete temp;
  }

  void displayAllAppointments() {
    Node *current = head;
    if (current == nullptr) {
      cout << "No appointments." << endl;
      return;
    }
    cout << " ---- All Appointments ----" << endl;
    while (current != nullptr) {
      cout << "Patient ID: " << current->patientID
           << ", Doctor: " << current->doctorName
           << ", Patient Name: " << current->patientName
           << ", Appointment Time: " << current->appointmentTime << endl;
      current = current->next;
    }
  }
};

int main() {
  HospitalManagementSystem hms;

  hms.addPatient(1, "John Doe", "Dr. Smith", "09:00 AM");
  hms.addPatient(2, "Jane Doe", "Dr. Adams", "09:30 AM");
  hms.addPatient(3, "Alice Brown", "Dr. Miller", "10:00 AM");
  hms.addPatient(4, "Bob Green", "Dr. Lee", "10:30 AM");

  hms.displayAllAppointments();
  hms.callNextPatient();
  hms.displayAllAppointments();
  hms.callNextPatient();
  hms.displayAllAppointments();
  hms.callNextPatient();

  return 0;
}