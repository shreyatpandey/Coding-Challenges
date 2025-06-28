#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Bank State Machine Implementation

// Define Bank States
typedef enum {
    STATE_INITIAL,          // Initial state when system starts
    STATE_MAIN_MENU,        // Main menu state
    STATE_LOGIN,            // User login state
    STATE_AUTHENTICATED,    // User successfully logged in
    STATE_ACCOUNT_MENU,     // Account operations menu
    STATE_DEPOSIT,          // Deposit money state
    STATE_WITHDRAW,         // Withdraw money state
    STATE_BALANCE_INQUIRY,  // Check balance state
    STATE_TRANSFER,         // Transfer money state
    STATE_CREATE_ACCOUNT,   // Create new account state
    STATE_EXIT,             // Exit state
    STATE_ERROR             // Error state
} BankState;

// Define Events that trigger state transitions
typedef enum {
    EVENT_START,
    EVENT_LOGIN_REQUEST,
    EVENT_LOGIN_SUCCESS,
    EVENT_LOGIN_FAILURE,
    EVENT_DEPOSIT_REQUEST,
    EVENT_WITHDRAW_REQUEST,
    EVENT_BALANCE_REQUEST,
    EVENT_TRANSFER_REQUEST,
    EVENT_CREATE_ACCOUNT_REQUEST,
    EVENT_TRANSACTION_COMPLETE,
    EVENT_LOGOUT,
    EVENT_EXIT_REQUEST,
    EVENT_BACK_TO_MENU,
    EVENT_ERROR_OCCURRED
} BankEvent;

// Account structure
typedef struct {
    int account_number;
    char name[50];
    char pin[5];
    double balance;
    bool is_active;
} Account;

// Bank System structure
typedef struct {
    BankState current_state;
    Account accounts[100];  // Maximum 100 accounts
    int total_accounts;
    int current_user_index;
    char temp_pin[5];
    int temp_account_number;
    double temp_amount;
} BankSystem;

// Function prototypes
void initialize_bank_system(BankSystem* bank);
void print_current_state(BankState state);
BankState handle_event(BankSystem* bank, BankEvent event);
void display_main_menu(void);
void display_account_menu(void);
bool authenticate_user(BankSystem* bank, int account_number, const char* pin);
void create_account(BankSystem* bank);
void deposit_money(BankSystem* bank);
void withdraw_money(BankSystem* bank);
void check_balance(BankSystem* bank);
void transfer_money(BankSystem* bank);
void run_bank_system(BankSystem* bank);

// Initialize the bank system
void initialize_bank_system(BankSystem* bank) {
    bank->current_state = STATE_INITIAL;
    bank->total_accounts = 0;
    bank->current_user_index = -1;
    
    // Initialize with some sample accounts for testing
    strcpy(bank->accounts[0].name, "John Doe");
    bank->accounts[0].account_number = 1001;
    strcpy(bank->accounts[0].pin, "1234");
    bank->accounts[0].balance = 5000.0;
    bank->accounts[0].is_active = true;
    
    strcpy(bank->accounts[1].name, "Jane Smith");
    bank->accounts[1].account_number = 1002;
    strcpy(bank->accounts[1].pin, "5678");
    bank->accounts[1].balance = 3000.0;
    bank->accounts[1].is_active = true;
    
    bank->total_accounts = 2;
    
    printf("Bank System Initialized Successfully!\n");
    printf("Sample Accounts:\n");
    printf("Account 1001 - John Doe (PIN: 1234) - Balance: $5000.00\n");
    printf("Account 1002 - Jane Smith (PIN: 5678) - Balance: $3000.00\n\n");
}

// Print current state for debugging
void print_current_state(BankState state) {
    const char* state_names[] = {
        "INITIAL", "MAIN_MENU", "LOGIN", "AUTHENTICATED", "ACCOUNT_MENU",
        "DEPOSIT", "WITHDRAW", "BALANCE_INQUIRY", "TRANSFER", "CREATE_ACCOUNT",
        "EXIT", "ERROR"
    };
    printf("[DEBUG] Current State: %s\n", state_names[state]);
}

// State transition handler
BankState handle_event(BankSystem* bank, BankEvent event) {
    BankState next_state = bank->current_state;
    
    switch (bank->current_state) {
        case STATE_INITIAL:
            if (event == EVENT_START) {
                next_state = STATE_MAIN_MENU;
            }
            break;
            
        case STATE_MAIN_MENU:
            switch (event) {
                case EVENT_LOGIN_REQUEST:
                    next_state = STATE_LOGIN;
                    break;
                case EVENT_CREATE_ACCOUNT_REQUEST:
                    next_state = STATE_CREATE_ACCOUNT;
                    break;
                case EVENT_EXIT_REQUEST:
                    next_state = STATE_EXIT;
                    break;
                default:
                    next_state = STATE_ERROR;
                    break;
            }
            break;
            
        case STATE_LOGIN:
            switch (event) {
                case EVENT_LOGIN_SUCCESS:
                    next_state = STATE_AUTHENTICATED;
                    break;
                case EVENT_LOGIN_FAILURE:
                    next_state = STATE_MAIN_MENU;
                    break;
                case EVENT_BACK_TO_MENU:
                    next_state = STATE_MAIN_MENU;
                    break;
                default:
                    next_state = STATE_ERROR;
                    break;
            }
            break;
            
        case STATE_AUTHENTICATED:
            if (event == EVENT_LOGIN_SUCCESS) {
                next_state = STATE_ACCOUNT_MENU;
            }
            break;
            
        case STATE_ACCOUNT_MENU:
            switch (event) {
                case EVENT_DEPOSIT_REQUEST:
                    next_state = STATE_DEPOSIT;
                    break;
                case EVENT_WITHDRAW_REQUEST:
                    next_state = STATE_WITHDRAW;
                    break;
                case EVENT_BALANCE_REQUEST:
                    next_state = STATE_BALANCE_INQUIRY;
                    break;
                case EVENT_TRANSFER_REQUEST:
                    next_state = STATE_TRANSFER;
                    break;
                case EVENT_LOGOUT:
                    next_state = STATE_MAIN_MENU;
                    break;
                default:
                    next_state = STATE_ERROR;
                    break;
            }
            break;
            
        case STATE_DEPOSIT:
        case STATE_WITHDRAW:
        case STATE_BALANCE_INQUIRY:
        case STATE_TRANSFER:
            switch (event) {
                case EVENT_TRANSACTION_COMPLETE:
                    next_state = STATE_ACCOUNT_MENU;
                    break;
                case EVENT_BACK_TO_MENU:
                    next_state = STATE_ACCOUNT_MENU;
                    break;
                default:
                    next_state = STATE_ERROR;
                    break;
            }
            break;
            
        case STATE_CREATE_ACCOUNT:
            switch (event) {
                case EVENT_TRANSACTION_COMPLETE:
                    next_state = STATE_MAIN_MENU;
                    break;
                case EVENT_BACK_TO_MENU:
                    next_state = STATE_MAIN_MENU;
                    break;
                default:
                    next_state = STATE_ERROR;
                    break;
            }
            break;
            
        case STATE_ERROR:
            if (event == EVENT_BACK_TO_MENU) {
                next_state = STATE_MAIN_MENU;
            }
            break;
            
        case STATE_EXIT:
            // Terminal state - no transitions
            break;
    }
    
    return next_state;
}

// Display main menu
void display_main_menu(void) {
    printf("\n=== BANK MANAGEMENT SYSTEM ===\n");
    printf("1. Login to Account\n");
    printf("2. Create New Account\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Display account menu
void display_account_menu(void) {
    printf("\n=== ACCOUNT MENU ===\n");
    printf("1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Check Balance\n");
    printf("4. Transfer Money\n");
    printf("5. Logout\n");
    printf("Choose an option: ");
}

// Authenticate user
bool authenticate_user(BankSystem* bank, int account_number, const char* pin) {
    for (int i = 0; i < bank->total_accounts; i++) {
        if (bank->accounts[i].account_number == account_number &&
            strcmp(bank->accounts[i].pin, pin) == 0 &&
            bank->accounts[i].is_active) {
            bank->current_user_index = i;
            return true;
        }
    }
    return false;
}

// Create new account
void create_account(BankSystem* bank) {
    if (bank->total_accounts >= 100) {
        printf("Error: Maximum number of accounts reached!\n");
        return;
    }
    
    Account* new_account = &bank->accounts[bank->total_accounts];
    
    printf("\n=== CREATE NEW ACCOUNT ===\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", new_account->name);
    
    printf("Enter initial deposit amount: $");
    scanf("%lf", &new_account->balance);
    
    if (new_account->balance < 100.0) {
        printf("Error: Minimum initial deposit is $100.00\n");
        return;
    }
    
    printf("Create a 4-digit PIN: ");
    scanf("%s", new_account->pin);
    
    if (strlen(new_account->pin) != 4) {
        printf("Error: PIN must be exactly 4 digits!\n");
        return;
    }
    
    // Generate account number
    new_account->account_number = 1001 + bank->total_accounts;
    new_account->is_active = true;
    
    bank->total_accounts++;
    
    printf("\nAccount created successfully!\n");
    printf("Your account number is: %d\n", new_account->account_number);
    printf("Please remember your PIN: %s\n", new_account->pin);
}

// Deposit money
void deposit_money(BankSystem* bank) {
    printf("\n=== DEPOSIT MONEY ===\n");
    printf("Current Balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
    printf("Enter deposit amount: $");
    scanf("%lf", &bank->temp_amount);
    
    if (bank->temp_amount <= 0) {
        printf("Error: Invalid deposit amount!\n");
        return;
    }
    
    bank->accounts[bank->current_user_index].balance += bank->temp_amount;
    printf("Deposit successful!\n");
    printf("New Balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
}

// Withdraw money
void withdraw_money(BankSystem* bank) {
    printf("\n=== WITHDRAW MONEY ===\n");
    printf("Current Balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
    printf("Enter withdrawal amount: $");
    scanf("%lf", &bank->temp_amount);
    
    if (bank->temp_amount <= 0) {
        printf("Error: Invalid withdrawal amount!\n");
        return;
    }
    
    if (bank->temp_amount > bank->accounts[bank->current_user_index].balance) {
        printf("Error: Insufficient funds!\n");
        return;
    }
    
    bank->accounts[bank->current_user_index].balance -= bank->temp_amount;
    printf("Withdrawal successful!\n");
    printf("New Balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
}

// Check balance
void check_balance(BankSystem* bank) {
    printf("\n=== BALANCE INQUIRY ===\n");
    printf("Account Holder: %s\n", bank->accounts[bank->current_user_index].name);
    printf("Account Number: %d\n", bank->accounts[bank->current_user_index].account_number);
    printf("Current Balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
}

// Transfer money
void transfer_money(BankSystem* bank) {
    printf("\n=== TRANSFER MONEY ===\n");
    printf("Current Balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
    printf("Enter recipient account number: ");
    scanf("%d", &bank->temp_account_number);
    
    // Find recipient account
    int recipient_index = -1;
    for (int i = 0; i < bank->total_accounts; i++) {
        if (bank->accounts[i].account_number == bank->temp_account_number &&
            bank->accounts[i].is_active) {
            recipient_index = i;
            break;
        }
    }
    
    if (recipient_index == -1) {
        printf("Error: Recipient account not found!\n");
        return;
    }
    
    if (recipient_index == bank->current_user_index) {
        printf("Error: Cannot transfer to your own account!\n");
        return;
    }
    
    printf("Recipient: %s\n", bank->accounts[recipient_index].name);
    printf("Enter transfer amount: $");
    scanf("%lf", &bank->temp_amount);
    
    if (bank->temp_amount <= 0) {
        printf("Error: Invalid transfer amount!\n");
        return;
    }
    
    if (bank->temp_amount > bank->accounts[bank->current_user_index].balance) {
        printf("Error: Insufficient funds!\n");
        return;
    }
    
    // Perform transfer
    bank->accounts[bank->current_user_index].balance -= bank->temp_amount;
    bank->accounts[recipient_index].balance += bank->temp_amount;
    
    printf("Transfer successful!\n");
    printf("Transferred $%.2f to %s\n", bank->temp_amount, bank->accounts[recipient_index].name);
    printf("Your new balance: $%.2f\n", bank->accounts[bank->current_user_index].balance);
}

// Main bank system execution
void run_bank_system(BankSystem* bank) {
    int choice;
    BankEvent event;
    
    // Start the system
    bank->current_state = handle_event(bank, EVENT_START);
    
    while (bank->current_state != STATE_EXIT) {
        print_current_state(bank->current_state);
        
        switch (bank->current_state) {
            case STATE_MAIN_MENU:
                display_main_menu();
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        event = EVENT_LOGIN_REQUEST;
                        break;
                    case 2:
                        event = EVENT_CREATE_ACCOUNT_REQUEST;
                        break;
                    case 3:
                        event = EVENT_EXIT_REQUEST;
                        break;
                    default:
                        printf("Invalid option!\n");
                        continue;
                }
                break;
                
            case STATE_LOGIN:
                printf("\n=== LOGIN ===\n");
                printf("Enter account number: ");
                scanf("%d", &bank->temp_account_number);
                printf("Enter PIN: ");
                scanf("%s", bank->temp_pin);
                
                if (authenticate_user(bank, bank->temp_account_number, bank->temp_pin)) {
                    printf("Login successful! Welcome, %s\n", 
                           bank->accounts[bank->current_user_index].name);
                    event = EVENT_LOGIN_SUCCESS;
                } else {
                    printf("Invalid account number or PIN!\n");
                    event = EVENT_LOGIN_FAILURE;
                }
                break;
                
            case STATE_AUTHENTICATED:
                event = EVENT_LOGIN_SUCCESS;
                break;
                
            case STATE_ACCOUNT_MENU:
                display_account_menu();
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        event = EVENT_DEPOSIT_REQUEST;
                        break;
                    case 2:
                        event = EVENT_WITHDRAW_REQUEST;
                        break;
                    case 3:
                        event = EVENT_BALANCE_REQUEST;
                        break;
                    case 4:
                        event = EVENT_TRANSFER_REQUEST;
                        break;
                    case 5:
                        bank->current_user_index = -1;
                        event = EVENT_LOGOUT;
                        break;
                    default:
                        printf("Invalid option!\n");
                        continue;
                }
                break;
                
            case STATE_DEPOSIT:
                deposit_money(bank);
                event = EVENT_TRANSACTION_COMPLETE;
                break;
                
            case STATE_WITHDRAW:
                withdraw_money(bank);
                event = EVENT_TRANSACTION_COMPLETE;
                break;
                
            case STATE_BALANCE_INQUIRY:
                check_balance(bank);
                event = EVENT_TRANSACTION_COMPLETE;
                break;
                
            case STATE_TRANSFER:
                transfer_money(bank);
                event = EVENT_TRANSACTION_COMPLETE;
                break;
                
            case STATE_CREATE_ACCOUNT:
                create_account(bank);
                event = EVENT_TRANSACTION_COMPLETE;
                break;
                
            case STATE_ERROR:
                printf("An error occurred! Returning to main menu...\n");
                event = EVENT_BACK_TO_MENU;
                break;
                
            default:
                printf("Unknown state! Exiting...\n");
                bank->current_state = STATE_EXIT;
                continue;
        }
        
        // Transition to next state
        bank->current_state = handle_event(bank, event);
    }
    
    printf("\nThank you for using our Bank Management System!\n");
    printf("Goodbye!\n");
}

// Main function
int main() {
    BankSystem bank;
    
    printf("=== BANK STATE MACHINE DEMO ===\n\n");
    
    // Initialize the bank system
    initialize_bank_system(&bank);
    
    // Run the bank system
    run_bank_system(&bank);
    
    return 0;
}
