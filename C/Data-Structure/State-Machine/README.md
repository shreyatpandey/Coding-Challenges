# Bank State Machine Implementation in C

This project implements a comprehensive Bank Management System using a State Machine design pattern in C.

## Overview

The Bank State Machine manages different states of a banking system and handles transitions between them based on user events. This implementation demonstrates proper state management, event handling, and modular programming in C.

## Features

### States Implemented
- **STATE_INITIAL**: System startup state
- **STATE_MAIN_MENU**: Main menu display
- **STATE_LOGIN**: User authentication
- **STATE_AUTHENTICATED**: Successful login transition
- **STATE_ACCOUNT_MENU**: Account operations menu
- **STATE_DEPOSIT**: Money deposit operations
- **STATE_WITHDRAW**: Money withdrawal operations
- **STATE_BALANCE_INQUIRY**: Balance checking
- **STATE_TRANSFER**: Money transfer between accounts
- **STATE_CREATE_ACCOUNT**: New account creation
- **STATE_EXIT**: System shutdown
- **STATE_ERROR**: Error handling state

### Banking Operations
1. **Account Management**
   - Create new accounts with validation
   - Secure PIN-based authentication
   - Account number generation

2. **Financial Transactions**
   - Deposit money with validation
   - Withdraw money with insufficient funds checking
   - Transfer money between accounts
   - Balance inquiry

3. **Security Features**
   - PIN-based authentication
   - Account activation status
   - Input validation for all operations

## State Transition Diagram

```
[INITIAL] --start--> [MAIN_MENU]
                         |
                    +---------+----------+
                    |         |          |
                [LOGIN]  [CREATE_ACC]  [EXIT]
                    |         |
              +-----+-----+   |
              |           |   |
        [AUTHENTICATED] [MAIN_MENU]
              |
        [ACCOUNT_MENU]
              |
    +---------+---------+---------+
    |         |         |         |
[DEPOSIT] [WITHDRAW] [BALANCE] [TRANSFER]
    |         |         |         |
    +---------+---------+---------+
              |
        [ACCOUNT_MENU]
```

## Code Structure

### Data Structures
- **BankState**: Enumeration defining all possible states
- **BankEvent**: Enumeration defining all possible events
- **Account**: Structure representing a bank account
- **BankSystem**: Main system structure containing state and account data

### Key Functions
- `initialize_bank_system()`: Sets up initial system state and sample accounts
- `handle_event()`: Core state transition logic
- `authenticate_user()`: User login validation
- `create_account()`: New account creation with validation
- Banking operation functions: `deposit_money()`, `withdraw_money()`, etc.
- `run_bank_system()`: Main execution loop

## Sample Accounts

The system comes pre-loaded with test accounts:
- **Account 1001**: John Doe (PIN: 1234) - Balance: $5000.00
- **Account 1002**: Jane Smith (PIN: 5678) - Balance: $3000.00

## Compilation and Execution

```bash
# Compile the program
gcc -o bank_state_machine bank_state_machine.c

# Run the program
./bank_state_machine
```

## Usage Example

1. **Login Process**:
   - Choose option 1 from main menu
   - Enter account number (e.g., 1001)
   - Enter PIN (e.g., 1234)

2. **Perform Transactions**:
   - Choose from deposit, withdraw, balance inquiry, or transfer
   - Follow the prompts for each operation

3. **Create New Account**:
   - Choose option 2 from main menu
   - Provide name, initial deposit (minimum $100), and 4-digit PIN
   - System generates unique account number

## Validation and Error Handling

- **PIN Validation**: Must be exactly 4 digits
- **Amount Validation**: Positive amounts only
- **Insufficient Funds**: Prevents overdrafts
- **Account Existence**: Validates account numbers for transfers
- **Minimum Deposit**: $100 minimum for new accounts
- **Self-Transfer Prevention**: Cannot transfer to own account

## State Machine Benefits

1. **Clear Control Flow**: Easy to understand system behavior
2. **Maintainable Code**: States and transitions are explicit
3. **Error Handling**: Dedicated error state for anomalies
4. **Extensible**: Easy to add new states and transitions
5. **Debugging**: Current state is always known and displayed

## Potential Enhancements

1. **Persistent Storage**: Save account data to files
2. **Transaction History**: Log all operations
3. **Multiple User Sessions**: Support concurrent users
4. **Enhanced Security**: Encryption, session timeouts
5. **Administrative Features**: Account management, reporting
6. **GUI Interface**: Graphical user interface
7. **Network Support**: Client-server architecture

## Learning Outcomes

This implementation demonstrates:
- State Machine design pattern
- Event-driven programming
- Modular C programming
- Input validation and error handling
- Banking system logic
- Memory management
- Structured programming principles

The code serves as an excellent example for understanding how complex systems can be managed through well-defined states and transitions, making it easier to reason about system behavior and maintain the codebase.
