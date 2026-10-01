#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <string>

using namespace std;

const char FILE_NAME[] = "transactions.dat";

struct Transaction
{
    int transactionId;
    long long accountNumber;
    char dateTime[20];       // YYYY-MM-DD HH:MM:SS
    char transactionType[10]; // DEPOSIT, WITHDRAW, TRANSFER
    double amount;
    double balanceAfter;
};


// Utility Functions


bool isValidType(const string& type)
{
    return type == "DEPOSIT" || type == "WITHDRAW" || type == "TRANSFER";
}

string getCurrentDateTime()
{
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

    return string(buffer);
}

bool isValidDateTime(const string& dateTime)
{
    // Basic validation for YYYY-MM-DD HH:MM:SS
    if (dateTime.length() != 19)
        return false;

    if (dateTime[4] != '-' || dateTime[7] != '-' ||
        dateTime[10] != ' ' || dateTime[13] != ':' ||
        dateTime[16] != ':')
        return false;

    for (int i = 0; i < 19; i++)
    {
        if (i == 4 || i == 7 || i == 10 || i == 13 || i == 16)
            continue;

        if (dateTime[i] < '0' || dateTime[i] > '9')
            return false;
    }

    return true;
}

bool fileExists()
{
    ifstream file(FILE_NAME, ios::binary);
    return file.good();
}

bool isDuplicateTransactionId(int id)
{
    ifstream file(FILE_NAME, ios::binary);

    if (!file)
        return false;

    Transaction t;

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        if (t.transactionId == id)
            return true;
    }

    return false;
}

bool isCorruptedFile()
{
    ifstream file(FILE_NAME, ios::binary);

    if (!file)
        return false;

    file.seekg(0, ios::end);
    streamoff size = file.tellg();

    return size % sizeof(Transaction) != 0;
}

void displayTransaction(const Transaction& t)
{
    cout << "\n---------------------------------------------\n";
    cout << "Transaction ID : " << t.transactionId << endl;
    cout << "Account Number : " << t.accountNumber << endl;
    cout << "Date & Time    : " << t.dateTime << endl;
    cout << "Type           : " << t.transactionType << endl;
    cout << fixed << setprecision(2);
    cout << "Amount         : " << t.amount << endl;
    cout << "Balance After  : " << t.balanceAfter << endl;
    cout << "---------------------------------------------\n";
}


// Calculate Current Balance


double calculateCurrentBalance(long long accountNumber)
{
    ifstream file(FILE_NAME, ios::binary);

    if (!file)
        return 0.0;

    Transaction t;
    double currentBalance = 0.0;

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        if (t.accountNumber == accountNumber)
        {
            currentBalance = t.balanceAfter;
        }
    }

    return currentBalance;
}

// Add New Transaction


void addTransaction()
{
    Transaction t;

    cout << "\nEnter Transaction ID: ";
    cin >> t.transactionId;

    if (isDuplicateTransactionId(t.transactionId))
    {
        cout << "Error: Transaction ID already exists.\n";
        return;
    }

    cout << "Enter Account Number: ";
    cin >> t.accountNumber;

    int typeChoice;

    cout << "\nSelect Transaction Type:\n";
    cout << "1. DEPOSIT\n";
    cout << "2. WITHDRAW\n";
    cout << "3. TRANSFER\n";
    cout << "Enter choice: ";
    cin >> typeChoice;

    string type;

    if (typeChoice == 1)
        type = "DEPOSIT";
    else if (typeChoice == 2)
        type = "WITHDRAW";
    else if (typeChoice == 3)
        type = "TRANSFER";
    else
    {
        cout << "Invalid transaction type.\n";
        return;
    }

    strcpy(t.transactionType, type.c_str());

    cout << "Enter Amount: ";
    cin >> t.amount;

    if (t.amount <= 0)
    {
        cout << "Amount must be greater than zero.\n";
        return;
    }

    // Calculate previous balance from file
    double previousBalance = calculateCurrentBalance(t.accountNumber);

    if ((type == "WITHDRAW" || type == "TRANSFER") &&
        t.amount > previousBalance)
    {
        cout << "Error: Insufficient balance.\n";
        return;
    }

    if (type == "DEPOSIT")
        t.balanceAfter = previousBalance + t.amount;
    else
        t.balanceAfter = previousBalance - t.amount;

    string dateTime = getCurrentDateTime();
    strcpy(t.dateTime, dateTime.c_str());

 
    ofstream file(FILE_NAME, ios::binary | ios::app);

    if (!file)
    {
        cout << "Error: Cannot open transaction file.\n";
        return;
    }

    file.write(reinterpret_cast<char*>(&t), sizeof(t));

    if (!file)
    {
        cout << "Error: Transaction could not be written.\n";
        return;
    }

    file.close();

    cout << "\nTransaction added successfully.\n";
    displayTransaction(t);
}

// Search Transactions By Account Number


void searchTransactions()
{
    long long accountNumber;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    ifstream file(FILE_NAME, ios::binary);

    if (!file)
    {
        cout << "No transaction file found.\n";
        return;
    }

    Transaction t;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        if (t.accountNumber == accountNumber)
        {
            displayTransaction(t);
            found = true;
        }
    }

    if (!found)
        cout << "No transactions found for this account.\n";

    file.close();
}


// Complete Transaction History


void displayAccountHistory()
{
    long long accountNumber;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    ifstream file(FILE_NAME, ios::binary);

    if (!file)
    {
        cout << "No transaction file found.\n";
        return;
    }

    Transaction t;
    bool found = false;

    cout << "\n=============================================\n";
    cout << "COMPLETE TRANSACTION HISTORY\n";
    cout << "Account Number: " << accountNumber << endl;
    cout << "=============================================\n";

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        if (t.accountNumber == accountNumber)
        {
            displayTransaction(t);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No transaction history found.\n";
    }
    else
    {
        cout << fixed << setprecision(2);
        cout << "\nCurrent Balance: "
             << calculateCurrentBalance(accountNumber) << endl;
    }

    file.close();
}


// Calculate Current Balance


void showCurrentBalance()
{
    long long accountNumber;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    double balance = calculateCurrentBalance(accountNumber);

    cout << fixed << setprecision(2);
    cout << "Current Balance: " << balance << endl;
}


// Find Record Position


streamoff findTransactionPosition(int transactionId)
{
    ifstream file(FILE_NAME, ios::binary);

    if (!file)
        return -1;

    Transaction t;
    streamoff position = 0;

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        if (t.transactionId == transactionId)
        {
            return position;
        }

        position += sizeof(Transaction);
    }

    return -1;
}


// Modify Transaction Using seekg() and seekp()


void modifyTransaction()
{
    int transactionId;

    cout << "\nEnter Transaction ID to modify: ";
    cin >> transactionId;

    // Check current position using seekg()
    streamoff position = findTransactionPosition(transactionId);

    if (position == -1)
    {
        cout << "Transaction not found.\n";
        return;
    }

    fstream file(FILE_NAME, ios::binary | ios::in | ios::out);

    if (!file)
    {
        cout << "Error: Cannot open transaction file.\n";
        return;
    }

    Transaction oldTransaction;

    // Move GET pointer to required record
    file.seekg(position, ios::beg);

    if (!file.read(reinterpret_cast<char*>(&oldTransaction),
                   sizeof(oldTransaction)))
    {
        cout << "Error: Unable to read transaction.\n";
        file.close();
        return;
    }

    cout << "\nExisting Transaction:";
    displayTransaction(oldTransaction);

    Transaction newTransaction = oldTransaction;

    int choice;

    cout << "\nWhat do you want to modify?\n";
    cout << "1. Account Number\n";
    cout << "2. Date & Time\n";
    cout << "3. Transaction Type\n";
    cout << "4. Amount\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter New Account Number: ";
        cin >> newTransaction.accountNumber;
    }
    else if (choice == 2)
    {
        string dateTime;

        cout << "Enter Date & Time (YYYY-MM-DD HH:MM:SS): ";
        cin.ignore();
        getline(cin, dateTime);

        if (!isValidDateTime(dateTime))
        {
            cout << "Invalid date/time format.\n";
            file.close();
            return;
        }

        strcpy(newTransaction.dateTime, dateTime.c_str());
    }
    else if (choice == 3)
    {
        int typeChoice;

        cout << "1. DEPOSIT\n";
        cout << "2. WITHDRAW\n";
        cout << "3. TRANSFER\n";
        cout << "Enter choice: ";
        cin >> typeChoice;

        string type;

        if (typeChoice == 1)
            type = "DEPOSIT";
        else if (typeChoice == 2)
            type = "WITHDRAW";
        else if (typeChoice == 3)
            type = "TRANSFER";
        else
        {
            cout << "Invalid transaction type.\n";
            file.close();
            return;
        }

        strcpy(newTransaction.transactionType, type.c_str());
    }
    else if (choice == 4)
    {
        cout << "Enter New Amount: ";
        cin >> newTransaction.amount;

        if (newTransaction.amount <= 0)
        {
            cout << "Amount must be greater than zero.\n";
            file.close();
            return;
        }
    }
    else
    {
        cout << "Invalid choice.\n";
        file.close();
        return;
    }

   
    file.seekp(position, ios::beg);

    if (!file.write(reinterpret_cast<char*>(&newTransaction),
                    sizeof(newTransaction)))
    {
        cout << "Error: Transaction modification failed.\n";
        file.close();
        return;
    }

    file.flush();

    cout << "\nTransaction modified successfully using seekp().\n";

    file.close();

    displayTransaction(newTransaction);
}


// Detect Corrupted / Incomplete Records


void checkFileIntegrity()
{
    if (!fileExists())
    {
        cout << "Transaction file does not exist.\n";
        return;
    }

    ifstream file(FILE_NAME, ios::binary);

    file.seekg(0, ios::end);

    streamoff fileSize = file.tellg();

    file.seekg(0, ios::beg);

    cout << "\nFile Size: " << fileSize << " bytes\n";
    cout << "Record Size: " << sizeof(Transaction) << " bytes\n";

    if (fileSize % sizeof(Transaction) != 0)
    {
        cout << "\nWARNING: Corrupted or incomplete record detected.\n";
        cout << "Extra/incomplete bytes: "
             << fileSize % sizeof(Transaction) << endl;
    }
    else
    {
        cout << "\nFile integrity check successful.\n";
        cout << "All records have complete fixed-size structure.\n";
    }

    file.close();
}


// Monthly Transaction Report


void monthlyReport()
{
    string month;

    cout << "\nEnter month for report (YYYY-MM): ";
    cin >> month;

    if (month.length() != 7 ||
        month[4] != '-')
    {
        cout << "Invalid month format. Use YYYY-MM.\n";
        return;
    }

    ifstream file(FILE_NAME, ios::binary);

    if (!file)
    {
        cout << "No transaction file found.\n";
        return;
    }

    Transaction t;

    int count = 0;
    int depositCount = 0;
    int withdrawCount = 0;
    int transferCount = 0;

    double totalDeposit = 0.0;
    double totalWithdraw = 0.0;
    double totalTransfer = 0.0;

    cout << "\n====================================================\n";
    cout << "MONTHLY TRANSACTION REPORT - " << month << endl;
    cout << "====================================================\n";

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        string date(t.dateTime);

        if (date.substr(0, 7) == month)
        {
            displayTransaction(t);

            count++;

            if (strcmp(t.transactionType, "DEPOSIT") == 0)
            {
                depositCount++;
                totalDeposit += t.amount;
            }
            else if (strcmp(t.transactionType, "WITHDRAW") == 0)
            {
                withdrawCount++;
                totalWithdraw += t.amount;
            }
            else if (strcmp(t.transactionType, "TRANSFER") == 0)
            {
                transferCount++;
                totalTransfer += t.amount;
            }
        }
    }

    file.close();

    cout << "\n================ SUMMARY =================\n";
    cout << "Total Transactions : " << count << endl;
    cout << "Deposit Count      : " << depositCount << endl;
    cout << "Withdraw Count     : " << withdrawCount << endl;
    cout << "Transfer Count     : " << transferCount << endl;

    cout << fixed << setprecision(2);

    cout << "Total Deposits     : " << totalDeposit << endl;
    cout << "Total Withdrawals  : " << totalWithdraw << endl;
    cout << "Total Transfers    : " << totalTransfer << endl;

    if (count == 0)
        cout << "\nNo transactions found for " << month << ".\n";
}


// Display All Transactions

void displayAllTransactions()
{
    ifstream file(FILE_NAME, ios::binary);

    if (!file)
    {
        cout << "No transaction file found.\n";
        return;
    }

    Transaction t;
    bool found = false;

    cout << "\n=============================================\n";
    cout << "ALL TRANSACTIONS\n";
    cout << "=============================================\n";

    while (file.read(reinterpret_cast<char*>(&t), sizeof(t)))
    {
        displayTransaction(t);
        found = true;
    }

    if (!found)
        cout << "No transactions available.\n";

    file.close();
}


// Main Menu


int main()
{
    int choice;



    do
    {
        cout << "\n\n===============BANKING TRANSACTION LEDGER MAIN MENU ===============\n";
        cout << "1. Add New Transaction\n";
        cout << "2. Search Transactions by Account Number\n";
        cout << "3. Display Complete Account History\n";
        cout << "4. Calculate Current Balance\n";
        cout << "5. Modify Transaction\n";
        cout << "6. Check File Integrity\n";
        cout << "7. Generate Monthly Report\n";
        cout << "8. Display All Transactions\n";
        cout << "0. Exit\n";
        cout << "==========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTransaction();
                break;

            case 2:
                searchTransactions();
                break;

            case 3:
                displayAccountHistory();
                break;

            case 4:
                showCurrentBalance();
                break;

            case 5:
                modifyTransaction();
                break;

            case 6:
                checkFileIntegrity();
                break;

            case 7:
                monthlyReport();
                break;

            case 8:
                displayAllTransactions();
                break;

            case 0:
                cout << "\nThank you for using Banking Transaction Ledger.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
