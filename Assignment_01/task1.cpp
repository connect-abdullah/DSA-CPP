#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  
using namespace std;

class TransactionManager {
private:
    vector<double> transactions;

public:
    void insertTransaction(double amount) {
        transactions.push_back(amount);
    }

    void deleteTransaction(int index) {
        if (index >= 0 && index < transactions.size()) {
            transactions.erase(transactions.begin() + index);
        } else {
            cout << "Invalid index!\n";
        }
    }

    void findAndUpdate(double oldAmount, double newAmount) {
        for (double &t : transactions) {
            if (t == oldAmount) {
                t = newAmount;
            }
        }
    }

    void calculateStatistics() {
        if (transactions.empty()) {
            cout << "No transactions available!\n";
            return;
        }

        int count = transactions.size();
        double maxVal = *max_element(transactions.begin(), transactions.end());
        double minVal = *min_element(transactions.begin(), transactions.end());
        double sum = accumulate(transactions.begin(), transactions.end(), 0.0);
        double avg = sum / count;

        cout << "Statistics -> count=" << count
             << ", max=" << maxVal
             << ", min=" << minVal
             << ", avg=" << avg << "\n";
    }

    void displayTransactionsSorted(bool ascending = true) {
        vector<double> sorted = transactions;
        if (ascending)
            sort(sorted.begin(), sorted.end());
        else
            sort(sorted.rbegin(), sorted.rend());

        cout << "Transactions: ";
        for (double t : sorted) cout << t << " ";
        cout << "\n";
    }

    void displayTransactions() {
        cout << "Transactions: ";
        for (double t : transactions) cout << t << " ";
        cout << "\n";
    }
};

int main() {
    TransactionManager transaction;

    // Insert
    transaction.insertTransaction(2500);
    transaction.insertTransaction(3200);
    transaction.insertTransaction(1800);
    transaction.insertTransaction(2500);
    transaction.insertTransaction(4000);

    transaction.displayTransactions();

    // Delete transaction at index 2
    transaction.deleteTransaction(2);
    transaction.displayTransactions();

    // Update all 2500 → 2600
    transaction.findAndUpdate(2500, 2600);
    transaction.displayTransactions();

    // Stats
    transaction.calculateStatistics();

    // Descending
    transaction.displayTransactionsSorted(false);

    return 0;
}
