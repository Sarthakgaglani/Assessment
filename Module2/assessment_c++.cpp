#include <iostream>
#include <fstream>   // For file input/output operations
#include <ctime>     // For displaying current date and time
using namespace std;

// ATM class definition
class ATM {
private:
    int pin;                // Stores the user's PIN
    double balance;         // Stores account balance
    double depositAmount;   // Stores last deposited amount
    double withdrawAmount;  // Stores last withdrawn amount

public:
    // Constructor to initialize variables and load balance from file
    ATM() {
        pin = 12345;                // Default PIN
        depositAmount = 0;
        withdrawAmount = 0;
        loadBalance();              // Load existing balance from file (if exists)
    }

    // Function declarations
    void displayDateTime();
    void welcomeScreen();
    bool validatePIN();
    void mainMenu();
    void deposit();
    void withdraw();
    void checkBalance();
    void helpScreen();
    void saveBalance();
    void loadBalance();
};

// ---------------------- Function Definitions ----------------------

// Function to display the current date and time
void ATM::displayDateTime() {
    time_t now = time(0);      // Get current system time
    char* dt = ctime(&now);    // Convert to readable format
    cout << "Current date : " << dt;
}

// Displays the welcome screen and options
void ATM::welcomeScreen() {
    system("cls"); // Clears the console (works only on Windows)

    cout << "\n";
    cout << string(45, '=') << "\n";
    cout << "              WELCOME TO ATM              \n";
    cout << string(45, '=') << "\n";
    cout << "-------------------------------------------\n";
    displayDateTime();  // Show current date and time
    cout << "-------------------------------------------\n\n";

    cout << "Press 1 and Then Press Enter to Access Your Account Via Pin Number\n\n";
    cout << "or\n\n";
    cout << "Press 0 and Press Enter to Get Help.\n";
    cout << "\n-------------------------------------------\n";
}

// Validates the user-entered PIN
bool ATM::validatePIN() {
    int userPin;
    cout << "\nEnter your 5-digit ATM PIN: ";
    cin >> userPin;

    if (userPin == pin) {
        cout << "\nPIN Accepted Successfully!\n";
        return true;
    } else {
        cout << "\nIncorrect PIN! Exiting...\n";
        return false;
    }
}

// Main menu showing available ATM operations
void ATM::mainMenu() {
    int choice;
    do {
        cout << "\n=========== MAIN MENU ===========\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                deposit();        // Call deposit function
                break;
            case 2:
                withdraw();       // Call withdraw function
                break;
            case 3:
                checkBalance();   // Show current balance
                break;
            case 4:
                cout << "\nThank you for using our ATM!\n";
                saveBalance();    // Save balance before exiting
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);  // Repeat menu until user chooses Exit
}

// Function to deposit money into account
void ATM::deposit() {
    cout << "\nEnter amount to deposit: Rs. ";
    cin >> depositAmount;
    balance += depositAmount;  // Add deposit to balance
    cout << "Deposit Successful!\n";
    cout << "Current Balance: Rs. " << balance << endl;
    saveBalance(); // Save updated balance to file
}

// Function to withdraw money from account
void ATM::withdraw() {
    cout << "\nEnter amount to withdraw: Rs. ";
    cin >> withdrawAmount;

    // Check for sufficient balance
    if (withdrawAmount > balance) {
        cout << "\nInsufficient Balance! Withdrawal Failed.\n";
    } else {
        balance -= withdrawAmount;  // Deduct amount
        cout << "Withdrawal Successful!\n";
        cout << "Remaining Balance: Rs. " << balance << endl;
        saveBalance(); // Save updated balance to file
    }
}

// Function to display the current account balance
void ATM::checkBalance() {
    cout << "\nYour Current Account Balance is: Rs. " << balance << endl;
}

// Function to display help/instructions for the user
void ATM::helpScreen() {
    cout << "\n========= HELP SCREEN =========\n";
    cout << "1. Use PIN to access your account.\n";
    cout << "2. You can deposit or withdraw money safely.\n";
    cout << "3. Check balance anytime.\n";
    cout << "4. Always exit properly after use.\n";
    cout << "===============================\n";
}

// Function to save the balance into a text file
void ATM::saveBalance() {
    ofstream file("balance.txt");  // Open file for writing
    file << balance;               // Write balance value
    file.close();                  // Close file
}

// Function to load the balance from a text file
void ATM::loadBalance() {
    ifstream file("balance.txt");  // Open file for reading
    if (file) {
        file >> balance;           // If file exists, read balance
    } else {
        balance = 20000;           // Default balance if no file found
    }
    file.close();                  // Close file
}

// ---------------------- MAIN FUNCTION ----------------------

int main() {
    ATM atm;      // Create ATM object
    int choice;

    atm.welcomeScreen();  // Display welcome screen
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (atm.validatePIN()) {  // Validate PIN before showing menu
                atm.mainMenu();
            }
            break;
        case 0:
            atm.helpScreen();         // Display help information
            break;
        default:
            cout << "\nExiting ATM. Have a nice day!\n";
            atm.saveBalance();        // Save balance before exiting
            break;
    }

    return 0;
}
