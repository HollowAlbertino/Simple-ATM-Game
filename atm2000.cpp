#include <iostream>
#include <string>
#include "BankAccount.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main() {
    SavingAccount saving;
    CheckingAccount checking;

    // Initialize accounts
    cout << "Update the account info for Checking (balance and fee): ";
    checking.input(cin);

    cout << "Update the account info for Saving (balance and rate): ";
    saving.input(cin);

    // Welcome message
    cout << "***** Welcome to the ATM 2000!!\n";
    cout << "Looks like you accrued some interest in your Savings.\n";

    char transact, fromAcct;
    double amount;
    
    do {
        cout << "\nWhat would you like to do today?\n";
        cout << "B)alance, D)eposit, W)ithdraw, C)heck, T)ransfer, Q)uit?\n";
        cin >> transact;

        switch(transact) {
            case 'B':  // Balance inquiry
                cout << "From which account? C) checking, S) savings: ";
                cin >> fromAcct;
                if (fromAcct == 'C') checking.output(cout);
                else if (fromAcct == 'S') saving.output(cout);
                break;
            case 'D':  // Deposit
                cout << "What amount would you like to Deposit today?\n";
                cin >> amount;
                cout << "From which account? C) checking, S) savings: ";
                cin >> fromAcct;
                if (fromAcct == 'C') checking.deposit(amount);
                else if (fromAcct == 'S') saving.deposit(amount);
                break;
            case 'W':  // Withdraw
                cout << "What amount would you like to Withdraw today?\n";
                cin >> amount;
                cout << "From which account? C) checking, S) savings: ";
                cin >> fromAcct;
                if (fromAcct == 'C') checking.withdraw(amount);
                else if (fromAcct == 'S') saving.withdraw(amount);
                break;
            case 'C':  // Check
                cout << "What amount would you like to Write a Check for today?\n";
                cin >> amount;
                checking.check(amount);
                break;
            case 'T':  // Transfer
                cout << "What amount would you like to Transfer today?\n";
                cin >> amount;
                cout << "Transfer from which account? C) checking, S) savings: ";
                cin >> fromAcct;
                cout << "Transfer to which account? C) checking, S) savings: ";
                char toAcct;
                cin >> toAcct;
                if (fromAcct == 'C' && toAcct == 'S') {
                    checking.withdraw(amount);
                    saving.deposit(amount);
                } else if (fromAcct == 'S' && toAcct == 'C') {
                    saving.withdraw(amount);
                    checking.deposit(amount);
                }
                break;
            case 'Q':  // Quit
                cout << "Come Again! Bye!\n";
                break;
            default:
                cout << "Invalid transaction type. Please try again.\n";
        }

    } while (transact != 'Q');

    return 0;
}
