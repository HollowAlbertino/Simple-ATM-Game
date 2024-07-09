#include "BankAccount.h"
#include <iostream>
#include <cstdlib>

using namespace std;

BankAccount::BankAccount(int dollars, int cents) {
    if (dollars < 0 || cents < 0) {
        cout << "Illegal values for money.\n";
        exit(1);
    }
    balance = dollars + 0.01 * cents; // Convert cents to a dollar fraction and add
}

BankAccount::BankAccount(int dollars) : balance(dollars) {
    if (dollars < 0) {
        cout << "Illegal values for money.\n";
        exit(1);
    }
}

BankAccount::BankAccount() : balance(0) {
    // Constructor intentionally left empty to default to a balance of 0
}

double BankAccount::get_balance() const {
    return balance;
}

void BankAccount::set_balance(double new_balance) {
    if (new_balance < 0) {
        cout << "Illegal value for new balance.\n";
        exit(1);
    }
    balance = new_balance;
}

void BankAccount::output(ostream& outs) const {
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance: $" << balance << endl;
}

void BankAccount::input(istream& ins) {
    double input_balance;
    ins >> input_balance;
    if (input_balance < 0) {
        cout << "Illegal value for balance.\n";
        exit(1);
    }
    balance = input_balance;
}

void BankAccount::deposit(int dollars, int cents) {
    if (dollars < 0 || cents < 0 || cents >= 100) {
        cout << "Illegal values for deposit.\n";
        exit(1);
    }
    balance += dollars + cents / 100.0;  // Correctly handle cents as a fraction of a dollar
}

void BankAccount::withdraw(int dollars, int cents) {
    double amount = dollars + cents / 100.0; // Correctly handle cents
    if (amount > balance) {
        cout << "Insufficient funds for withdrawal.\n";
        exit(1);
    }
    balance = amount;
}
