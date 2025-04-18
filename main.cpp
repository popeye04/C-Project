#include <iostream>
#include "banktransaction.h"
using namespace std;

int main()
{
    int num, searchID, index;
    char option;

    cout << "\n||-------------------------------------------------||" << endl;
    cout << "||-------------------COOL Bank---------------------||" << endl;
    cout << "||------------------Welcome User!------------------||" << endl;
    cout << "||-------------------------------------------------||" << endl;
    cout << "\n1) Open Account." << endl;
    cout << "2) Deposit Money." << endl;
    cout << "3) Withdraw Money." << endl;
    cout << "4) Display Account." << endl;
    cout << "5) Open Admin Panel (Show All Accounts)." << endl;
    cout << "6) Show Transaction History." << endl;
    cout << "7) Exit." << endl;

    do
    {
        cout << "\nEnter an Option: ";
        cin >> num;

        switch (num)
        {
        case 1:
            BankTransaction::accounts[BankTransaction::accountCount].OpenAccount();
            break;

        case 2:
            cout << "Enter Account ID: ";
            cin >> searchID;
            index = BankTransaction::SearchAccount(searchID);
            if (index != -1 && BankTransaction::accounts[index].verifyPassword())
            {
                BankTransaction::accounts[index].DepositMoney();
            }
            else
            {
                cout << "Invalid account or password!\n";
            }
            break;

        case 3:
            cout << "Enter Account ID: ";
            cin >> searchID;
            index = BankTransaction::SearchAccount(searchID);
            if (index != -1 && BankTransaction::accounts[index].verifyPassword())
            {
                BankTransaction::accounts[index].WithdrawMoney();
            }
            else
            {
                cout << "Invalid account or password!\n";
            }
            break;

        case 4:
            cout << "Enter Account ID: ";
            cin >> searchID;
            index = BankTransaction::SearchAccount(searchID);
            if (index != -1 && BankTransaction::accounts[index].verifyPassword())
            {
                BankTransaction::accounts[index].DisplayAmount();
            }
            else
            {
                cout << "Invalid account or password!\n";
            }
            break;

        case 5:
            BankTransaction::AdminView();
            break;

        case 6:
            cout << "Enter Account ID: ";
            cin >> searchID;
            index = BankTransaction::SearchAccount(searchID);
            if (index != -1 && BankTransaction::accounts[index].verifyPassword())
            {
                BankTransaction::accounts[index].ShowTransactionHistory();
            }
            else
            {
                cout << "Invalid account or password!\n";
            }
            break;

        case 7:
            cout << "||---------------------Exited----------------------||" << endl;
            exit(0);

        default:
            cout << "\nTry Again and Choose the Correct Option !" << endl;
            break;
        }

        cout << "\nDo You Want to Continue Banking Without Exit? Press(Y/N)." << endl;
        cin >> option;

        if ((option == 'n') || (option == 'N'))
        {
            cout << "||---------------------Exited----------------------||" << endl;
            exit(0);
        }

    } while ((option == 'y') || (option == 'Y'));

    return 0;
}
