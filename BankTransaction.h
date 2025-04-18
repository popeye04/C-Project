#ifndef BANKTRANSACTION_H
#define BANKTRANSACTION_H

#include <string>

class BankTransaction
{

private:

    int accountID;
    char name[100], address[100], type[10];
    float balance;
    std::string password;

public:

    static int accountCount;
    static BankTransaction accounts[100];

    void OpenAccount();
    void DepositMoney();
    void WithdrawMoney();
    void DisplayAmount();
    int getAccountID();
    bool verifyPassword();
    static int SearchAccount(int id);
    static void AdminView();


};

#endif // BANKTRANSACTION_H
