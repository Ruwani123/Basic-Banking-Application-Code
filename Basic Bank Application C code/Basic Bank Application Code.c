
#include <stdio.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

// Array to hold bank accounts
struct BankAccount accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void transfer();

int main() {
    int choice;

    while (1) {
        printf("\nBanking Application\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Transfer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                transfer();
                break;
            case 6:
                printf("Exiting the application. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    if (totalAccounts == MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    struct BankAccount newAccount;
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);
    printf("Enter initial deposit amount: ");
    scanf("%f", &newAccount.balance);

    newAccount.accountNumber = totalAccounts + 1001; // Assuming account numbers start from 1001
    accounts[totalAccounts++] = newAccount;

    printf("Account created successfully. Account number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Invalid deposit amount. Please enter a positive value.\n");
            }
            return;
        }
    }

    printf("Account not found. Please check the account number and try again.\n");
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0) {
                if (amount <= accounts[i].balance) {
                    accounts[i].balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
                } else {
                    printf("Insufficient funds. Cannot withdraw.\n");
                }
            } else {
                printf("Invalid withdrawal amount. Please enter a positive value.\n");
            }
            return;
        }
    }

    printf("Account not found. Please check the account number and try again.\n");
}

void checkBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found. Please check the account number and try again.\n");
}

void transfer() {
    int sourceAccountNumber, destinationAccountNumber;
    float amount;
    printf("Enter source account number: ");
    scanf("%d", &sourceAccountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == sourceAccountNumber) {
            printf("Enter destination account number: ");
            scanf("%d", &destinationAccountNumber);

            for (int j = 0; j < totalAccounts; j++) {
                if (accounts[j].accountNumber == destinationAccountNumber) {
                    printf("Enter the amount to transfer: ");
                    scanf("%f", &amount);
                    if (amount > 0) {
                        if (amount <= accounts[i].balance) {
                            accounts[i].balance -= amount;
                            accounts[j].balance += amount;
                            printf("Transfer successful.\n");
                        } else {
                            printf("Insufficient funds. Cannot transfer.\n");
                        }
                    } else {
                        printf("Invalid transfer amount. Please enter a positive value.\n");
                    }
                    return;
                }
            }

            printf("Destination account not found. Please check the account number and try again.\n");
            return;
        }
    }

    printf("Source account not found. Please check the account number and try again.\n");
}
