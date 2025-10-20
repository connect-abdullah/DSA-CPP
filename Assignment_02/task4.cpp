#include <iostream>
using namespace std;

struct Node {
  string boxNumber;
  int boxWeight;
  Node *prev;
  Node(string num, int wt) : boxNumber(num), boxWeight(wt), prev(nullptr) {}
};

class LogisticsSystem {
private:
  Node *top;

public:
  LogisticsSystem() : top(nullptr) {}

  void placeBox(string boxNumber, int boxWeight) {
    Node *newNode = new Node(boxNumber, boxWeight);

    // Popping until we find a heavier or equal box
    while (top != nullptr && boxWeight > top->boxWeight) {
      Node *temp = top;
      top = top->prev;
      delete temp;
    }

    newNode->prev = top;
    top = newNode;
  }

  void displayBoxList() {
    if (top == nullptr) {
      cout << "No boxes in the system.\n";
      return;
    }

    cout << "---- Stack from Top (lightest) to Bottom (heaviest) ----\n";
    Node *current = top;
    while (current != nullptr) {
      cout << "Box Number: " << current->boxNumber
           << ", Box Weight: " << current->boxWeight << endl;
      current = current->prev;
    }
  }
};

int main() {
  LogisticsSystem ls;

  ls.placeBox("B101", 50);
  ls.placeBox("B102", 40);
  ls.placeBox("B103", 35);
  ls.placeBox("B104", 25);
  ls.placeBox("B105", 5);
  ls.placeBox("B106",36);

  ls.displayBoxList();
  return 0;
}
