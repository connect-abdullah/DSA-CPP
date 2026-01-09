#include <iostream>
using namespace std;

const int MAX = 10;

struct Order {
  int orderID;
  string restaurant;
  string customer;
  string items;
  int prepTime;
  string orderTime;
};

class DeliveryQueue {
private:
  Order queue[MAX];
  int front, rear, count;

public:
  DeliveryQueue() {
    front = 0;
    rear = -1;
    count = 0;
  }

  bool isFull() { return count == MAX; }

  bool isEmpty() { return count == 0; }

  void addOrder(int id, string rest, string cust, string items, int prep,
                string time) {
    if (isFull()) {
      cout << "Queue is full. Cannot add more orders.\n";
      return;
    }

    Order o = {id, rest, cust, items, prep, time};

    // quick order -> add at front, else at rear
    if (prep <= 10) {
      front = (front - 1 + MAX) % MAX;
      queue[front] = o;
    } else {
      rear = (rear + 1) % MAX;
      queue[rear] = o;
    }
    count++;
    cout << "Order " << id << " added (" << (prep <= 10 ? "Quick" : "Normal")
         << ").\n";
  }

  void dispatchOrder() {
    if (isEmpty()) {
      cout << "No orders to dispatch.\n";
      return;
    }
    cout << "Dispatching Order " << queue[front].orderID << " from "
         << queue[front].restaurant << endl;
    front = (front + 1) % MAX;
    count--;
  }

  void viewNextOrder() {
    if (isEmpty()) {
      cout << "No pending orders.\n";
      return;
    }
    Order o = queue[front];
    cout << "\nNext Order to dispatch:\n";
    cout << "Order ID: " << o.orderID << endl;
    cout << "Restaurant: " << o.restaurant << endl;
    cout << "Customer: " << o.customer << endl;
    cout << "Items: " << o.items << endl;
    cout << "Prep Time: " << o.prepTime << " mins" << endl;
    cout << "Order Time: " << o.orderTime << endl;
  }

  void displayAllOrders() {
    if (isEmpty()) {
      cout << "No pending orders.\n";
      return;
    }
    cout << "\n--- Current Queue ---\n";
    for (int i = 0; i < count; i++) {
      int index = (front + i) % MAX;
      cout << "Order " << queue[index].orderID << " | "
           << queue[index].restaurant << " | Prep: " << queue[index].prepTime
           << " mins | Customer: " << queue[index].customer << endl;
    }
    cout << endl;
  }

  void cancelOrder(int id) {
    if (isEmpty()) {
      cout << "Queue is empty!!";
      return;
    }
    bool found = false;

    for (int i = 0; i < count; i++) {
      int index = (front + i) % MAX;
      if (queue[index].orderID == id) {
        found = true;
        cout << "Cancelling Order " << id << endl;

        for (int j = i; j < count - 1; j++) {
          int from = (front + j + 1) % MAX;
          int to = (front + j) % MAX;
          to = from;
        }
        
        rear = (rear - 1 + MAX) % MAX;
        count--;
        break;
      }
    }
  }
};

int main() {
  DeliveryQueue d;

  d.addOrder(101, "McDonalds", "House 12", "Burger, Fries", 8, "12:30");
  d.addOrder(102, "KFC", "Street 5", "Zinger", 15, "12:35");
  d.addOrder(103, "Subway", "House 21", "Sandwich", 5, "12:40");
  d.addOrder(104, "Pizza Hut", "Block B", "Pizza", 20, "12:45");

  d.displayAllOrders();

  cout << "\nDispatching 2 orders:\n";
  d.dispatchOrder();
  d.dispatchOrder();

  d.displayAllOrders();

  cout << "\nCancelling Order 104:\n";
  d.cancelOrder(104);

  d.displayAllOrders();

  return 0;
}
