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

void show_menu(string accounts[], double balance[]);

int search_accounts(string account, string accounts[]);

void deposit(int account_pos, string accounts[], double balance[]);

int main() {
    int index = 0;
    string accounts[MAX_RECORDS];
    double balance[MAX_RECORDS];

    ifstream inFile;
    inFile.open("bank.txt");

    if (inFile.is_open()) {
        //cout << "File is open" << endl;
        while (!inFile.eof()) {
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
    show_menu(accounts, balance);

    return 0;
}

/**
 * @details
 * @param accounts
 * @param balance
 */
void show_menu(string accounts[], double balance[]) {
    char transaction_type;
    int valid_account_number = -1;
    string user_account_number;

    cout << "Please enter the account number" << endl;
    cin >> user_account_number;

    valid_account_number = search_accounts(user_account_number, accounts);

    if (valid_account_number != -1) {
        cout << endl << "Account is ready to use" << endl;
        do {
            cout << endl << "Select one of the following:" << endl;
            cout << "W - Withdrawal" << endl;
            cout << "D  - Deposit" << endl;
            cout << "B  - Balance" << endl;
            cout << "Q  - Quit" << endl;
            cin >> transaction_type;
            if (transaction_type == 'W' || transaction_type == 'w') {
                cout << "-----_W" << endl;
            } else if (transaction_type == 'D' || transaction_type == 'd') {
                deposit(valid_account_number, accounts, balance);
            } else if (transaction_type == 'B' || transaction_type == 'b') {
                cout << "Your Account Balance" << endl;
            } else if (transaction_type == 'Q' || transaction_type == 'q') {
                exit(0);
            }
        } while (transaction_type != 'Q' || transaction_type != 'q');
    } else {
        cout << "------";
    }
}

/**
 * @details
 * @param account
 * @param accounts
 * @return user account index position
 */
int search_accounts(string account, string accounts[]) {
    int index = 0;

    cout << "Account Number Entered: " << account << endl << endl;

    for (int i = 0; i < RECORD_LIMIT; i++) {
        if (accounts[i] == account) {
            cout << "Valid Account Number";
            return index;
        } else {
            cout << "Invalid Account Number";
            return -1;
        }
    }
}

/**
 * @details
 * @param account_pos
 * @param accounts
 * @param balance
 */
void deposit(int account_pos, string accounts[], double balance[]) {
    double deposit_amount;

    cout << "Please enter amount to be deposited into your account " << accounts[account_pos] << endl;
    cin >> deposit_amount;

    // increment the existing balance
    balance[account_pos] += deposit_amount;

    cout << endl << "We have successfully processed your $" << deposit_amount << " to " << "the account : "
         << accounts[account_pos];
    cout << endl << "The current total is " << balance[account_pos];
}