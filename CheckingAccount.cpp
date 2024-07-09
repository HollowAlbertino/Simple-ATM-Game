#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int dollars, int cents, double fee)
    : BankAccount(dollars, cents), check_fee(fee) {}

CheckingAccount::CheckingAccount(int dollars, double fee)
    : BankAccount(dollars), check_fee(fee) {}

CheckingAccount::CheckingAccount() : check_fee(0) {}

double CheckingAccount::get_check_fee() const {
    return check_fee;
}

void CheckingAccount::set_check_fee(double fee) {
    check_fee = fee;
}

void CheckingAccount::output(ostream& outs) const {
    BankAccount::output(outs);
    outs << "Check Fee: $" << get_check_fee() << endl;
}

void CheckingAccount::input(istream& ins) {
    BankAccount::input(ins);
    ins >> check_fee;
}

void CheckingAccount::check(int dollars, int cents) {
    // Withdraw the check amount first
    withdraw(dollars, cents);

    // Now withdraw the check fee
    int fee_dollars = static_cast<int>(check_fee);
    int fee_cents = static_cast<int>((check_fee - fee_dollars) * 100);
    withdraw(fee_dollars, fee_cents);
}

