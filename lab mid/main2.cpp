#include <iostream>
using namespace std;

struct Stop {
  string name;
  int distance;
  Stop *next;
  Stop *prev;

  Stop(string name, int distance)
      : name(name), distance(distance), next(nullptr), prev(nullptr) {};
};

class themePark {
private:
  Stop *head;
  Stop *tail;
public:
  // Constructor
  themePark() {
    head = nullptr;
    tail = nullptr;
  };

  void addStop(string name, int distance) {
    Stop *newStop = new Stop(name, distance);

    if (!head) {
      head = tail = newStop;
    } else {
      tail->next = newStop;
      newStop->prev = tail;
      tail = newStop;
      tail->next = head;
      head->prev = tail;
    }
  }

  Stop* findLargestGap() {
    if (!head)
      return nullptr;
    // finding it the way we find max Number in array.
    Stop *temp = head;
    Stop *maxStop = head;
    int maxDistance = head->distance; // to keep maxDistance stable through the loop

    do {
      if (temp->distance > maxDistance) {
        maxDistance = temp->distance;
        maxStop = temp;
      }
      temp = temp->next;
    } while (temp != head);
    return maxStop;
  }

  void insertNewStop(string newName) {
    if(!head) return;
    Stop* largestGapStop = findLargestGap();
    Stop* nodeBehindLargeStop = largestGapStop->prev;

    // taking the distance of the largest one and making it half so it can come in between the largest and the it's previous one
    int originalDistance = largestGapStop->distance;
    int halfDistance = originalDistance/2;

    Stop* newStop = new Stop(newName, halfDistance);
    newStop->prev = nodeBehindLargeStop; // new Node's previous becomes the previous of the largestGapStop
    newStop->next = largestGapStop; // new Node's next becomes largestGapStop
    largestGapStop->prev = newStop; // largestGapStop prev becomes new Node, as new Node next is largestGapStop, connecting in both ways.
    nodeBehindLargeStop->next = newStop; // nodeBehindLargeStop next becomes new Node, as new Node prev is nodeBehindLargeStop, connecting in both ways.

    cout << "New Stop Added:" << newStop->name << endl;
  }

  void displayRoutes() {
    if (!head)
      return;

    Stop* current = head;
    do {
      cout << current->name << "{ " << current->distance << " }" ;
      if(current->next != head){
        cout << " -> ";
      }
      current = current->next;
    } while (current != head) ;
    cout << endl;
  }
};

int main() {
  themePark tp;

  tp.addStop("Main Gate", 50);
  tp.addStop("Water Park", 100);
  tp.addStop("Food Court", 250);
  tp.addStop("Zoo", 150);
  tp.addStop("Main Gate", 200);

  tp.displayRoutes();
  cout << tp.findLargestGap()->name << endl; // food court : 250
  tp.insertNewStop("Rest Area");
  tp.displayRoutes();


};