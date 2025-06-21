/*
 * Program: Multiply 16-bit integers using 8-bit multiplier
 * 
 * Description: This program demonstrates how to multiply two 16-bit integers
 * using only 8-bit multiplication operations. This is useful in embedded systems
 * or processors that only have 8-bit multipliers.
 * 
 * Algorithm:
 * To multiply two 16-bit numbers A and B:
 * A = A_high * 256 + A_low (where A_high and A_low are 8-bit values)
 * B = B_high * 256 + B_low (where B_high and B_low are 8-bit values)
 * 
 * A * B = (A_high * 256 + A_low) * (B_high * 256 + B_low)
 *       = A_high * B_high * 256^2 + A_high * B_low * 256 + A_low * B_high * 256 + A_low * B_low
 *       = A_high * B_high * 65536 + (A_high * B_low + A_low * B_high) * 256 + A_low * B_low
 */

#include <stdio.h>
#include <stdint.h>

// Function to simulate 8-bit multiplication (returns 16-bit result)
uint16_t multiply_8bit(uint8_t a, uint8_t b) {
    return (uint16_t)a * (uint16_t)b;
}

// Function to multiply two 16-bit numbers using only 8-bit multiplications
uint32_t multiply_16bit_using_8bit(uint16_t a, uint16_t b) {
    // Extract high and low bytes of first number
    uint8_t a_high = (a >> 8) & 0xFF;  // Upper 8 bits
    uint8_t a_low = a & 0xFF;          // Lower 8 bits
    
    // Extract high and low bytes of second number
    uint8_t b_high = (b >> 8) & 0xFF;  // Upper 8 bits
    uint8_t b_low = b & 0xFF;          // Lower 8 bits
    
    // Perform four 8-bit multiplications
    uint16_t p1 = multiply_8bit(a_high, b_high);  // High * High
    uint16_t p2 = multiply_8bit(a_high, b_low);   // High * Low
    uint16_t p3 = multiply_8bit(a_low, b_high);   // Low * High
    uint16_t p4 = multiply_8bit(a_low, b_low);    // Low * Low
    
    // Combine results according to the formula:
    // Result = p1 * 65536 + (p2 + p3) * 256 + p4
    uint32_t result = ((uint32_t)p1 << 16) + (((uint32_t)p2 + (uint32_t)p3) << 8) + (uint32_t)p4;
    
    return result;
}

// Function to display the breakdown of multiplication
void display_multiplication_breakdown(uint16_t a, uint16_t b) {
    uint8_t a_high = (a >> 8) & 0xFF;
    uint8_t a_low = a & 0xFF;
    uint8_t b_high = (b >> 8) & 0xFF;
    uint8_t b_low = b & 0xFF;
    
    uint16_t p1 = multiply_8bit(a_high, b_high);
    uint16_t p2 = multiply_8bit(a_high, b_low);
    uint16_t p3 = multiply_8bit(a_low, b_high);
    uint16_t p4 = multiply_8bit(a_low, b_low);
    
    printf("\nMultiplication Breakdown:\n");
    printf("A = %u (0x%04X) = %u * 256 + %u\n", a, a, a_high, a_low);
    printf("B = %u (0x%04X) = %u * 256 + %u\n", b, b, b_high, b_low);
    printf("\nFour 8-bit multiplications:\n");
    printf("P1 = A_high * B_high = %u * %u = %u (0x%04X)\n", a_high, b_high, p1, p1);
    printf("P2 = A_high * B_low  = %u * %u = %u (0x%04X)\n", a_high, b_low, p2, p2);
    printf("P3 = A_low  * B_high = %u * %u = %u (0x%04X)\n", a_low, b_high, p3, p3);
    printf("P4 = A_low  * B_low  = %u * %u = %u (0x%04X)\n", a_low, b_low, p4, p4);
    
    uint32_t term1 = (uint32_t)p1 << 16;
    uint32_t term2 = ((uint32_t)p2 + (uint32_t)p3) << 8;
    uint32_t term3 = (uint32_t)p4;
    
    printf("\nCombining results:\n");
    printf("Term1 = P1 * 65536 = %u * 65536 = %u (0x%08X)\n", p1, term1, term1);
    printf("Term2 = (P2 + P3) * 256 = (%u + %u) * 256 = %u * 256 = %u (0x%08X)\n", 
           p2, p3, p2 + p3, term2, term2);
    printf("Term3 = P4 = %u (0x%08X)\n", term3, term3);
    printf("Final Result = Term1 + Term2 + Term3 = %u + %u + %u = %u (0x%08X)\n",
           term1, term2, term3, term1 + term2 + term3, term1 + term2 + term3);
}

// Function to test the implementation
void test_multiplication() {
    struct {
        uint16_t a, b;
        uint32_t expected;
    } test_cases[] = {
        {0, 0, 0},
        {1, 1, 1},
        {255, 255, 65025},
        {256, 256, 65536},
        {1000, 2000, 2000000},
        {65535, 2, 131070},
        {65535, 65535, 4294836225UL}
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int passed = 0;
    
    printf("Running test cases:\n");
    printf("====================\n");
    
    for (int i = 0; i < num_tests; i++) {
        uint32_t result = multiply_16bit_using_8bit(test_cases[i].a, test_cases[i].b);
        uint32_t expected = test_cases[i].expected;
        
        printf("Test %d: %u * %u = %u ", i + 1, test_cases[i].a, test_cases[i].b, result);
        
        if (result == expected) {
            printf("✓ PASS\n");
            passed++;
        } else {
            printf("✗ FAIL (expected %u)\n", expected);
        }
    }
    
    printf("\nTest Results: %d/%d passed\n", passed, num_tests);
}

int main() {
    printf("16-bit Integer Multiplication Using 8-bit Multiplier\n");
    printf("====================================================\n");
    test_multiplication();
    return 0;
}
