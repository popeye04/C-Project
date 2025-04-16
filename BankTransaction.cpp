#include "banktransaction.h"
#include <iostream>
#include <string>
using namespace std;

int BankTransaction::accountCount = 0;
BankTransaction BankTransaction::accounts[100];

int BankTransaction::getAccountID() {
    return accountID;
}

bool BankTransaction::verifyPassword() {
    string inputPass;
    cout << "Enter your password: ";
    cin >> inputPass;
    return inputPass == password;
}

void BankTransaction::OpenAccount() {
    cout << endl << "Enter Account ID (unique number): ";
    cin >> accountID;
    cin.ignore(); // Clear input buffer
    cout << endl << "Enter Your Full Name:" << endl;
    cin.getline(name, 100);
    cout << endl << "Enter Your Address:" << endl;
    cin.getline(address, 100);
    cout << endl << "Type of Account You Want to Open savings(s) or current(c):" << endl;
    cin.getline(type, 10);
    cout << endl << "Enter Your Deposit Amount:" << endl;
    cin >> balance;
    cout << endl << "Set Your Account Password: ";
    cin >> password;
    cout << endl << "Your Account is Created Successfully." << endl;

    accountCount++;

}

void BankTransaction::DepositMoney() {
    int deposit;
    cout << endl << "Enter the Amount You Want to Deposit:" << endl;
    cin >> deposit;
    balance = balance + deposit;
    cout << "\nYour Current Balance is: " << balance << endl;
}

void BankTransaction::WithdrawMoney() {
    int withdraw;
    cout << endl << "Enter the Amount You Want to Withdraw:" << endl;
    cin >> withdraw;
    if (withdraw <= balance) {
        balance = balance - withdraw;
        cout << "\nYour Remaining Balance is: " << balance << endl;
    } else {
        cout << "\nInsufficient balance!" << endl;
    }
}

void BankTransaction::DisplayAmount() {
    cout <<endl<< "Your Name: " << name << endl;
    cout <<"Your Address: " << address << endl;
    cout << endl << "Type of Account: " << type << endl;
    cout << "Account ID: " << accountID << endl;
    cout << "Current/Total Balance: " << balance << endl;
}

int BankTransaction::SearchAccount(int id) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountID == id) {
            return i;
        }
    }
    return -1;
}
