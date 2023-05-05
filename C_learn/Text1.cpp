#include <iostream>
#include <string>
using namespace std;
class Account {
public:
    Account() {
        string id;
        string name;
        double balance;
        double annualInterestRate;
    }
    Account(string newId, string newName, double newBalance, double newAnnualInterestRate) {
        id = newId;
        name = newName;
        balance = newBalance;
        annualInterestRate = newAnnualInterestRate;
    }
    void setId(string newId) {
        id = newId;
    }
    void setName(string newName) {
        name = newName;
    }
    void setBalance(double newBalance) {
        balance = newBalance;
    }
    void setAnnualInterestRate(double newAnnualInterestRate) {
        annualInterestRate = newAnnualInterestRate;
    }
    string getId() const {
        return id;
    }
    string getName() const {
        return name;
    }
    double getBalance() const {
        return balance;
    }
    double getAnnualInterestRate() const {
        return annualInterestRate;
    }
    void withdraw(double a) {
        balance -= a;
    }
    void deposit(double b) {
        balance += b;
    }
    void print() {
        cout << id << "\n"
             << name << "\n"
             << balance + b - a << "\n"
             << annualInterestRate / 2;
    }

private:
    string id;
    string name;
    double balance;
    double annualInterestRate;
};

int main() {
    string id;
    string name;
    double balance;
    double annualInterestRate;
    cin >> id >> name >> balance >> annualInterestRate;
    Account account(id, name, balance, annualInterestRate);
    account.withdraw(2500);
    account.deposit(3000);
    account.print();
    return 0;
}