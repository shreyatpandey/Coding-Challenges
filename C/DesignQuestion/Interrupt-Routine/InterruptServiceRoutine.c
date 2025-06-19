#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_INTERRUPTS 256

// Function pointer type for ISRs
typedef void (*ISR)(void);

// Interrupt Vector Table
ISR interruptVectorTable[MAX_INTERRUPTS];

// Function to register an ISR
void registerISR(int interruptNumber, ISR isr) {
    if (interruptNumber < 0 || interruptNumber >= MAX_INTERRUPTS) {
        fprintf(stderr, "Error: Invalid interrupt number\n");
        return;
    }
    interruptVectorTable[interruptNumber] = isr;
}

// Function to handle an interrupt
void handleInterrupt(int interruptNumber) {
    if (interruptNumber < 0 || interruptNumber >= MAX_INTERRUPTS || interruptVectorTable[interruptNumber] == NULL) {
        fprintf(stderr, "Error: No ISR registered for interrupt %d\n", interruptNumber);
        return;
    }
    interruptVectorTable[interruptNumber]();
}

// Example ISR
void exampleISR(void) {
    printf("Interrupt handled by exampleISR\n");
}

int main() {
    // Register example ISR for interrupt 5
    registerISR(5, exampleISR);

    // Simulate interrupt 5
    printf("Simulating interrupt 5\n");
    handleInterrupt(5);

    // Simulate an unregistered interrupt
    printf("Simulating interrupt 10\n");
    handleInterrupt(10);

    return 0;
}
