#ifndef BANKTRANSACTION_H
#define BANKTRANSACTION_H

#include <string>
#include <stack>

class BankTransaction
{

private:

    long long int accountID;
    char name[100], address[100], type[10];
    float balance;
    std::string password;
    std::stack<std::string> transactionHistory; // new

public:

    static int accountCount;
    static BankTransaction accounts[100];

    void OpenAccount();
    void DepositMoney();
    void WithdrawMoney();
    void DisplayAmount();
    void ShowTransactionHistory(); // new
    int getAccountID();
    bool verifyPassword();
    static int SearchAccount(int id);
    static void AdminView();
    void SaveToFile();
    void LoadFromFile();

};

#endif // BANKTRANSACTION_H
