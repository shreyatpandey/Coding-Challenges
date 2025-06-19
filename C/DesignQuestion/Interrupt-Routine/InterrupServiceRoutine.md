An Interrupt Service Routine (ISR) mechanism in C typically involves handling hardware or software interrupts. Here's a basic design:

Interrupt Vector Table: A table that maps interrupt numbers to their corresponding ISR functions.
ISR Registration: A mechanism to register ISRs dynamically.
ISR Execution: A dispatcher that invokes the appropriate ISR based on the interrupt number.