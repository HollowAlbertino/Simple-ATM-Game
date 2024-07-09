//Program to demonstrate the class SavingAccount.
#include "SavingAccount.h"
#include <iostream>
#include <cstdlib>

using namespace std;

SavingAccount::SavingAccount(int dollars, int cents, double rate)
    : BankAccount(dollars, cents) {
    if (rate < 0) {
        cout << "Illegal value for interest rate.\n";
        exit(1);
    }
    interest_rate = rate;
}

SavingAccount::SavingAccount(int dollars, double rate)
    : BankAccount(dollars) {
    if (rate < 0) {
        cout << "Illegal value for interest rate.\n";
        exit(1);
    }
    interest_rate = rate;
}

SavingAccount::SavingAccount() : BankAccount(), interest_rate(0.0) {
    // Constructor intentionally empty
}

void SavingAccount::update() {
    double amount = fraction(interest_rate) * get_balance();
    deposit(static_cast<int>(amount), static_cast<int>((amount - static_cast<int>(amount)) * 100));
}

double SavingAccount::get_rate() const {
    return interest_rate;
}

void SavingAccount::output(ostream& outs) const {
    BankAccount::output(outs); // Call the base class output function
    outs << "Interest Rate: " << interest_rate << "%" << endl;
}

void SavingAccount::input(istream& ins) {
    BankAccount::input(ins); // Call the base class input function
    cout << "" << endl;
    ins >> interest_rate;
    if (interest_rate < 0) {
        cout << "Illegal value for interest rate.\n";
        exit(1);
    }
}

double SavingAccount::fraction(double percent) const {
    return percent / 100.0;
}
