//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class BankAccount.
#include <iostream>
using namespace std;

#pragma once

class BankAccount {
public:
    BankAccount(int dollars, int cents);
    BankAccount(int dollars);
    BankAccount();
    double get_balance() const;
    void set_balance(double balance);
    void output(ostream& outs) const;
	void input(istream& ins);
    void deposit(int dollars, int cents = 0);
    void withdraw(int dollars, int cents = 0);

private:
    double balance;
};
