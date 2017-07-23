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

void show_menu();

int search_accounts(string account, string accounts[]);

void deposit();

void withdraw();

void check_balance();

void add_new_account();

int total_records(string accounts[]);

void quit();

void save_data(string accounts[], double balance[]);

string accounts[MAX_RECORDS];
double balance[MAX_RECORDS];

int main() {
    int index = 0;

    ifstream inFile;
    inFile.open("bank.txt");

    if (inFile.is_open()) {
        //cout << "File is open" << endl;
        while (!inFile.eof() and index != MAX_RECORDS) {
            inFile >> accounts[index];
            inFile >> balance[index];
            ++index;

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
    cout << setw(15) << left << "Welcome to the Staten Island Bank" << endl;
    do {
        cout << "Select one of the following:" << endl;
        cout << "To Withdrawal" << setw(10) << right << "W" << endl;
        cout << "To Deposit" << setw(13) << "D" << right << endl;
        cout << "To Balance" << setw(13) << "B" << right << endl;
        cout << "To Add new account" << setw(5) << "A" << right << endl;
        cout << "To Quit" << setw(16) << "Q" << right << endl;
        cin >> transaction_type;
        if (transaction_type == 'W' || transaction_type == 'w') {
            withdraw();
        } else if (transaction_type == 'D' || transaction_type == 'd') {
            deposit();
        } else if (transaction_type == 'B' || transaction_type == 'b') {
            check_balance();
        } else if (transaction_type == 'A' || transaction_type == 'a'){
            add_new_account();
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
        save_data(accounts,balance);
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

//    cout << account_pos;

    if (account_pos != -1) {
        cout << endl << "Account # " << accounts[account_pos];
        cout << endl << "Please enter amount that you wish to withdraw " << accounts[account_pos] << endl;

        do {
            cin >> withdraw_amount;
            // deduct withdraw amount from existing balance
            if (balance[account_pos] < withdraw_amount) {
                cout << endl << "Insufficient funds";
                cout << endl << "Please enter amount that you wish to withdraw " << accounts[account_pos] << endl;
            } else {
                balance[account_pos] -= withdraw_amount;
                cout << endl << "You have successfully withdrawn $" << withdraw_amount << " from "
                     << "the account : "
                     << accounts[account_pos];
                save_data(accounts, balance);
                show_menu();
            }
        } while (balance[account_pos] < withdraw_amount);

    } else {
        cout << endl << "We cannot find the " << accounts[account_pos] << " in our system" << endl;
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

/**
 *
 */
void quit() {
    exit(0);
}

/**
 * @details
 * @param accounts
 * @param balance
 * @author
 * @date
 */
void save_data(string accounts[], double balance[]) {
    ofstream outFile;
    outFile.open("bank.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < MAX_RECORDS; i++) {
            outFile << accounts[i] << " " << balance[i] << endl;
        }
    }
    outFile.close();
}

/**
 *
 */
void add_new_account(){
    string new_account_number;
    int account_flag;
    int account_pos = total_records(accounts);

    cout << "Please enter the new account " <<endl;
    cin >> new_account_number;

    account_flag = search_accounts(new_account_number, accounts);
    if(account_flag == -1) {
        accounts[account_pos + 1] = new_account_number;
        balance[account_pos + 1] = 0.00;
        save_data(accounts,balance);
    }else{
        cout <<  endl << "Account " << new_account_number << " is exist in the file" << endl;
    }
}

/**
 *
 * @param accounts
 * @return
 */
int total_records(string accounts[]){
    return sizeof(accounts);

}