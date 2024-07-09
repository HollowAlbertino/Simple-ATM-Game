//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class SavingAccount.
#pragma once
#include "BankAccount.h"

class SavingAccount : public BankAccount {
public:
    SavingAccount(int dollars, int cents, double rate);
    SavingAccount(int dollars, double rate);
    SavingAccount();
    void update();
    double get_rate() const;
    void output(ostream& outs) const;
    void input(istream& ins);

private:
    double interest_rate;
    double fraction(double percent) const;
};
