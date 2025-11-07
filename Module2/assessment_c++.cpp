#include <iostream>
#include <fstream>   // for file handling
#include <ctime>
using namespace std;

class ATM {
	private:
    	int pin;
    	double balance;
    	double depositAmount;
    	double withdrawAmount;

	public:
    	ATM() {
        	pin = 12345;
        	depositAmount = 0;
        	withdrawAmount = 0;
        	loadBalance();   // load previous balance from file
    	}

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

void ATM::displayDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Current date : " << dt;
}

void ATM::welcomeScreen() {
    system("cls"); // clear console (works in Windows)

    cout << "\n";
    cout << string(45, '=') << "\n";
    cout << "              WELCOME TO ATM              \n";
    cout << string(45, '=') << "\n";
    cout << "-------------------------------------------\n";
    displayDateTime();
    cout << "-------------------------------------------\n\n";

    cout << "Press 1 and Then Press Enter to Access Your Account Via Pin Number\n\n";
    cout << "or\n\n";
    cout << "Press 0 and Press Enter to Get Help.\n";
    cout << "\n-------------------------------------------\n";
}

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
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                cout << "\nThank you for using our ATM!\n";
                saveBalance();  // save before exit
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

void ATM::deposit() {
    cout << "\nEnter amount to deposit: Rs. ";
    cin >> depositAmount;
    balance += depositAmount;
    cout << "Deposit Successful!\n";
    cout << "Current Balance: Rs. " << balance << endl;
    saveBalance(); // save after deposit
}

void ATM::withdraw() {
    cout << "\nEnter amount to withdraw: Rs. ";
    cin >> withdrawAmount;

    if (withdrawAmount > balance) {
        cout << "\nInsufficient Balance! Withdrawal Failed.\n";
    } else {
        balance -= withdrawAmount;
        cout << "Withdrawal Successful!\n";
        cout << "Remaining Balance: Rs. " << balance << endl;
        saveBalance(); // save after withdrawal
    }
}

void ATM::checkBalance() {
    cout << "\nYour Current Account Balance is: Rs. " << balance << endl;
}

// Pin is 12345
void ATM::helpScreen() {
    cout << "\n========= HELP SCREEN =========\n";
    cout << "1. Use PIN to access your account.\n";
    cout << "2. You can deposit or withdraw money safely.\n";
    cout << "3. Check balance anytime.\n";
    cout << "4. Always exit properly after use.\n";
    cout << "===============================\n";
}

// Save balance to file
void ATM::saveBalance() {
    ofstream file("balance.txt");
    file << balance;
    file.close();
}

// Load balance from file
void ATM::loadBalance() {
    ifstream file("balance.txt");
    if (file) {
        file >> balance;
    } else {
        balance = 20000; // default if file not found
    }
    file.close();
}

int main() {
    ATM atm;
    int choice;

    atm.welcomeScreen();
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (atm.validatePIN()) {
                atm.mainMenu();
            }
            break;
        case 0:
            atm.helpScreen();
            break;
        default:
            cout << "\nExiting ATM. Have a nice day!\n";
            atm.saveBalance();
            break;
    }

    return 0;
}

