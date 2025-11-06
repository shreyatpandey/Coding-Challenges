#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "single_hw_timer.h"

// Example callback functions
void callback1(void) {
    printf("  >>> Callback 1 executed! <<<\n");
}

void callback2(void) {
    printf("  >>> Callback 2 executed! <<<\n");
}

void callback3(void) {
    printf("  >>> Callback 3 executed! <<<\n");
}

void callback4(void) {
    printf("  >>> Callback 4 executed! <<<\n");
}

void callback5(void) {
    printf("  >>> Callback 5 executed! <<<\n");
}

/**
 * Simulate hardware timer ticks
 * In a real embedded system, this would be called by a hardware interrupt
 */
void simulate_hw_timer_tick(int tick_number) {
    printf("\n========== Simulating HW Timer Tick #%d ==========\n", tick_number);
    HwTimerExpire();
}

/**
 * Test Case 1: Simple timer requests
 */
void test_case_1(void) {
    printf("\n\n");
    printf("================================================================\n");
    printf("TEST CASE 1: Simple Timer Requests\n");
    printf("================================================================\n");
    
    timer_system_init(10); // 10ms hardware timer period
    
    printf("\nRequesting timers:\n");
    printf("  - Timer 1: 50ms (5 ticks)\n");
    printf("  - Timer 2: 100ms (10 ticks)\n");
    printf("  - Timer 3: 30ms (3 ticks)\n");
    
    requestCallback(50, callback1);
    requestCallback(100, callback2);
    requestCallback(30, callback3);
    
    printf("\nActive timers: %d\n", get_active_timer_count());
    
    // Simulate 15 hardware timer ticks (150ms)
    for (int i = 1; i <= 15; i++) {
        simulate_hw_timer_tick(i);
        usleep(50000); // 50ms delay for visualization
    }
    
    printf("\nActive timers remaining: %d\n", get_active_timer_count());
    timer_system_cleanup();
}

/**
 * Test Case 2: Multiple timers with same expiry time
 */
void test_case_2(void) {
    printf("\n\n");
    printf("================================================================\n");
    printf("TEST CASE 2: Multiple Timers with Same Expiry Time\n");
    printf("================================================================\n");
    
    timer_system_init(10); // 10ms hardware timer period
    
    printf("\nRequesting timers:\n");
    printf("  - Timer 1: 50ms\n");
    printf("  - Timer 2: 50ms\n");
    printf("  - Timer 3: 50ms\n");
    
    requestCallback(50, callback1);
    requestCallback(50, callback2);
    requestCallback(50, callback3);
    
    printf("\nActive timers: %d\n", get_active_timer_count());
    
    // Simulate 10 hardware timer ticks
    for (int i = 1; i <= 10; i++) {
        simulate_hw_timer_tick(i);
        usleep(50000);
    }
    
    printf("\nActive timers remaining: %d\n", get_active_timer_count());
    timer_system_cleanup();
}

/**
 * Test Case 3: Timers requested at different times
 */
void test_case_3(void) {
    printf("\n\n");
    printf("================================================================\n");
    printf("TEST CASE 3: Timers Requested at Different Times\n");
    printf("================================================================\n");
    
    timer_system_init(10); // 10ms hardware timer period
    
    printf("\nRequesting Timer 1: 100ms\n");
    requestCallback(100, callback1);
    
    // Simulate 5 ticks (50ms)
    for (int i = 1; i <= 5; i++) {
        simulate_hw_timer_tick(i);
        usleep(30000);
    }
    
    printf("\nRequesting Timer 2: 30ms (should fire before Timer 1)\n");
    requestCallback(30, callback2);
    
    printf("\nRequesting Timer 3: 20ms\n");
    requestCallback(20, callback3);
    
    // Simulate 10 more ticks
    for (int i = 6; i <= 15; i++) {
        simulate_hw_timer_tick(i);
        usleep(30000);
    }
    
    timer_system_cleanup();
}

/**
 * Test Case 4: Edge cases
 */
void test_case_4(void) {
    printf("\n\n");
    printf("================================================================\n");
    printf("TEST CASE 4: Edge Cases\n");
    printf("================================================================\n");
    
    timer_system_init(10);
    
    printf("\nTest 4.1: Very short interval (5ms - less than 1 tick)\n");
    requestCallback(5, callback1);
    
    simulate_hw_timer_tick(1);
    simulate_hw_timer_tick(2);
    
    printf("\nTest 4.2: NULL callback (should fail)\n");
    int result = requestCallback(100, NULL);
    printf("Result: %d (expected -1)\n", result);
    
    printf("\nTest 4.3: Zero interval (should fail)\n");
    result = requestCallback(0, callback2);
    printf("Result: %d (expected -1)\n", result);
    
    timer_system_cleanup();
}

/**
 * Test Case 5: Large number of timers
 */
void test_case_5(void) {
    printf("\n\n");
    printf("================================================================\n");
    printf("TEST CASE 5: Multiple Timers with Different Intervals\n");
    printf("================================================================\n");
    
    timer_system_init(10);
    
    printf("\nRequesting 5 timers:\n");
    requestCallback(20, callback1);   // 2 ticks
    requestCallback(40, callback2);   // 4 ticks
    requestCallback(60, callback3);   // 6 ticks
    requestCallback(80, callback4);   // 8 ticks
    requestCallback(100, callback5);  // 10 ticks
    
    printf("Active timers: %d\n", get_active_timer_count());
    
    // Simulate 12 ticks
    for (int i = 1; i <= 12; i++) {
        simulate_hw_timer_tick(i);
        usleep(50000);
    }
    
    printf("\nActive timers remaining: %d\n", get_active_timer_count());
    timer_system_cleanup();
}

/**
 * Main function
 */
int main(void) {
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║     Single Hardware Timer Implementation - Test Suite         ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    
    // Run all test cases
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    
    printf("\n\n");
    printf("================================================================\n");
    printf("All tests completed!\n");
    printf("================================================================\n");
    
    return 0;
}
