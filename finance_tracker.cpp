#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Transaction {
    string description;
    double amount;
    string date;
    string type; // "Income" or "Expense"
};

class Finance_track {
private:
    vector<Transaction> transactions;

public:
    void addTransaction(const Transaction &transaction) {
        transactions.push_back(transaction);
    }

    void displayTransactions() {
        for (const auto &transaction : transactions) {
            cout << "Description: " << transaction.description
                      << ", Amount: " << transaction.amount
                      << ", Date: " << transaction.date
                      << ", Type: " << transaction.type << "\n";
        }
    }

    double getTotalBalance() {
        double balance = 0.0;
        for (const auto &transaction : transactions) {
            balance += transaction.amount;
        }
        return balance;
    }

   

};

int main() {
    Finance_track tracker;
    int choice;

    do {
        cout << "\nFinance Tracker Menu:\n";
        cout << "1. Add Transaction\n";
        cout << "2. Display All Transactions\n";
        cout << "3. Display Total Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Transaction transaction;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, transaction.description);
                cout << "Enter amount: ";
                cin >> transaction.amount;
                cout << "Enter date (YYYY-MM-DD): ";
                cin.ignore();
                getline(cin, transaction.date);
                cout << "Enter type (Income/Expense): ";
                getline(cin, transaction.type);
                tracker.addTransaction(transaction);
                break;
            }
            case 2: {
                tracker.displayTransactions();
                break;
            }
            case 3: {
                cout << "Total Balance: " << tracker.getTotalBalance() << "\n";
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
