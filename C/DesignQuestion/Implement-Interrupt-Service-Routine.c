/*
 * Implement Interrupt Service Routine (ISR) in C
 * 
 * This program demonstrates how to implement an Interrupt Service Routine (ISR) in C.
 * 
 * The program creates a worker thread that waits for a signal from the ISR to handle the interrupt.
 * The ISR is triggered by the SIGINT signal (Ctrl+C) and increments a counter to track the number of interrupts.
 * 
 * The worker thread waits for the signal from the ISR using a condition variable and mutex.
 * When the signal is received, the worker thread handles the interrupt (simulated by sleeping for 2 seconds).
 * 
 * The main thread simulates some work and then exits, but the worker thread continues to run indefinitely.
 * The program can be terminated by sending a SIGINT signal (Ctrl+C) to the process.
 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// Global variables
volatile int interrupt_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
volatile int interrupt_occurred = 0;

// Interrupt Service Routine (ISR)
void isr_sigint(int signum) {
    pthread_mutex_lock(&mutex);
    interrupt_count++;
    interrupt_occurred = 1;
    pthread_cond_signal(&cond); // Signal the worker thread
    pthread_mutex_unlock(&mutex);
    signal(SIGINT, isr_sigint); //re-register
}

// Worker thread function
void *worker_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (interrupt_occurred == 0) {
            pthread_cond_wait(&cond, &mutex); // Wait for signal
        }
        interrupt_occurred = 0; // Reset flag

        printf("Worker thread: Handling interrupt. Count: %d\n", interrupt_count);

        // Simulate interrupt handling (replace with actual work)
        sleep(2); // Simulate processing time

        pthread_mutex_unlock(&mutex);
    }
    return NULL; // Never reached in this example
}

int main() {
    pthread_t worker;

    // Register the ISR
    /*
     This declaration defines a function named signal that takes two parameters: 
     an int and a pointer to a function that takes an int and returns void. 
     The signal function returns a pointer to a function that takes an int and returns void.
    */
    if (signal(SIGINT, isr_sigint) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    // Create the worker thread
    if (pthread_create(&worker, NULL, worker_thread, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    printf("Program started. Press Ctrl+C to trigger interrupts.\n");
    printf("Main thread running.\n");

    // Simulate main program work
    for(int i = 0; i < 10; ++i){
        printf("Main thread: Working... %d\n", i);
        sleep(1);
    }

    //The worker thread runs infinitely, so the main thread will complete, but the program will not terminate unless forcibly terminated.
    printf("Main Thread Finished.\n");
    pthread_join(worker, NULL); //This will never return in this example.

    return 0;
}