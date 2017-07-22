/**
    Course: CSC126(****)
    Filename : ****.cpp
    Requried : *****.txt
    Purpose: ***
    @author Suresh Melvin Sigera
    @date 20/07/2017
*/

#include <iostream> //standard input / output streams
#include <fstream>  //file streams
#include <iomanip>  //parametric manipulators

using namespace std;

const int MAX_RECORDS = 50; //maximum records in the file.
const int RECORD_LIMIT = 15;//number of jobs available records.

void show_menu();

int search_accounts(string account, string accounts[]);

void deposit();

void withdraw();

void check_balance();

void quit();

string accounts[MAX_RECORDS];
double balance[MAX_RECORDS];

int main() {
    int index = 0;


    ifstream inFile;
    inFile.open("bank50.txt");

    if (inFile.is_open()) {
        //cout << "File is open" << endl;
        while (!inFile.eof() and index != MAX_RECORDS) {
            inFile >> accounts[index];
            inFile >> balance[index];
            index++;
        }
        inFile.close();
        //cout << "File is closed.";
    } else {
        cerr << "Cannot open the file";
        exit(EXIT_FAILURE);
    }
    show_menu();

    return 0;
}


void show_menu() {
    char transaction_type;

    do {
        cout << endl << "Select one of the following:" << endl;
        cout << "W - Withdrawal" << endl;
        cout << "D  - Deposit" << endl;
        cout << "B  - Balance" << endl;
        cout << "Q  - Quit" << endl;
        cin >> transaction_type;
        if (transaction_type == 'W' || transaction_type == 'w') {
            withdraw();
        } else if (transaction_type == 'D' || transaction_type == 'd') {
            deposit();
        } else if (transaction_type == 'B' || transaction_type == 'b') {
            check_balance();
        } else if (transaction_type == 'Q' || transaction_type == 'q') {
            quit();
        }
    } while (transaction_type != 'Q' || transaction_type != 'q');
}


/**
 * @details
 * @param account
 * @param accounts
 * @return flag
 */
int search_accounts(string account, string accounts[]) {
    int index = 0;
    int flag = -1;

    for (int i = 0; i < MAX_RECORDS; i++) {
        if (accounts[i] == account) {
            flag = index;
        }
        index++;
    }
    return flag;
}

/**
 * @details
 * @param account_pos
 * @param accounts
 * @param balance
 */
void deposit() {
    string user_account_number;
    double deposit_amount;
    int account_pos;

    cout << endl << "Please enter the account number" << endl;
    cin >> user_account_number;

    account_pos = search_accounts(user_account_number, accounts);

    cout << account_pos;

    if (account_pos != -1) {
        cout << endl << "Account # " << accounts[account_pos];
        cout << endl << "Please enter amount to be deposited into your account " << accounts[account_pos] << endl;
        cin >> deposit_amount;
        balance[account_pos] += deposit_amount;
        cout << endl << "We have successfully processed your $" << deposit_amount << " to " << "the account : "
             << accounts[account_pos];
    } else {
        cout << endl << "We cannot find the " << accounts[account_pos] << " in our system" << endl;
    }
}

void withdraw() {
    string user_account_number;
    double withdraw_amount;
    int account_pos;

    cout << endl << "Please enter the account number" << endl;
    cin >> user_account_number;

    account_pos = search_accounts(user_account_number, accounts);

    cout << account_pos;

    if (account_pos != -1) {
        cout << endl << "Account # " << accounts[account_pos];
        cout << endl << "Please enter amount that you wish to withdraw " << accounts[account_pos] << endl;
        cin >> withdraw_amount;

        // deduct withdraw amount from existing balance
        balance[account_pos] -= withdraw_amount;
        cout << endl << "You have successfully withdrawn $" << withdraw_amount << " from " << "the account : "
             << accounts[account_pos];
    } else {
        cout << endl << "The new balance is " << balance[account_pos];
    }
}

void check_balance() {
    string user_account_number;
    int account_pos;

    cout << endl << "Please enter the account number" << endl;
    cin >> user_account_number;

    account_pos = search_accounts(user_account_number, accounts);

    if (account_pos != -1) {
        cout << endl << "Account # " << accounts[account_pos];
        cout << endl << "Your current balance is: " << balance[account_pos] << endl;
    } else {
        cout << endl << "We cannot find the " << accounts[account_pos] << " in our system" << endl;
    }
}

void quit() {
    exit(0);
}