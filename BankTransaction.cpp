#include "banktransaction.h"
#include <iostream>
#include <string>




using namespace std;

int BankTransaction::accountCount = 0;
BankTransaction BankTransaction::accounts[100];

int BankTransaction::getAccountID()
{
    return accountID;
}

bool BankTransaction::verifyPassword()
{
    string inputPass;
    cout<<"Enter your password: ";
    cin>>inputPass;
    return inputPass == password;
}

void BankTransaction::OpenAccount()
{
    cout<<endl<< "Enter Account ID (within 12 digits): ";
    cin>> accountID;
    cin.ignore();
    cout<< endl << "Enter Your Full Name:" <<endl;
    cin.getline(name, 100);
    cout<< endl << "Enter Your Address:" <<endl;
    cin.getline(address, 100);
    while (true)
    {
        cout<< endl << "Type of Account You Want to Open savings(s) or current(c):" << endl;
        cin.getline(type, 10);
        if (type[0] == 's' || type[0] == 'S' || type[0] == 'c' || type[0] == 'C')
        {
            break;
        }
        else
        {
            cout << "Incorrect Account Type. Please Try Again." << endl;
        }
    }
    cout<< endl << "Enter Your Deposit Amount:" <<endl;
    cin>> balance;
    cout<< endl << "Set Your Account Password: ";
    cin>> password;
    cout<< endl << "Your Account is Created Successfully." <<endl;

    accountCount++;


    for (int i = 0; i < accountCount - 1; i++)
    {
        for (int j = 0; j < accountCount - i - 1; j++)
        {
            if (accounts[j].accountID > accounts[j + 1].accountID)
            {
                BankTransaction temp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = temp;
            }
        }
    }
}

void BankTransaction::DepositMoney()
{
    float deposit;
    cout<< endl << "Enter the Amount You Want to Deposit:" <<endl;
    cin>> deposit;
    balance += deposit;
    cout<< "\nYour Current Balance is: " << balance <<endl;

    transactionHistory.push("Deposited " + to_string(deposit));
}

void BankTransaction::WithdrawMoney()
{
    float withdraw;
    cout<< endl << "Enter the Amount You Want to Withdraw:" <<endl;
    cin>> withdraw;
    if (withdraw <= balance)
    {
        balance -= withdraw;
        cout<< "\nYour Remaining Balance is: " << balance <<endl;
        transactionHistory.push("Withdrew " + to_string(withdraw));
    }
    else
    {
        cout<< "\nInsufficient balance!" <<endl;
    }
}

void BankTransaction::DisplayAmount()
{
    cout<< endl << "Your Name: " << name <<endl;
    cout<< "Your Address: " << address <<endl;
    cout<< endl << "Type of Account: " << type <<endl;
    cout<< "Account ID: " << accountID <<endl;
    cout<< "Current/Total Balance: " << balance <<endl;
}

void BankTransaction::ShowTransactionHistory()
{
    if (transactionHistory.empty())
    {
        cout<< "No transactions yet." <<endl;
        return;
    }

    cout<< "\nRecent Transactions:\n";
    std::stack<std::string> tempStack = transactionHistory;

    while (!tempStack.empty())
    {
        cout<< tempStack.top() <<endl;
        tempStack.pop();
    }
}

int BankTransaction::SearchAccount(int id)
{
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountID == id)
        {
            return i;
        }
    }
    return -1;
}

void BankTransaction::AdminView()
{
    int adminPassword;
    cout<< "Enter Admin Password: ";
    cin>> adminPassword;

    if (adminPassword == 420)
    {
        cout<< "\nWelcome Admin!\n";
        cout<< "\nList of All Accounts (Sorted by Account ID):\n";

        for (int i = 0; i < accountCount; i++)
        {
            cout<< "Account " << i + 1 << ": " << accounts[i].name
                << " (ID: " << accounts[i].accountID << ")\n";
        }
    }
    else
    {
        cout<< "Incorrect Admin Password!\n";
    }
}

