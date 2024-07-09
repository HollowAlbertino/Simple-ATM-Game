#pragma once
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(int dollars, int cents, double fee);
    CheckingAccount(int dollars, double fee);
    CheckingAccount();
    double get_check_fee() const;
    void set_check_fee(double fee);
    void output(ostream& outs) const;
    void input(istream& ins);
    void check(int dollars, int cents = 0);

private:
    double check_fee;
};
